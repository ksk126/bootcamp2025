/*
* �ۼ���: �����
* ���ϸ�: assignment05
* �ۼ���: 2025.07.03
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double scanL();
double computeL(double lenth);
void printL(double inch, double cm);

int main()
{
	double inch = 0.0, result = 0.0;

	inch = scanL();

	result = computeL(inch);

	printL(inch, result);

	return 0;
}

double scanL()
{
	int lenth = 0;

	printf("����(inch)? ");
	scanf("%d", &lenth);

	return lenth;
}

double computeL(double lenth)
{
	double result = lenth * 2.54;

	return result;
}

void printL(double inch, double cm)
{
	printf("%lf inch = %lf cm", inch, cm);

	return;
}