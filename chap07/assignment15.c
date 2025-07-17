/*
* 작성자: 김수경
* 파일명: assignment15
* 작성일: 2025.07.14
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 10

void initializeArray(int arr[], int size);
void printArray(int arr[], int size);

int main()
{
	int arr[SIZE];

	initializeArray(arr, SIZE);
	printArray(arr, SIZE);

	return 0;
}

void initializeArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
	return;
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}
