/*
* 작성자: 김수경
* 파일명: assignment14
* 작성일: 2025.07.15
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printRand(int* count, int min, int max);

int main()
{
	int count;

	printf("count = ");
	scanf("%d", &count);

	printRand(&count, 1, 10);

	return 0;
}

void printRand(int* count, int min, int max)
{
	int i, j;
	int arr[10];

	srand((unsigned)time(NULL));

	for (i = 0; i < *count; i++)
	{
		for (j = 0; j < max; j++)
		{
			arr[j] = rand() % 100 + min;
			printf("%2d ", arr[j]);
		}
		printf("\n");
	}
	return;
}
