/*
* 작성자: 김수경
* 파일명: assignment16
* 작성일: 2025.07.14
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 10

void printArray(int arr[], int size);
int findArray(int key, int arr[], int size);
int inputKey();

int main()
{
	int arr[SIZE] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37 };
	int key = 0;
	int index = 0;

	printArray(arr, SIZE);
	key = inputKey();
	index = findArray(key, arr, SIZE);

	if (index != -1)
	{
		printf("%d는 %d번째 원소입니다.\n", key, index);
	}
	else
	{
		printf("찾으시는 원소가 없습니다.\n");
	}

	return 0;
}

void printArray(int arr[], int size)
{
	int i;
	printf("배열:");
	for (i = 0; i < size; i++)
	{
		printf(" %d", arr[i]);
	}
	printf("\n");
	return;
}

int inputKey()
{
	int key = 0;
	printf("찾을 값? ");
	scanf("%d", &key);
	return key;
}

int findArray(int key, int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (key == arr[i])
		{
			return i;
		}
	}
	return -1;
}
