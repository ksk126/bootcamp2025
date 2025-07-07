/*
* �ۼ���: �����
* ���ϸ�: assignment10
* �ۼ���: 2025.07.04
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct time {
	int day;
	int hour;
	int minute;
} TIME;

double scanTime();
TIME computeTime(TIME time, double timeF);
void printTime(TIME time);

int main()
{
	double timeF = 0.0;
	TIME time = { 0 };

	timeF = scanTime();
	time= computeTime(time, timeF);
	printTime(time);

	return 0;
}

double scanTime()
{
	double time = 0.0;

	printf("���� �ҿ�ð�(�ð�)? ");
	scanf("%lf", &time);

	return time;
}

TIME computeTime(TIME time, double timeF)
{
	time.day = timeF / 24;
	time.hour = timeF - ((int)time.day*24);
	time.minute = (timeF - time.day * 24 - time.hour) * 60;

	return time;
}

void printTime(TIME time)
{
	printf("���� �ҿ�ð��� %d�� %d�ð� %d���Դϴ�.", time.day, time.hour, time.minute);

	return;
}