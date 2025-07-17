/*
* 작성자: 김수경
* 파일명: assignment16
* 작성일: 2025.07.15
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void printArr(int* arr, int size);
void sortOrder(int* arr, int size);

int main()
{
	srand((unsigned)time(NULL));

	int arr[SIZE], i;

	for (i = 0; i < SIZE; i++)
		arr[i] = rand() % 100;

	printf("정렬 전         : ");
	printArr(arr, SIZE);

	sortOrder(arr, SIZE);

	return 0;
}

void printArr(int* arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%2d ", arr[i]);
	printf("\n");

	return;
}

void sortOrder(int* arr, int size)
{
	int i, j, temp;

	for (i = 0; i < size - 1; i++) {
		for (j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("오름차순 정렬 후: ");
	printArr(arr, size);

	for (i = 0; i < size - 1; i++) {
		for (j = i + 1; j < size; j++) {
			if (arr[i] < arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("내림차순 정렬 후: ");
	printArr(arr, size);

	return;
}