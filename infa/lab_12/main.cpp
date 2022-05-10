#include <iostream>
#include <cmath>
#include <ctime>

int main()
{
    srand((unsigned)time(NULL));
	int length;

	std::cout << "Input length of array: ";
	std::cin >> length;

    int** array = new int* [length];
    for (int i = 0; i < length; i++)
    {
        array[i] = new int[length];
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            array[i][j] = rand() % 100;
            std::cout << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    int max = 0;
    int min = 1000000;

    for (int i = 0; i < length; i++)
    {
        if (array[i][i] > max)
        {
            max = array[i][i];
        }
    }

    std::cout << "Max " << max << std::endl;

    for (int i = 0; i < length; i++)
    {
        if (max == array[i][i])
        {
            int temp = array[i][i];
            array[i][i] = array[i][length - i - 1];
            array[i][length - i - 1] = temp;
        }
    }


    for (int i = 0; i < length; i++)
    {
        if (array[i][length - i - 1] < min)
        {
            min = array[i][length - i - 1];
        }
    }

    std::cout << "Min " << min << std::endl;

    for (int i = 0; i < length; i++)
    {
        if (min == array[i][length - i - 1])
        {
            int temp = array[i][length - i - 1];
            array[i][length - i - 1] = array[i][i];
            array[i][i] = temp;
        }
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            std::cout << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < length; i++)
    {
        delete [] array[i];
    }
    delete [] array;

    std::cout << std::endl;
    std::cout << "Input length of array (length < 10): ";
	std::cin >> length;

	while (length > 10)
	{
		std::cout << "Input correct length: ";
		std::cin >> length;
	}

    int** matrix = new int* [length];
    for (int i = 0; i < length; i++)
    {
        matrix[i] = new int[length];
    }

    std::cout << "Input matrix" << std::endl;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            matrix[i][j] = rand() % 100;
            printf("%4i", matrix[i][j]);
        }
        std::cout << std::endl;
    }

    std::cout << "Output matrix" << std::endl;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (i <= length - j - 1 && j >= i)
            {
                printf("%4i", array[i][j]);
            }
            else if (j >= length - i - 1 && j <= i)
            {
                printf("%4i", array[i][j]);
            }
            else
            {
                printf("    ");
            }
        }
        printf("\n");
    }


    return 0;
}
