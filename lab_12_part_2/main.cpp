#include <iostream>

int main() {
    system("color E1");
    srand((unsigned)time(NULL));
    int len;
    std::cout << "Input len of matrix: ";
    std::cin >> len;

    int** array = new int*[len];
    for (int i = 0; i < len; i++) {
        *(array + i) = new int[len];
    }

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            *(*(array + i) + j) = rand() % 50 + 10;
        }
    }

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            std::cout.width(4);
            if (i <= j && i <= len - j - 1) {
                std::cout << *(*(array + i) + j);
            }
            else if (i >= j && i >= len - j - 1) {
                std::cout << *(*(array + i) + j);
            } else {
                std::cout << " ";
            }        
        }
        std::cout << std::endl;
    }

    return 0;
}
