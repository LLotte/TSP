#include <vector> 
#include <iostream> 
#include <assert.h>
#include <ctime>
#include <algorithm>
#include "CityMapFunctions.h"
#include "Genetic.h"
#define NR_OF_ORGANISMS 100
#define NR_OF_REPRODUCTIONS 20 
#define NR_OF_GENES 4

struct OrganismData
{
    int length;
    int index;
    bool operator < (const OrganismData& rhs) const 
    {
        return length < rhs.length;
    }
};

struct GenesData
{
    int city;
    int position;
};

OrganismData OrgData[NR_OF_ORGANISMS];
GenesData GnsData[NR_OF_GENES];
OrganismData RepData[NR_OF_ORGANISMS + NR_OF_REPRODUCTIONS];
std::vector<unsigned int> currentPaths[NR_OF_ORGANISMS];
std::vector<unsigned int> reproductionPaths[NR_OF_ORGANISMS + NR_OF_REPRODUCTIONS];

void reproduce(int nrRandomParents)
{
    unsigned int p1 = INT_MAX;
    unsigned int p2 = INT_MAX;
    std::vector<unsigned int> tempPaths[NR_OF_ORGANISMS];

    for (unsigned int k = NR_OF_ORGANISMS; k < NR_OF_ORGANISMS + NR_OF_REPRODUCTIONS; k++)
    {
        for (unsigned int i = 0; i < NR_OF_ORGANISMS; i++)
        {
            tempPaths[i] = currentPaths[i];
        }

        for (unsigned int i = 0; i < nrRandomParents; i++)
        {
            int j = rand() % (NR_OF_ORGANISMS);
            if (j < p1)
                p1 = j;
            else if (j < p2)
                p2 = j;
        }
        int u1 = OrgData[p1].index;
        int u2 = OrgData[p2].index;
        unsigned int randomPosition = rand() % (GetNrOfCities() - 1) + 1;

        for (unsigned int i = 0; i < 1000; i++)
        {
            if (randomPosition + NR_OF_GENES < GetNrOfCities() - 1)
                i = 1000;
            else if (randomPosition + NR_OF_GENES > GetNrOfCities() - 1)
                randomPosition = rand() % (GetNrOfCities() - 1) + 1;
        }
        
        for (unsigned int i = 0; i < NR_OF_GENES; i++)
        {
            if (randomPosition + i < GetNrOfCities() - 1)
            {
                GnsData[i].position = randomPosition + i;
                GnsData[i].city = tempPaths[u1][randomPosition + i];
            } 
        }

        unsigned int j = 0;
        for (unsigned int i = 0; i < GetNrOfCities() - 1; i++)
        {
            if (tempPaths[u2][i] == GnsData[j].city)
            {
                tempPaths[u2].erase(tempPaths[u2].begin() + i);
                i = -1;
                j++;
                if (j == NR_OF_GENES)
                    i = GetNrOfCities();
            }
        }

        for (unsigned int i = 0; i < NR_OF_GENES; i++)
        {
            tempPaths[u2].insert(tempPaths[u2].begin() + GnsData[i].position, GnsData[i].city);
        }

        tempPaths[u2][GetNrOfCities()] = tempPaths[u2][0];
        reproductionPaths[k] = tempPaths[u2];
    }
}

void swap(int index, int nrOfSwaps)
{
    int u = OrgData[index].index;
    for (int i = 0; i < nrOfSwaps; ++i)
    {
        int i1 = rand() % (GetNrOfCities() - 1);
        int i2 = rand() % (GetNrOfCities() - 1);

        int temp = reproductionPaths[u][i1];
        reproductionPaths[u][i1] = reproductionPaths[u][i2];
        reproductionPaths[u][i2] = temp;
    }
    reproductionPaths[u][GetNrOfCities()] = reproductionPaths[u][0];
}

std::vector<unsigned int> Darwin()
{
    std::clock_t begin = clock();
    unsigned int shortestDist = INT_MAX;
    std::vector<unsigned int> bestPath;
    for (unsigned int i = 0; i < NR_OF_ORGANISMS; ++i)
    {
        currentPaths[i].clear();
    }

    for (unsigned int i = 0; i < GetNrOfCities(); ++i)
    {
        for (unsigned int j = 0; j < NR_OF_ORGANISMS; ++j)
        {
            currentPaths[j].push_back(i);
        }
    }

    for (unsigned int i = 0; i < NR_OF_ORGANISMS; ++i)
    {
        std::random_shuffle(currentPaths[i].begin(), currentPaths[i].end());
        currentPaths[i].push_back(currentPaths[i][0]);
    }

    for (int nrOfGenerations = 0; nrOfGenerations < 1000; ++nrOfGenerations)
    {
        for (unsigned int i = 0; i < NR_OF_ORGANISMS; ++i)
        {
            OrgData[i].length = GetPathLength(currentPaths[i]);
            OrgData[i].index = i;
        }
        std::sort(OrgData, OrgData + NR_OF_ORGANISMS);

        for (unsigned int i = 0; i < NR_OF_ORGANISMS; i++) reproductionPaths[i] = currentPaths[i];
        reproduce(10);

        for (unsigned int i = 0; i < NR_OF_ORGANISMS + NR_OF_REPRODUCTIONS; i++)
        {
            RepData[i].length = GetPathLength(reproductionPaths[i]);
            RepData[i].index = i;
        }
        std::sort(RepData, RepData + NR_OF_ORGANISMS + NR_OF_REPRODUCTIONS);

        for (unsigned int i = NR_OF_ORGANISMS * 0.05; i < NR_OF_ORGANISMS * 0.15; ++i) swap(i, 1);
        for (unsigned int i = NR_OF_ORGANISMS * 0.15; i < NR_OF_ORGANISMS * 0.25; ++i) swap(i, 2);
        for (unsigned int i = NR_OF_ORGANISMS * 0.25; i < NR_OF_ORGANISMS * 0.35; ++i) swap(i, 3);
        for (unsigned int i = NR_OF_ORGANISMS * 0.35; i < NR_OF_ORGANISMS; ++i)
        {
            int u = OrgData[i].index;
            std::random_shuffle(reproductionPaths[u].begin(), --reproductionPaths[u].end());
            reproductionPaths[u][reproductionPaths[u].size() - 1] = reproductionPaths[u][0];
        }

        for (unsigned int i = 0; i < NR_OF_ORGANISMS + NR_OF_REPRODUCTIONS; i++)
        {
            if (GetPathLength(reproductionPaths[i]) < shortestDist)
            {
                shortestDist = GetPathLength(reproductionPaths[i]);
                bestPath = reproductionPaths[i];
                std::cout << "\n\nCurrent best distance is: " << shortestDist << "\n";
                printPath(reproductionPaths[i]);
            }
        }

        for (unsigned int i = 0; i < NR_OF_ORGANISMS; i++)
        {
            int u = RepData[i].index;
            currentPaths[i] = reproductionPaths[u];
            OrgData[i].index = i;
            OrgData[i].length = GetPathLength(currentPaths[i]);
        }
    }

    std::clock_t end = clock();
    std::cout << "\n\nBest distance that has been found: " << shortestDist << " km\nPath is: ";
    printPath(bestPath);
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    std::cout << "\nTotal time elapsed: " << elapsed_secs << " seconden\n\n\n\n";

    return(bestPath);
}