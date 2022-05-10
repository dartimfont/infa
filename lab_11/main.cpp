#include <iostream>
#include <cmath>
#include <ctime>

int main()
{
	srand((unsigned)time(NULL));
	int length;

	do {
		std::cout << "Input correct length: ";
		std::cin >> length;
	} while (length % 2 == 0);
	int* array = new int[length];
	std::cout << "Input array" << std::endl;
	for (int i = 0; i < length; i++)
	{
		*(array + i) = rand() % 101 - 50;
		std::cout << *(array + i) << "\t";
	}
	std::cout << std::endl;
	for (int i = 0; i < length; i++)
	{
		if (*(array + i) < 0)
		{
			std::cout << "Negative num " << *(array + i) << " addres " << (array + i) << std::endl;
		}
	}
	std::cout << "Average num " << *(array + length / 2) << " addres " << (array + length / 2) << std::endl;
	double sum = 0;
	int counter = 0;
	for (int i = 0; i < length; i++)
	{
		if (*(array + i) % 5 == 0)
		{
			sum += *(array + i);
		}
		if (*(array + i) < 0)
		{
			counter++;
		}
	}
	std::cout << "Sum kratnyh 5: " << sum << "\n"
		<< "Quntity negativ num: " << counter << std::endl;

	if (counter != 0 && sum != 0)
	{
		std::cout << "Final Num: " << sum / counter << std::endl;
		*(array + length / 2) = sum / counter;
		std::cout << "Output array" << std::endl;
		for (int i = 0; i < length; i++)
		{
			std::cout << *(array + i) << "\t";
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Final num not found!" << std::endl;
	}

	delete[] array;
	system("pause");
	return 0;
}