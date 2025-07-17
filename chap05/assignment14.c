/*
* �ۼ���: �����
* ���ϸ�: assignment14
* �ۼ���: 2025.07.04
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct unit {
	double m;
	double km;
} UNIT;

UNIT scanUnit(UNIT unit);
double computeUnit(UNIT unit);
void printUnit(double result);

int main()
{
	UNIT unit = { 0 };

	unit = scanUnit(unit);

	double result = computeUnit(unit);

	printUnit(result);

	return 0;
}

UNIT scanUnit(UNIT unit)
{
	printf("���� �ܼ� �ҿ� �ð� (��)? ");
	scanf("%lf", &unit.m);
	printf("���� �ܼ� ���� �Ÿ� (km)? ");
	scanf("%lf", &unit.km);

	return unit;
}

double computeUnit(UNIT unit)
{
	double result = (60 / unit.m) * unit.km;

	return result;
}

void printUnit(double result)
{
	printf("��� �ӷ��� %.1lf km/h�Դϴ�. ", result);

	if (result >= 100)
	{
		printf("�����Դϴ�.");
	}

	return;
}