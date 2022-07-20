#include <iostream>
#include "module.hpp"

void deleteString(int** matrix, int raw, int column, int index) {
    int temp = 0;
    for (int i = index; i < raw - 1; i++) {
        for (int j = 0; j < column; j++) {
            temp = *(*(matrix + i) + j);
            *(*(matrix + i) + j) = *(*(matrix + i + 1) + j);
            *(*(matrix + i + 1) + j) = temp;
        }
    }
}

void printMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << *(*(matrix + i) + j) << " ";
        }
        std::cout << std::endl;
    }
}

void sort(int* matrix, int n) {
    int temp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(matrix + j) > *(matrix + j + 1)) {
                temp = *(matrix + j + 1);
                *(matrix + j + 1) = *(matrix + j);
                *(matrix + j) = temp;
            }
        }
    }
}