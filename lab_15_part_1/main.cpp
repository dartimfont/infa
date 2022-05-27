#include <iostream>
#include <cstring>

int sumNumInString(const char* str)
{
    char temp[1000];
    strcpy(temp, str);

    int result = 0;
    char* p = strtok(temp, " \0");
    while (p != NULL)
    {
        result += atoi(p);
        p = strtok(NULL, " \0");
    }
    return result;
}

void printStrings(const char* path)
{
    char buffer[1000];
    FILE* in = fopen(path, "r");

    int i = 1;
    while (fgets(buffer, 1000, in))
    {
        std::cout << i << " | " << buffer;
        std::cout << "Sum in string " << i << ": "<< sumNumInString(buffer) << std::endl;
        i++;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    FILE* in; 
    FILE* out;

    int a, b, x, quantityNum, quantityRaws;
    char buffer[1000];
    quantityRaws = rand() % 10 + 1;
    quantityNum = rand() % 30 + 1;

    in = fopen("input.txt", "w");
    for (a = 0; a < quantityRaws; a++)
    {
        for (b = 0; b < quantityNum; b++)
        {
            x = rand() % 100 + 1;
            itoa(x, buffer, 10);
            fputs(buffer, in);
            fputs(" ", in);
        }
        fputs("\n", in);
    }
    fclose(in);

    std::cout << "Input strings\n";
    printStrings("input.txt");

    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    int num;
    std::cout << "Input num: ";
    std::cin >> num;

    while (fgets(buffer, 1000, in))
    {
        if (sumNumInString(buffer) >= num)
        {
            fputs(buffer, out);
        }
    }
    fclose(out);
    fclose(in);    

    std::cout << "String with sum of num more then " << num << std::endl;
    printStrings("Output.txt");
    
    remove("input.txt");

    return 0;
}
