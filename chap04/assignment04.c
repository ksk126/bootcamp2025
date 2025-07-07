/*
* �ۼ���: �����
* ���ϸ�: assignment04
* �ۼ���: 2025.07.04
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct unit {
	int solvent;
	int solute;
}UNIT;

UNIT scanPercent(UNIT percent);
double computePercent(UNIT percent);
void printPercent(double result);

int main()
{
	UNIT percent = { 0 };

	percent=scanPercent(percent);

	double result=computePercent(percent);

	printPercent(result);

	return 0;
}

UNIT scanPercent(UNIT percent)
{
	printf("���(g)? ");
	scanf("%d", &percent.solvent);
	printf("����(g)? ");
	scanf("%d", &percent.solute);

	return percent;
}

double computePercent(UNIT percent)
{
	double result = ((double)percent.solute / (double)(percent.solute + percent.solvent)) * 100;

	return result;
}

void printPercent(double result)
{
	printf("��: %.2lf %", result);

	return;
}