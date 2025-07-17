/*
* 작성자: 김수경
* 파일명: assignment11
* 작성일: 2025.07.14
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_average(int arr[5][5], int number);
void print_student_scores(int arr[5][5]);
void print_item_average(int arr[5][5]);

int main()
{
	int arr[5][5] = { 0 };

	arr[0][0] = 28, arr[0][1] = 28, arr[0][2] = 26, arr[0][3] = 9;
	arr[1][0] = 30, arr[1][1] = 27, arr[1][2] = 30, arr[1][3] = 10;
	arr[2][0] = 25, arr[2][1] = 26, arr[2][2] = 24, arr[2][3] = 8;
	arr[3][0] = 18, arr[3][1] = 22, arr[3][2] = 22, arr[3][3] = 5;
	arr[4][0] = 24, arr[4][1] = 25, arr[4][2] = 30, arr[4][3] = 10;

	print_student_scores(arr);
	print_item_average(arr);

	return 0;
}

int get_average(int arr[5][5], int number)
{
	int i;
	arr[number][4] = 0;
	for (i = 0; i < 4; i++)
	{
		arr[number][4] += arr[number][i];
	}
	return arr[number][4];
}

void print_student_scores(int arr[5][5])
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("학생 %d번: %5d %5d %5d %5d ==> %2d\n",
			i + 1,
			arr[i][0], arr[i][1], arr[i][2], arr[i][3],
			get_average(arr, i));
	}
	return;
}

void print_item_average(int arr[5][5])
{
	int i;
	float average[4] = { 0.0 };

	for (i = 0; i < 4; i++)
	{
		average[i] = (arr[0][i] + arr[1][i] + arr[2][i] + arr[3][i] + arr[4][i]) / 5.0f;
	}

	printf("항목별 평균: %2.2f %2.2f %2.2f %2.2f\n",
		average[0], average[1], average[2], average[3]);

	return;
}
