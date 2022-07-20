#include <iostream>
#include <ctime>
#include "module.hpp"

int main() {
    system("color E1");
    srand((unsigned)time(NULL));
    int n, m;
    std::cout << "Vvedite kolichestvo strok: ";
    std::cin >> n;
    std::cout << "Vvedite kolichestvo stolbsov: ";
    std::cin >> m;

    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        *(matrix + i) = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            *(*(matrix + i) + j) = rand() % 100 + 3;
        }
    }
    std::cout << "Input matrix\n";
    printMatrix(matrix, n, m);

    int* l = new int[n];
    for (int i = 0; i < n; i++) {
        *(l + i) = rand() % n;
    } 
    std::cout << "Massiv s indeksami strok: ";
    for (int i = 0; i < n; i++) {
        std::cout << *(l + i) << " ";
    }
    std::cout << std::endl;
    sort(l, n);

    int cnt = 1;
    int lenIndex = n;
    deleteString(matrix, n, m, *l);
    for (int i = 1; i < lenIndex; i++) {
        if (*(l + i) != *(l + i - 1)) {
            deleteString(matrix, n, m, *(l + i) - cnt);
            cnt++;
        }
    }

    std::cout << "Output matrix\n";
    printMatrix(matrix, n - cnt, m);

    system("pause");
    delete[] l;

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}