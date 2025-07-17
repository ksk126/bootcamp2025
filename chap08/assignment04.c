/*
* 작성자: 김수경
* 파일명: assignment04
* 작성일: 2025.07.15
*/

#include <stdio.h>

#define SIZE 10

void printArray(double* arr, int size);
double calculateSum(double* arr, int size);

int main()
{
	double arr[SIZE] = { 0.10, 2.00, 3.40, 5.20, 4.50, 7.80, 9.70, 1.40, 6.60, 7.20 };
	double* pf = arr;
	double sum = 0.0;

	printArray(pf, SIZE);
	sum = calculateSum(pf, SIZE);

	printf("평균: %lf\n", sum);

	return 0;
}

void printArray(double* arr, int size)
{
	int i;
	printf("배열: ");
	for (i = 0; i < size; i++)
	{
		printf("%.2lf ", *(arr + i));
	}
	printf("\n");
	return;
}

double calculateSum(double* arr, int size)
{
	int i;
	double total = 0.0;

	for (i = 0; i < size; i++)
	{
		total += *(arr + i);
	}

	return total / size;
}
