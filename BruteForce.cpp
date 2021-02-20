#include <vector> 
#include <iostream> 
#include <assert.h>
#include <algorithm>
#include "CityMapFunctions.h"
#include "BruteForce.h"
#include <ctime>

std::vector<unsigned int> BruteForce()
{
    std::clock_t begin = clock();
    std::vector<unsigned int> bestPath;
    std::vector<unsigned int> myPath;
    for (unsigned int i = 0; i < GetNrOfCities(); ++i)
    {
        myPath.push_back(i);
    }
    myPath.push_back(0);

    unsigned int shortestPathLength = INT_MAX;
    do {
        unsigned int temp = GetPathLength(myPath);
        if (temp < shortestPathLength)
        {
            temp = GetPathLength(myPath);
            shortestPathLength = temp;
            printPath(myPath);
            std::cout << "Length: " << shortestPathLength << "\n";
            bestPath = myPath;
        }
    } while (std::next_permutation(++myPath.begin(), --myPath.end()));

    std::clock_t end = clock();
    std::cout << "\n\n\n\nBest distance that has been found: " << shortestPathLength << " km\nPath is: ";
    printPath(bestPath);
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    std::cout << "\nTotal time elapsed: " << elapsed_secs << " seconden\n\n\n\n";

    return myPath;
}