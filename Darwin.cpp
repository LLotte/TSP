/*#include <vector> 
#include <iostream> 
#include <assert.h>
#include <ctime>
#include <algorithm>
#include "CityMapFunctions.h"
#include "DistanceCalculations.h"
#include "Darwin.h"
#define NR_OF_ORGANISMS  100

struct OrganismData
{
    int length;
    int index;
    bool operator < (const OrganismData& rhs) const {
        return length < rhs.length;
    }
};

OrganismData OrgData[NR_OF_ORGANISMS];
std::vector<unsigned int> currentPaths[NR_OF_ORGANISMS];

void swap(int index, int nrOfSwaps)
{
    int u = OrgData[index].index;
    for (int i = 0; i < nrOfSwaps; ++i)
    {
        int i1 = rand() % (GetNrOfCities() - 1);
        int i2 = rand() % (GetNrOfCities() - 1);

        int temp = currentPaths[u][i1] ;
        currentPaths[u][i1] = currentPaths[u][i2];
        currentPaths[u][i2] = temp;
    }
    currentPaths[u][GetNrOfCities()] = currentPaths[u][0];
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

    for (int nrOfGenerations = 0; nrOfGenerations < 10000; ++nrOfGenerations)
    {
        for (unsigned int i = 0; i < NR_OF_ORGANISMS; ++i)
        {
            OrgData[i].length = GetPathLength(currentPaths[i]);
            OrgData[i].index = i;
        }
        std::sort(OrgData, OrgData + NR_OF_ORGANISMS);

        for (unsigned int i = NR_OF_ORGANISMS * 0.05; i < NR_OF_ORGANISMS * 0.15; ++i) swap(i, 1);
        for (unsigned int i = NR_OF_ORGANISMS * 0.15; i < NR_OF_ORGANISMS * 0.25; ++i) swap(i, 2);
        for (unsigned int i = NR_OF_ORGANISMS * 0.25; i < NR_OF_ORGANISMS * 0.35; ++i) swap(i, 3);
        for (unsigned int i = NR_OF_ORGANISMS * 0.35; i < NR_OF_ORGANISMS; ++i)
        {
            int u = OrgData[i].index;
            std::random_shuffle(currentPaths[u].begin(), --currentPaths[u].end());
            currentPaths[u][currentPaths[u].size() - 1] = currentPaths[u][0];
        }

        for (unsigned int i = 0; i < NR_OF_ORGANISMS; i++)
        {
            if (GetPathLength(currentPaths[i]) < shortestDist)
            {
                shortestDist = GetPathLength(currentPaths[i]);
                bestPath = currentPaths[i];
                std::cout << "\n\nCurrent best distance is: " << shortestDist << "\n";
                printPath(currentPaths[i]);
            }
        }
    }

    std::clock_t end = clock();
    std::cout << "\n\nBest distance that has been found: " << shortestDist << " km\nPath is: ";
    printPath(bestPath);
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    std::cout << "\nTotal time elapsed: " << elapsed_secs << " seconden\n\n\n\n";

    return(bestPath);
}*/