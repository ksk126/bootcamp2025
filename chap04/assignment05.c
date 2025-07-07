/*
* 작성자: 김수경
* 파일명: assignment05
* 작성일: 2025.07.04
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct unit {
	int lenth;
	int height;
}UNIT;

UNIT scanVolume(UNIT volume);
double computeVolume(UNIT volume);
void printVolume(double result);

int main()
{
	UNIT volume = { 0 };

	volume = scanVolume(volume);

	double result = computeVolume(volume);

	printVolume(result);

	return 0;
}

UNIT scanVolume(UNIT volume)
{
	printf("반지름의 길이? ");
	scanf("%d", &volume.lenth);
	printf("높이? ");
	scanf("%d", &volume.height);

	return volume;
}

double computeVolume(UNIT volume)
{
	double result = 3.141592 * (volume.lenth * volume.lenth) * volume.height;

	return result;
}

void printVolume(double result)
{
	printf("원기둥의 부피: %lf", result);

	return;
}