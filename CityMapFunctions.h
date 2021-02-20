#pragma once
#include <vector> 

unsigned int GetDistance(unsigned int row, unsigned column);
unsigned int GetNrOfCities();
bool IsCityInPath(std::vector<unsigned int> path, unsigned int city);
void printPath(std::vector<unsigned int> path);
unsigned int GetPathLength(std::vector<unsigned int> path);