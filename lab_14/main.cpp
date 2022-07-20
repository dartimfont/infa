#include <iostream>

#include "Module.hpp"

int main() {
    int length;
    std::cout << "Enter length: ";
    do {
        std::cin >> length;
        if (length % 2 == 0)
            std::cout << "Try input again: ";
    } while (length % 2 == 0);
    int** array = init_matrix(length);
    print_matrix(array, length);
    module(array, length);
    print_matrix(array, length);
    delete_matrix(array, length);
    system("pause");
    return 0;
}
