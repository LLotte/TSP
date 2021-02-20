#include <vector> 
#include <iostream> 
#include <assert.h>
#include <algorithm>
#include "CityMapFunctions.h"
#include <ctime>

std::vector<unsigned int> MixPermutations()
{
    std::clock_t begin = clock();
    std::vector<unsigned int> myPath;
    for (unsigned int i = 0; i < GetNrOfCities(); ++i)
    {
        myPath.push_back(i);
    }
    myPath.push_back(0);

    unsigned int nmbrOfShuffles = 15;
    unsigned int nmbrOfLoops = 45;
    unsigned int temp = INT_MAX;
    unsigned int shortestPathLength = INT_MAX;
    std::vector<unsigned int> bestPath;

    for (unsigned int i = 0; i < nmbrOfShuffles; ++i)
    {
        std::random_shuffle(++myPath.begin(), --myPath.end());
        if (GetPathLength(myPath) < temp)
        {
            temp = GetPathLength(myPath);
            std::vector<unsigned int> tempBestPath = myPath;
            shortestPathLength = temp;
            bestPath = myPath;
            printPath(myPath);
            std::cout << "\nCurrent best distance is: " << temp << "\n\n";

            for (unsigned int j = 0; j < nmbrOfLoops; j++) 
            {
                unsigned int randomCity = rand() % (myPath.size() - 2) + 1;
                unsigned int cityValue = tempBestPath[randomCity];

                if (randomCity > 1)
                {
                    tempBestPath.erase(tempBestPath.begin() + randomCity);
                    tempBestPath.insert(tempBestPath.begin() + randomCity - 1, cityValue);
                }
                else if (randomCity == 1)
                {
                    tempBestPath.erase(tempBestPath.begin() + randomCity);
                    tempBestPath.insert(tempBestPath.begin() + randomCity + 1, cityValue);
                }


                if (GetPathLength(tempBestPath) < temp)
                {
                    temp = GetPathLength(tempBestPath);
                    printPath(tempBestPath);
                    std::cout << "\nCurrent best distance is: " << temp << "\n\n";
                    shortestPathLength = temp;
                    bestPath = tempBestPath;
                }
            }
        }
    }

    std::clock_t end = clock();
    std::cout << "Best distance that has been found: " << shortestPathLength << " km\nPath is: ";
    printPath(bestPath);
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    std::cout << "\nTotal time elapsed: " << elapsed_secs << " seconden\n\n\n\n";    

    return myPath;
}