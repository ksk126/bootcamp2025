/*
* �ۼ���: �����
* ���ϸ�: assignment08
* �ۼ���: 2025.07.03
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void scanF();
void printF(float a, float b);

int main()
{
	scanF();

	return 0;
}

void scanF()
{
	double a = 0, b = 0;

	printf("�Ǽ� 2��? ");
	scanf("%lf %lf", &a, &b);

	printF(a, b);

	return;
}

void printF(float a, float b)
{
	printf("%lf + %lf = %lf\n", a, b, a + b);
	printf("%lf - %lf = %lf", a, b, a - b);

	return;
}