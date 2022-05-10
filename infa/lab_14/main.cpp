#include <iostream>
#include <ctime>

#include "Module.hpp"

int main()
{
    srand((unsigned)time(NULL));

    int length;
    std::cout << "Enter length: ";
    std::cin >> length;

    int** array = new int*[length];
    for (int i = 0; i < length; i++)
    {
        array[i] = new int[length];
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            array[i][j] = rand() % 101 - 50;
            printf("%4i", array[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < length; i++)
    {
        module(array, length, i);
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            printf("%4i", array[i][j]);
        }
        printf("\n");
    }


    return 0;
}
