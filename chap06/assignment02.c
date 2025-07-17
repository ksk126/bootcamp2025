/*
* 작성자: 김수경
* 파일명: assignment02
* 작성일: 2025.07.09
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double get_area_of_square();
void print_area(double lenth);

int main()
{
	double lenth = get_area_of_square();

	print_area(lenth);

	return 0;
}

double get_area_of_square()
{
	double lenth;

	printf("한 변의 길이? ");
	scanf("%lf", &lenth);

	return lenth;
}

void print_area(double lenth)
{
	printf("정사각형의 면적: %lf", lenth*lenth);

	return;
}