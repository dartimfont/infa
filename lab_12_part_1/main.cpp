#include <iostream>
#include <cmath>
#include <ctime>

void printMatrix(int** matrix, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            std::cout.width(4);
            std::cout << *(*(matrix + i) + j);
        }
        std::cout << std::endl;
    }
}

int main()
{
    system("color E1");
    srand((unsigned)time(NULL));
	int length;

	std::cout << "Input length of matrix: ";
	std::cin >> length;

    int** array = new int* [length];
    for (int i = 0; i < length; i++) {
        *(array + i) = new int[length];
        for (int j = 0; j < length; j++) {
            *(*(array + i) + j) = rand() % 100;
        }
    }

    std::cout << "Input matrix\n";
    printMatrix(array, length);

    int max_1 = 0;
    int max_2 = 0;
    int min_1 = 10000;
    int min_2 = 10000;

    int index_i1_max = 0;
    int index_i2_max = 0;
    int index_i1_min = 0;
    int index_i2_min = 0;

    for (int i = 0; i < length; i++) {
        if (*(*(array + i) + i) > max_1) {
            max_1 = *(*(array + i) + i);
            index_i1_max = i;
        }
        if (*(*(array + i) + length - i - 1) > max_2) {
            max_2 = *(*(array + i) + length - i - 1);
            index_i2_max = i;
        }
        if (*(*(array + i) + i) < min_1) {
            min_1 = *(*(array + i) + i);
            index_i1_min = i;
        }
        if (*(*(array + i) + length - i - 1) < min_2) {
            min_2 = *(*(array + i) + length - i - 1);
            index_i2_min = i;
        }
    }

    std::cout << "Max in main: " << *(*(array + index_i1_max) + index_i1_max) << " (" << (*(array + index_i1_max) + index_i1_max) << ")" << std::endl;
    std::cout << "Max in not main: " << *(*(array + index_i2_max) + length - index_i2_max - 1) << " (" << (*(array + index_i2_max) + length - index_i2_max - 1) << ")" << std::endl;
    std::cout << "Min in main: " << *(*(array + index_i1_min) + index_i1_min) << " (" << (*(array + index_i1_min) + index_i1_min) << ")" << std::endl;
    std::cout << "Min in not main: " << *(*(array + index_i2_min) + length - index_i2_min - 1) << " (" << (*(array + index_i2_min) + length - index_i2_min - 1) << ")" << std::endl;

    *(*(array + index_i1_max) + index_i1_max) = max_2;
    *(*(array + index_i2_max) + length - index_i2_max - 1) = max_1;
    *(*(array + index_i1_min) + index_i1_min) = min_2;
    *(*(array + index_i2_min) + length - index_i2_min - 1) = min_1;
  
    std::cout << "Output matrix\n";
    printMatrix(array, length);

    for (int i = 0; i < length; i++) {
        delete[] array[i];
    }
    delete[] array;
    return 0;
}
