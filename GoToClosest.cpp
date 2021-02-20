#include <vector> 
#include <iostream> 
#include <assert.h>
#include "CityMapFunctions.h"
#include "GoToClosest.h"
#include <ctime>

unsigned int GoToClosest()
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
            unsigned int closestCity = 0;
            unsigned int shortestDist = INT_MAX;
            for (unsigned int i = 0; i < GetNrOfCities(); i++)
            {
                if (IsCityInPath(visited, i) == false)
                {
                    if (GetDistance(currentCity, i) < shortestDist)
                    {
                        shortestDist = GetDistance(currentCity, i);
                        closestCity = i;
                    }
                }
            }
            currentCity = closestCity;

            shortestPathLength = shortestPathLength + shortestDist;
            std::cout << " >>>  Closest city: " << closestCity << "   Distance is: " << shortestDist << "\n";
            visited.push_back(closestCity);
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