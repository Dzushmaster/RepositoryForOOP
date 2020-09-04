#include <iostream>
#include <ctime>
void Shaker(int*,int);
void Shell(int*,int);
void print(int*);
int Min(int*,int);
#define size 10
int main()
{
	setlocale(LC_CTYPE, "Rus");
	int position = 0;
	srand(time(NULL));
	int ArrA[size];
	int ArrB[size];
	for (int i = 0; i < size; i++)
	{
		ArrA[i] = rand() % 20;
		ArrB[i] = rand() % 20;
	}
	int ArrC[20];
	int min = Min(ArrA,size);
	int sizeC = 0;
	for (int i = 0; i < size; i++)
	{
		if (ArrB[i] > min)
		{
			ArrC[sizeC] = ArrB[i];
			sizeC++;
		}
	}
	for (;;)
	{
		std::cout << "1. Shaker\n2. Shell\n3. Print\n";
		std::cin >> position;
		switch (position)
		{
		case 1:
			Shaker(ArrC,sizeC);
			break;
		case 2:
			Shell(ArrC, sizeC);
			break;
		case 3:
			print(ArrC);
			break;
		}
	}
}
void print(int* ArrC)
{
	int i = 0;
	while (ArrC[i] > 0)
	{
		std::cout << ArrC[i] << ' ';
		i++;
	}
	std::cout << '\n';
}
int Min(int*ArrA,int sizeA)
{
	int min = *ArrA;
	for (int i = 0; i < sizeA; i++)
		if (ArrA[i] < min)
			min = ArrA[i];
	return min;
}
void Shell(int* Arr,int sizeC)
{
	int* ArrC = new int[sizeC];
	for (int i = 0; i < sizeC; i++)
	{
		ArrC[i] = Arr[i];
	}
	int step, i, j, tmp;

	// Выбор шага
	for (step = sizeC / 2; step > 0; step /= 2)// Перечисление элементов, которые сортируются на определённом шаге
		for (i = step; i < sizeC; i++)// Перестановка элементов внутри подсписка, пока i-тый не будет отсортирован
			for (j = i - step; j >= 0 && ArrC[j] > ArrC[j + step]; j -= step)
			{
				tmp = ArrC[j];
				ArrC[j] = ArrC[j + step];
				ArrC[j + step] = tmp;
			}
	std::cout << "Shell's:\n";
	print(ArrC);
	delete[]ArrC;
}
void Shaker(int* ArrC, int sizeC) {
	int left, right, i;
	left = 0;
	right = sizeC - 1;
	while (left <= right) {
		for (i = right; i >= left; i--) {
			if (ArrC[i - 1] > ArrC[i]) {
				std::swap(ArrC[i - 1], ArrC[i]);
			}
		}
		left++;
		for (i = left; i <= right; i++) {
			if (ArrC[i - 1] > ArrC[i]) {
				std::swap(ArrC[i - 1], ArrC[i]);
			}
		}
		right--;
	}
	std::cout << "Shakers:\n";
	print(ArrC);
}