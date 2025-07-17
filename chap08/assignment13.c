/*
* 작성자: 김수경
* 파일명: assignment13
* 작성일: 2025.07.15
*/

#include <stdio.h>
#define SIZE 10

void swapArr(int* arr1, int* arr2);
void printArr(int* arr, const char* name);

int main()
{
	int a[SIZE] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
	int b[SIZE] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18 };

	printArr(a, "a");
	printArr(b, "b");

	printf("<< swap_arr 호출 후 >>\n");

	swapArr(a, b);

	printArr(a, "a");
	printArr(b, "b");

	return 0;
}

void swapArr(int* arr1, int* arr2)
{
	int i, temp;

	for (i = 0; i < SIZE; i++)
	{
		temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
	return;
}

void printArr(int* arr, const char* name)
{
	int i;
	printf("%s:", name);
	for (i = 0; i < SIZE; i++)
	{
		printf(" %2d", arr[i]);
	}
	printf("\n");
	return;
}
