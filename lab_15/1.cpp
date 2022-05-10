#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int sumNumInString(std::string str)
{
    int sum = 0;
    std::istringstream iss(str);
    std::cout << str << std::endl;
    for (std::string num; getline(iss, num, ' ');)
    {
        //std::cout << num << " ";
        //sum += std::stoi(num);
    }
    //std::cout << std::endl;

    return sum;
}

int main()
{
    srand((unsigned)time(NULL));
    std::ofstream in("./input.txt");

    int a, b, quantityNum, quantityRaws;
    quantityRaws = rand() % 10 + 1;
    quantityNum = rand() % 30 + 1;

    for (a = 0; a < quantityRaws; a++)
    {
        for (b = 0; b < quantityNum; b++)
        {
            in.width(4);
            in << rand() % 201 - 100;
        }
        in << "\n";
    }

    in.close();

    std::ifstream out("./input.txt");
    std::string line;

    while (getline(out, line))
    {
        std::cout << line << "  Sum in string = " << sumNumInString(line) <<  std::endl;
    }
    std::cout << std::endl;



    out.close();

    return 0;
}
