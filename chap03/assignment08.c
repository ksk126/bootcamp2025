/*
* 작성자: 김수경
* 파일명: assignment08
* 작성일: 2025.07.03
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int scanL();
double computeL(int lenth);
void printL(int yd, double m);

int main()
{
	int yd = 0;
	double result = 0.0;

	yd = scanL();

	result = computeL(yd);

	printL(yd, result);

	return 0;
}

int scanL()
{
	int lenth = 0;

	printf("길이(yd)? ");
	scanf("%d", &lenth);

	return lenth;
}

double computeL(int lenth)
{
	double result = (double)lenth * 0.9144;

	return result;
}

void printL(int yd, double m)
{
	printf("%d yd = %lf m", yd, m);

	return;
}