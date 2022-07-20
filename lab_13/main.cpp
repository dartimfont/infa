#include <iostream>
#include <cstring>

void run(char* word) {
    int counter = 0;
    std::cout << "Adreses for ";
    for (int i = 0; *(word + i) != '\0'; i++) {
        if (*(word + i) == '#') {
            counter++;
        }
        else if (counter != 0) {
            printf("#%1i%1c", counter, *(word + i));
            counter = 0;
        } else {
            printf("%1c", *(word + i));
        }
    }
    if (counter != 0) {
        printf("#%1i", counter);
        counter = 0;
    }

    int k = 0;
    std::cout << ": \n";
    for (int i = 0; *(word + i) != '\0'; i++) {
        if (*(word + i) == '#') {
            if (k == 0) {
                std::cout << word + i << ":\n";
            }
            k++;
            std::cout << " (" << std::hex << int(word + i) << ") ";
        }
        else if (k > 0) {
            printf("\n");
            counter++;
            k = 0;
        }
    }
    printf("\n");
}

int main() {
    int n;
    std::cout << "Vvedite shislo strok: ";
    std::cin >> n;

    char** arr = new char* [n];
    std::cout << "Vvedite text:\n";
    for (int i = 0; i < n; i++) {
        *(arr + i) = new char[255];
        std::cin >> *(arr + i);
    }
    std::cout << "Text:\n";
    for (int i = 0; i < n; i++) {
        std::cout << *(arr + i) << std::endl;
    }
    
    for (int i = 0; i < n; i++) {
        run(*(arr + i));  
    }

    system("pause");
    return 0;
}
