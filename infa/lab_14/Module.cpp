#include "Module.hpp"

void module(int** array, int length, int index)
{
    int counterPositive = 0;
    int counterNegative = 0;

    for (int i = 0; i < length; i++)
    {
        if (array[index][i] < 0)
        {
            counterNegative++;
        }
        else
        {
            counterPositive++;
        }
    }

    array[index][length/2] = counterPositive - counterNegative;

    std::cout << "String " << index + 1 << std::endl;

    std::cout << "Quantity positive nums: "
        << counterPositive << std::endl;

    std::cout << "Quantity negative nums: "
        << counterNegative << std::endl;

    std::cout << "Positive minus negative: "
        << array[index][length/2] << std::endl << std::endl;
}
