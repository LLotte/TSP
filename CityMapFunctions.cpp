#include <vector> 
#include <iostream> 
#include <assert.h>
#include "CityMapFunctions.h"

/*static std::vector<std::vector<unsigned int> > cityDistances = {
               { 0,  4,  7,  4,  6,  4,  6,  7},
               { 4,  0,  8,  5,  8,  5,  8,  4},
               { 7,  8,  0,  6,  9,  6,  5, 10},
               { 4,  5,  6,  0, 10, 12,  3,  5},
               { 6,  8,  9, 10,  0,  7, 18, 13},
               { 4,  5,  6, 12,  7,  0,  9,  8},
               { 6,  8,  5,  3, 18,  9,  0, 20},
               { 7,  4, 10,  5, 13,  8, 20,  0}
};*/

static std::vector<std::vector<unsigned int> > cityDistances = {
               {   0, 141, 118, 171, 126,  69, 158,  79, 166, 208,  65,  67,  98,  97},
               { 141,   0, 266,  34, 212, 208,  82, 114, 305, 324, 165,  75, 187, 118},
               { 118, 266,  0,  232,  56, 107, 194, 109, 229, 122,  61, 151,  60, 201},
               { 171,  34, 232,   0, 200, 233,  63, 128, 332, 347, 188, 104, 180, 146},
               { 126, 212,  56, 200,   0, 105, 145,  84, 228, 170,  55, 123,  19, 181},
               {  69, 208, 107, 233, 105,   0, 212, 113, 123, 144,  54, 133,  96, 163},
               { 158,  82, 194,  63, 145, 212,   0, 104, 324, 323, 161,  93, 137, 161},
               {  79, 114, 109, 128,  84, 113, 104,   0, 236, 225,  65,  51,  58, 133},
               { 166, 305, 229, 332, 228, 123, 324, 236,   0, 187, 177, 230, 219, 239},
               { 208, 324, 122, 347, 170, 144, 323, 225, 187,   0, 165, 249, 198, 298},
               {  65, 165,  61, 188,  55,  54, 161,  65, 177, 165,   0,  91,  48, 140},
               {  67,  75, 151, 104, 123, 133,  93,  51, 230, 249,  91,   0, 104,  73},
               {  98, 187,  60, 180,  19,  96, 137,  58, 219, 198,  48, 104,   0, 161},
               {  97, 118, 201, 146, 181, 163, 161, 133, 239, 298, 140,  73, 161,   0}
};

unsigned int GetDistance(unsigned int row, unsigned column)
{
    return cityDistances[row][column];
}

unsigned int GetNrOfCities()
{
    return (unsigned int)cityDistances.size();
}

bool IsCityInPath(std::vector<unsigned int> path, unsigned int city)
{
    for (int i = 0; i < path.size(); i++)
    {
        if (path[i] == city)
        {
            return true;
        }
    }
    return false;
}

void printPath(std::vector<unsigned int> path)
{
    std::cout << "Path is: ";
    for (int i = 0; i < path.size(); i++)
    {
        std::cout << path[i] << " ";
    }
}

unsigned int GetPathLength(std::vector<unsigned int> path)
{
    unsigned int length = 0;
    for (size_t i = 0; i < path.size() - 1; ++i)
    {
        length = length + GetDistance(path[i], path[i + 1]);
    }
    return length;
}
