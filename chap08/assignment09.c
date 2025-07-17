/*
* 작성자: 김수경
* 파일명: assignment09
* 작성일: 2025.07.15
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ROW 4
#define COL 5

void fill2d(int* p, int row, int value);
void print2d(int arr[][COL], int row);
int inputVal();

int main()
{
	int arr[ROW][COL];
	int value = 0;

	value = inputVal();
	fill2d(*arr, ROW, value);
	print2d(arr, ROW);

	return 0;
}

int inputVal()
{
	int val;
	printf("배열의 원소에 저장할 값? ");
	scanf("%d", &val);
	return val;
}

void fill2d(int *p, int row, int value)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < COL; j++, p++)
		{
			*p = value;
		}
	}
	return;
}

void print2d(int arr[][COL], int row)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return;
}
