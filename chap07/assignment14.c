/*
* 작성자: 김수경
* 파일명: assignment14
* 작성일: 2025.07.14
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void inputArray(int arr[], int size);
void shuffleArray(int arr[], int size);
void printArray(const char* msg, int arr[], int size);

int main()
{
	int arr[SIZE];

	inputArray(arr, SIZE);
	printArray("셔플 전", arr, SIZE);

	shuffleArray(arr, SIZE);
	printArray("셔플 후", arr, SIZE);

	return 0;
}

void inputArray(int arr[], int size)
{
	int i;
	srand((unsigned int)time(0));
	for (i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
	return;
}

void shuffleArray(int arr[], int size)
{
	int i, j, temp;
	if (size > 1)
	{
		for (i = 0; i < size - 1; i++)
		{
			j = i + rand() / (RAND_MAX / (size - i) + 1);
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
	return;
}

void printArray(const char* msg, int arr[], int size)
{
	int i;
	printf("%s:", msg);
	for (i = 0; i < size; i++)
	{
		printf(" %2d", arr[i]);
	}
	printf("\n");
	return;
}
