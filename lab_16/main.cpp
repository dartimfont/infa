#include <iostream>

bool check(char* word) {
    bool isFind = false;

    if ((word[0] == '+') || (word[0] == '-')) {
        return check(++word);
    }
    
    if (*word != '\0') {
        if (*word >= '0' && *word <= '9') {
            return check(++word);
        } else {
            isFind = true;
        }
    }
    return !isFind;
}

int main() {

    char word[100];
    gets(word);

    if (check(word)) {
        std::cout << "True!\n";
    } else {
        std::cout << "False!\n";
    }

    return 0;
}