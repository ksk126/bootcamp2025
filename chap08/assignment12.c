/*
* 작성자: 김수경
* 파일명: assignment12
* 작성일: 2025.07.15
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 10

void scanN(int* search);
int findAll(int* arr, int* idx, int search);
void printArr(int* arr, int size);
void printResult(int* idx, int count);

int main()
{
	int arr[SIZE] = { 12, 45, 62, 12, 99, 83, 23, 12, 72, 37 };
	int idx[SIZE];
	int search, count;

	printArr(arr, SIZE);
	scanN(&search);
	count = findAll(arr, idx, search);
	printResult(idx, count);

	return 0;
}

void scanN(int* search)
{
	printf("\n찾을 값? ");
	scanf("%d", search);
	return;
}

int findAll(int* arr, int* idx, int search)
{
	int i, count = 0;

	for (i = 0; i < SIZE; i++)
	{
		if (arr[i] == search)
		{
			idx[count] = i;
			count++;
		}
	}
	return count;
}

void printArr(int* arr, int size)
{
	int i;
	printf("배열: ");
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}

void printResult(int* idx, int count)
{
	int i;
	printf("찾은 항목은 모두 %d개입니다.\n", count);
	printf("찾은 항목의 인덱스: ");
	for (i = 0; i < count; i++)
	{
		printf("%d ", idx[i]);
	}
	printf("\n");
	return;
}
