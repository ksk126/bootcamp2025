/*
* 작성자: 김수경
* 파일명: assignment05
* 작성일: 2025.07.15
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 10

void input(int *first, int *diff);
void generate(int *arr, int size, int diff);
void printArray(int *arr, int size);

int main()
{
	int arr[SIZE];
	int first = 0, diff = 0;

	input(&first, &diff);

	arr[0] = first;
	generate(arr, SIZE, diff);
	printArray(arr, SIZE);

	return 0;
}

void input(int *first, int *diff)
{
	printf("첫 번째 항? ");
	scanf("%d", first);

	printf("공차? ");
	scanf("%d", diff);

	return;
}

void generate(int *arr, int size, int diff)
{
	int i;
	for (i = 1; i < size; i++)
	{
		arr[i] = arr[i - 1] + diff;
	}
	return;
}

void printArray(int *arr, int size)
{
	int i;
	printf("등차수열:");
	for (i = 0; i < size; i++)
	{
		printf(" %d", arr[i]);
	}
	printf("\n");
	return;
}
