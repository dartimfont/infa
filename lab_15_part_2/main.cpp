#include <iostream>

int sumOfCharacter(int num)
{
    int result = 0;
    while (num != 0)
    {
        result += (num % 10);
        num /= 10;
    }
    return result;
}

void printNums(const char* path)
{
    FILE* fileStream = fopen(path, "rb");
    int x;
    while (fread(&x, sizeof(x), 1, fileStream))
    {
        std::cout.width(5);
        std::cout << x;
    }
    std::cout << std::endl;
    fclose(fileStream);
}

int main()
{
    srand((unsigned)time(NULL));
    FILE *in, *out;

    in = fopen("input.bin", "wb");

    int a, x, quantityNum;
    char buffer[1000];
    quantityNum = rand() % 30 + 2;

    for (a = 0; a < quantityNum; a++)
    {
        x = rand() % 899 + 101;
        fwrite(&x, sizeof(x), 1, in);
    }
    fclose(in);
    
    std::cout << "Input nums: ";
    printNums("input.bin");

    int num;
    std::cout << "Input num: ";
    std::cin >> num;

    in = fopen("input.bin", "rb");
    out = fopen("output.bin", "wb");

    while (fread(&x, sizeof(x), 1, in))
    {
        if (sumOfCharacter(x) >= num)
        {
            fwrite(&x, sizeof(x), 1, out);
        }
    }

    fclose(in);
    fclose(out);

    std::cout << "Nums which sum of character more then " << num << ": ";
    printNums("output.bin");


    remove("input.bin");

    return 0;
}