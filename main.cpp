#include <assert.h>
#include <vector> 
#include <iostream>   
#include <algorithm>
#include <Windows.h>
#include "BruteForce.h"
#include "GoToClosest.h"
#include "FarthestInsertion.h"
#include "MixPermutations.h"
#include "Genetic.h"
#include <cstdlib>
#include <ctime>

void MenuMessage()
{
    std::cout << " Press A to run the Brute force method. \n Press B to run the nearest neighbour method.\n Press C to run the farthest insertion (maximum version) method.\n";
    std::cout << " Press D to run the farthest insertion (normal version) method.\n Press E to run the mix permutations method.\n Press F to run the genetic algorithm.\n";
    std::cout << " Press Left control to exit the program.\n";
}

void PrintCityMap()
{
    std::cout << " CITY MAP DATA:\n";
    std::cout << " |   0, 141, 118, 171, 126,  69, 158,  79, 166, 208,  65,  67,  98,  97 |\n | 141,   0, 266,  34, 212, 208,  82, 114, 305, 324, 165,  75, 187, 118 |\n";
    std::cout << " | 118, 266,  0,  232,  56, 107, 194, 109, 229, 122,  61, 151,  60, 201 |\n | 171,  34, 232,   0, 200, 233,  63, 128, 332, 347, 188, 104, 180, 146 |\n";
    std::cout << " | 126, 212,  56, 200,   0, 105, 145,  84, 228, 170,  55, 123,  19, 181 |\n |  69, 208, 107, 233, 105,   0, 212, 113, 123, 144,  54, 133,  96, 163 |\n";
    std::cout << " | 158,  82, 194,  63, 145, 212,   0, 104, 324, 323, 161,  93, 137, 161 |\n |  79, 114, 109, 128,  84, 113, 104,   0, 236, 225,  65,  51,  58, 133 |\n";
    std::cout << " | 166, 305, 229, 332, 228, 123, 324, 236,   0, 187, 177, 230, 219, 239 |\n | 208, 324, 122, 347, 170, 144, 323, 225, 187,   0, 165, 249, 198, 298 |\n";
    std::cout << " |  65, 165,  61, 188,  55,  54, 161,  65, 177, 165,   0,  91,  48, 140 |\n |  67,  75, 151, 104, 123, 133,  93,  51, 230, 249,  91,   0, 104,  73 |\n";
    std::cout << " |  98, 187,  60, 180,  19,  96, 137,  58, 219, 198,  48, 104,   0, 161 |\n |  97, 118, 201, 146, 181, 163, 161, 133, 239, 298, 140,  73, 161,   0 |\n\n";
}

int main()
{
    std::srand(std::time(0));
    std::cout << "\n WELCOME!\n";
    PrintCityMap();
    MenuMessage();
    while (true) {
        if (GetAsyncKeyState('A') != 0)
        {
            std::cout << "\n\nBRUTE FORCE METHOD\n\n\n";
            BruteForce();
            MenuMessage();
        }
        else if (GetAsyncKeyState('B') != 0)
        {
            std::cout << "\n\nNEAREST NEIGHBOUR METHOD\n\n\n";
            GoToClosest();
            MenuMessage();
        }
        else if (GetAsyncKeyState('C') != 0)
        {
            std::cout << "\n\n FARTHEST INSERTION (MAXIMUM VERSION) METHOD\n\n\n";
            FarthestInsertionMax();
            MenuMessage();
        }
        else if (GetAsyncKeyState('D') != 0)
        {
            std::cout << "\n\n FARTHEST INSERTION (NORMAL VERSION) METHOD\n\n\n";
            FarthestInsertion();
            MenuMessage();
        }
        else if (GetAsyncKeyState('E') != 0)
        {
            std::cout << "\n\n MIX PERMUTATIONS METHOD\n\n\n";
            MixPermutations();
            MenuMessage();
        }
        else if (GetAsyncKeyState('F') != 0)
        {
            std::cout << "\n\n GENETIC ALGORITHM\n\n\n";
            Darwin();
            MenuMessage();
        }
        else if (GetAsyncKeyState(VK_LCONTROL) != 0)
        {
            break;
        }
        Sleep(300);
    }
	return 0;
}