#include <iostream>

#include "Module.hpp"

int** init_matrix(int length) {
    srand((unsigned)time(NULL));
    int** array = new int* [length];
    for (int i = 0; i < length; i++) {
        *(array + i) = new int [length];
        for (int j = 0; j < length; j++) {
            *(*(array + i) + j) = rand() % 101 - 50;
        }
    }
    return array;
}

void print_matrix(int** array, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            std::cout.width(4);
            std::cout << *(*(array + i) + j);
        }
        std::cout << std::endl;
    }
}

void delete_matrix(int** array, int length) {
    for (int i = 0; i < length; i++) {
        delete[] *(array + i);
    }
    delete[] array;
}

void module(int** array, int length) {
    int counterPositive;
    int counterNegative;
    for (int i = 0; i < length; i++) {
        counterPositive = 0; 
        counterNegative = 0;
        for (int j = 0; j < length; j++) {
            if (*(*(array + i) + j) < 0)
                counterNegative++;
            else
                counterPositive++;
        }
        *(*(array + i) + length / 2) = counterPositive - counterNegative;
        std::cout << "String " << i + 1 << std::endl;
        std::cout << "Quantity positive nums: " << counterPositive << std::endl;
        std::cout << "Quantity negative nums: " << counterNegative << std::endl;
        std::cout << "Positive minus negative: " << *(*(array + i) + length / 2) << std::endl << std::endl;
    }
}
