/*
* 작성자: 김수경
* 파일명: assignment07
* 작성일: 2025.07.14
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 20

int inputValue();
int fill_array(int arr[], int size, int value);
void print_array(int arr[], int size);

int main()
{
	int arr[SIZE] = { 0 };
	int value = 0;

	value = inputValue();
	fill_array(arr, SIZE, value);
	print_array(arr, SIZE);

	return 0;
}

int inputValue()
{
	int val = 0;
	printf("배열의 원소에 저장할 값? ");
	scanf("%d", &val);
	return val;
}

int fill_array(int arr[], int size, int value)
{
	int i;
	for (i = 0; i < size; i++)
	{
		arr[i] = value;
	}
	return 0;
}

void print_array(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}
