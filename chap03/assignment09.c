/*
* 작성자: 김수경
* 파일명: assignment09
* 작성일: 2025.07.03
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int scanM();
double computeM(int m);
void printM(int lb, double kg);

int main()
{
	int lb = 0;
	double result = 0.0;

	lb = scanM();

	result = computeM(lb);

	printM(lb, result);

	return 0;
}

int scanM()
{
	int m = 0;

	printf("무게(lb)? ");
	scanf("%d", &m);

	return m;
}

double computeM(int m)
{
	double result = (double)m * 0.45359237;

	return result;
}

void printM(int lb, double kg)
{
	printf("%d lb = %lf kg", lb, kg);

	return;
}