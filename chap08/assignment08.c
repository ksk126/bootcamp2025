/*
* 작성자: 김수경
* 파일명: assignment08
* 작성일: 2025.07.15
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 20

void fill(int* arr, int value);
void printArr(int* arr, int size);
int inputVal();

int main()
{
	int arr[SIZE];
	int value = 0;

	value = inputVal();
	fill(arr, value);

	printf("배열:");
	printArr(arr, SIZE);

	return 0;
}

int inputVal()
{
	int val;
	printf("배열의 원소에 저장할 값? ");
	scanf("%d", &val);
	return val;
}

void fill(int *arr, int value)
{
	int i;
	for (i = 0; i < SIZE; i++, arr++)
	{
		*arr = value;
	}
	return;
}

void printArr(int* arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf(" %d", arr[i]);
	}
	printf("\n");
	return;
}
