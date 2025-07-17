/*
* �ۼ���: �����
* ���ϸ�: assignment06
* �ۼ���: 2025.07.15
*/

#include <stdio.h>

#define SIZE 10

void printArr(int *arr, int size);
void minMax(int *arr, int size);

int main()
{
	int arr[SIZE] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37 };

	printArr(arr, SIZE);
	minMax(arr, SIZE);

	return 0;
}

void printArr(int *arr, int size)
{
	int i;
	printf("�迭:");
	for (i = 0; i < size; i++)
	{
		printf(" %d", *(arr + i));
	}
	printf("\n");
	return;
}

void minMax(int* arr, int size)
{
	int i;
	int max = arr[0];
	int min = arr[0];

	for (i = 1; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}

	printf("�ִ밪: %d\n", max);
	printf("�ּҰ�: %d\n", min);
	return;
}
