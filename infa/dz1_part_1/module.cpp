#include "module.hpp"

void deleteString(int** array, int& raw, int column, int index) {
    int temp = 0;
    for (int i = index; i < raw; i++)
    {
        for (int j = 0; j < column; j++)
        {
            temp = *(*(array + j) + raw);
            *(*(array + j) + raw) = *(*(array + j) + raw + 1);
            *(*(array + j) + raw + 1) = temp;
        }
        raw--;
    }
}