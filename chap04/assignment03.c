/*
* �ۼ���: �����
* ���ϸ�: assignment03
* �ۼ���: 2025.07.04
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct unit {
	double g;
	double cm3;
}UNIT;

UNIT scanUnit();
void printDensity(UNIT density);


int main()
{
	UNIT density;

	density = scanUnit();

	printDensity(density);

	return 0;
}

UNIT scanUnit()
{
	UNIT density;

	printf("����(g)? ");
	scanf("%lf", &density.g);
	printf("����(��������Ƽ����)? ");
	scanf("%lf", &density.cm3);

	return density;
}

void printDensity(UNIT density)
{
	double result = (density.g) / (density.cm3);
	printf("�е�: %lf", result);

	return;
}