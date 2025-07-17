/*
* 작성자: 김수경
* 파일명: assignment07
* 작성일: 2025.07.15
*/

#include <stdio.h>

#define SIZE 10

void printArr(double *arr, int size);
void reverse(double *arr, int size);

int main()
{
	double arr[SIZE] = { 1.2, 3.1, 4.3, 4.5, 6.7, 2.3, 8.7, 9.5, 2.3, 5.8 };

	printf("배열:");
	printArr(arr, SIZE);

	reverse(arr, SIZE);

	printf("역순:");
	printArr(arr, SIZE);

	return 0;
}

void printArr(double* arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf(" %.2lf", arr[i]);
	}
	printf("\n");
	return;
}

void reverse(double* arr, int size)
{
	int i;
	double temp;

	for (i = 0; i < size / 2; i++)
	{
		temp = arr[size - 1 - i];
		arr[size - 1 - i] = arr[i];
		arr[i] = temp;
	}
	return;
}
