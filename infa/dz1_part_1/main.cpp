#include <iostream>
#include "module.hpp"

int main () {
    srand((unsigned)time(NULL));
    int n, m, t;
    std::cout << "Vvedite kolichestvo strok: ";
    std::cin >> n;
    std::cout << "Vvedite kolichestvo stolbsov: ";
    std::cin >> m;
    t = n;

    int** array = new int*[n];
    for (int i = 0; i < n; i++) {
        array[i] = new int[m];
    }

    int* l = new int [t];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            *(*(array + j) + i) = rand() % 100 + 3; 
        }
    }

    std::cout << "Input matrix\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << *(*(array + j) + i) << " "; 
        }
        std::cout << std::endl;
    }

    std::cout << "Massiv s indeksami strok: ";
    for (int i = 0; i < n; i++) {
        *(l + i) = rand() % n; 
        std::cout << *(l + i) << " ";
    }
    std::cout << std::endl;

    //deleteString(array, n, m, 0);
    

    std::cout << "Output matrix\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << *(*(array + j) + i) << " "; 
        }
        std::cout << std::endl;
    }

    
    delete[] l;
    return 0;
}