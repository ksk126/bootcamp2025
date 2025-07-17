/*
* 작성자: 김수경
* 파일명: assignment14
* 작성일: 2025.07.04
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
	printf("구간 단속 소요 시간 (분)? ");
	scanf("%lf", &unit.m);
	printf("구간 단속 주행 거리 (km)? ");
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
	printf("평균 속력은 %.1lf km/h입니다. ", result);

	if (result >= 100)
	{
		printf("과속입니다.");
	}

	return;
}