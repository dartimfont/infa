#include <iostream>
#include <cmath>
#include <ctime>

int main()
{
    srand((unsigned)time(NULL));
	int length;

	std::cout << "Input length of array: ";
	std::cin >> length;

    int** array = new int* [length];
    for (int i = 0; i < length; i++) {
        *(array + i) = new int[length];
    }

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            *(*(array + i) + j) = rand() % 100;
            std::cout.width(4);
            std::cout << *(*(array + i) + j);
        }
        std::cout << std::endl;
    }

    int max_1 = 0;
    int min_1 = 1000000;
    int max_2 = 0;
    int min_2 = 1000000;

    for (int i = 0; i < length; i++) {
        if (array[i][i] > max_1) {
            max_1 = array[i][i];
        }
        if (array[i][i] < min_1) {
            min_1 = array[i][i];
        }
        if (array[i][length - i - 1] > max_2) {
            max_2 = array[i][length - i - 1];
        }
        if (array[i][length - i - 1] < min_2) {
            min_2 = array[i][length - i - 1];
        }
    }

    std::cout << max_1 << std::endl;
    std::cout << min_1 << std::endl;
    std::cout << max_2 << std::endl;
    std::cout << min_2 << std::endl;

    for (int i = 0; i < length; i++) {
        if (max_1 == array[i][i]) {
            
        }
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++) {
            std::cout.width(4);
            std::cout << *(*(array + i) + j);
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < length; i++) {
        delete [] array[i];
    }
    
    delete [] array;
    return 0;
}
