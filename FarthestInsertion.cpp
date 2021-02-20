#include <vector> 
#include <iostream> 
#include <assert.h>
#include "CityMapFunctions.h"
#include "FarthestInsertion.h"
#include <ctime>

unsigned int FarthestInsertion()
{
    std::clock_t begin = clock();
    std::vector<unsigned int> bestPath;
    unsigned int shortestPathOfAll = INT_MAX;
    for (unsigned int city = 0; city < GetNrOfCities(); city++)
    {
        std::vector<unsigned int> visited;
        unsigned int currentCity = city;
        visited.push_back(currentCity);
        unsigned int  shortestPathLength = 0;

        while (visited.size() != GetNrOfCities())
        {
            unsigned int furthestCity = 0;
            unsigned int highestDist = 0;
            unsigned int shortestDist = INT_MAX;
            unsigned int positionClosestCity = 0;

            for (unsigned int i = 0; i < GetNrOfCities(); i++)
            {
                if (IsCityInPath(visited, i) == false)
                {
                    if (GetDistance(i, currentCity) > highestDist)
                    {
                        highestDist = GetDistance(currentCity, i);
                        furthestCity = i;
                    }
                }
            }
            currentCity = furthestCity;

            unsigned int tempPosition = 0;
            unsigned int tempCity = 0;

            for (unsigned int k = 0; k < GetNrOfCities(); k++)
            {
                if (IsCityInPath(visited, k) == true)
                {
                    for (unsigned int j = 0; j < visited.size(); j++)
                    {
                        if (visited[j] == k)
                            tempPosition = j;
                    }

                    if (tempPosition == 0)
                    {
                        tempCity = 1;
                        tempPosition = 1;
                    }
                    else if (tempPosition < visited.size() - 1)
                    {
                        unsigned int temp = tempPosition + 1;
                        tempCity = visited[temp];
                        tempPosition = temp;
                    }
                    else if (tempPosition == visited.size() - 1)
                    {
                        tempCity = visited[tempPosition - 1];
                        tempPosition = tempPosition - 1;
                    }

                    
                    if (GetDistance(k, furthestCity) + GetDistance(tempCity, furthestCity) < shortestDist)
                    {
                        shortestDist = GetDistance(k, furthestCity) + GetDistance(tempCity, furthestCity);
                        positionClosestCity = tempPosition;
                    }
                }
            }

            visited.insert(visited.begin() + positionClosestCity, furthestCity);
            
            shortestPathLength = shortestPathLength + highestDist;
            std::cout << " >>>  City with highest distance: " << furthestCity << "\n";
        }

        visited.push_back(visited[0]);
        shortestPathLength = GetPathLength(visited);

        std::cout << "\nCurrent Shortest path: " << shortestPathLength << "\n";
        printPath(visited);
        std::cout << "\n\n\n";
        if (shortestPathLength < shortestPathOfAll)
        {
            shortestPathOfAll = shortestPathLength;
            bestPath = visited;
        }

    }
    std::clock_t end = clock();
    std::cout << "Best distance that has been found: " << shortestPathOfAll << " km\nPath is: ";
    printPath(bestPath);
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    std::cout << "\nTotal time elapsed: " << elapsed_secs << " seconden\n\n\n\n";

    return shortestPathOfAll;
}

unsigned int FarthestInsertionMax()
{
    std::clock_t begin = clock();
    std::vector<unsigned int> bestPath;
    unsigned int shortestPathOfAll = INT_MAX;
    for (unsigned int city = 0; city < GetNrOfCities(); city++)
    {
        std::vector<unsigned int> visited;
        unsigned int currentCity = city;
        visited.push_back(currentCity);
        unsigned int  shortestPathLength = 0;

        while (visited.size() != GetNrOfCities())
        {
            unsigned int furthestCity = 0;
            unsigned int highestDist = 0;
            unsigned int shortestDist = INT_MAX;
            unsigned int positionClosestCity = 0;

            for (unsigned int i = 0; i < GetNrOfCities(); i++)
            {
                if (IsCityInPath(visited, i) == false)
                {
                    unsigned int tempDist = 0;
                    for (unsigned int n = 0; n < visited.size(); n++)
                    {
                        tempDist = tempDist + GetDistance(i, visited[n]);
                    }

                    if (tempDist > highestDist)
                    {
                        highestDist = tempDist;
                        furthestCity = i;
                    }
                }
            }
            currentCity = furthestCity;

            unsigned int tempPosition = 0;
            unsigned int tempCity = 0;

            for (unsigned int k = 0; k < GetNrOfCities(); k++)
            {
                if (IsCityInPath(visited, k) == true)
                {
                    for (unsigned int j = 0; j < visited.size(); j++)
                    {
                        if (visited[j] == k)
                            tempPosition = j;
                    }

                    if (tempPosition == 0)
                    {
                        tempCity = 1;
                        tempPosition = 1;
                    }
                    else if (tempPosition < visited.size() - 1)
                    {
                        unsigned int temp = tempPosition + 1;
                        tempCity = visited[temp];
                        tempPosition = temp;
                    }
                    else if (tempPosition == visited.size() - 1)
                    {
                        tempCity = visited[tempPosition - 1];
                        tempPosition = tempPosition - 1;
                    }


                    if (GetDistance(k, furthestCity) + GetDistance(tempCity, furthestCity) < shortestDist)
                    {
                        shortestDist = GetDistance(k, furthestCity) + GetDistance(tempCity, furthestCity);
                        positionClosestCity = tempPosition;
                    }
                }
            }

            visited.insert(visited.begin() + positionClosestCity, furthestCity);

            shortestPathLength = shortestPathLength + highestDist;
            std::cout << " >>>  City with highest distance: " << furthestCity << "\n";
        }

        visited.push_back(visited[0]);
        shortestPathLength = GetPathLength(visited);

        std::cout << "\nCurrent Shortest path: " << shortestPathLength << "\n";
        printPath(visited);
        std::cout << "\n\n\n";
        if (shortestPathLength < shortestPathOfAll)
        {
            shortestPathOfAll = shortestPathLength;
            bestPath = visited;
        }

    }
    std::clock_t end = clock();
    std::cout << "Best distance that has been found: " << shortestPathOfAll << " km\nPath is: ";
    printPath(bestPath);
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    std::cout << "\nTotal time elapsed: " << elapsed_secs << " seconden\n\n\n\n";

    return shortestPathOfAll;
}