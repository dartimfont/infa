#include <iostream>
//#include "module.hpp"

void deleteString(int** array, int& raw, int column, int index) {
    int temp = 0;
    for (int i = index; i < raw; i++)
    {
        for (int j = 0; j < column; j++)
        {
            temp = *(*(array + i) + j);
            *(*(array + i) + j) = *(*(array + i + 1) + j);
            *(*(array + i + 1) + j) = temp;
        }

        for (int i = 0; i < raw; i++) {
            for (int j = 0; j < column; j++) {
                std::cout << *(*(array + i) + j) << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    raw--;
}

int main() {
    srand((unsigned)time(NULL));
    int n, m, t;
    std::cout << "Vvedite kolichestvo strok: ";
    std::cin >> n;
    std::cout << "Vvedite kolichestvo stolbsov: ";
    std::cin >> m;
    t = n;

    int** array = new int* [n];
    for (int i = 0; i < n; i++)
    {
        *(array + i) = new int[m];
    }

    int* l = new int[t];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            *(*(array + i) + j) = rand() % 100 + 3;
        }
    }

    std::cout << "Input matrix\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << *(*(array + i) + j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Massiv s indeksami strok: ";
    for (int i = 0; i < n; i++) {
        *(l + i) = rand() % n;
        std::cout << *(l + i) << " ";
    }
    std::cout << std::endl;

    deleteString(array, n, m, 0);


    std::cout << "Output matrix\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << *(*(array + i) + j) << " ";
        }
        std::cout << std::endl;
    }


    delete[] l;
    return 0;
}