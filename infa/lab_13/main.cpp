#include <iostream>
#include <cstring>

int main()
{
    char word[100];
    std::cout << "Enter word: ";
    std::cin >> word;

    int len = strlen(word);

    std::cout << "Input word: ";
    for (int i = 0; word[i] != '\0'; i++)
    {
        printf("%1c", word[i]);
    }
    printf("\n");

    std::cout << "Output word: ";
    int counter = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] == '#')
        {
            counter++;
        }
        else if (counter != 0)
        {
            printf("#%1i%1c", counter, word[i]);
            counter = 0;
        }
        else
        {
            printf("%1c", word[i]);
        }
    }
    if (counter != 0)
    {
        printf("#%1i", counter);
        counter = 0;
    }
    printf("\n");

    return 0;
}
