/*
* 작성자: 김수경
* 파일명: assignment18
* 작성일: 2025.07.04
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int scanFee(int time);
int computeFee(int time);
void printFee(int result);

int main()
{
	int time = 1;

	while (time != 0)
	{
		time = scanFee(time);

		int result = computeFee(time);

		printFee(result);
	}

	return 0;
}

int scanFee(int time)
{
	printf("주차 시간(분)? ");
	scanf("%d", &time);

	while (time > 1440)
	{
		printf("주차 시간은 최대 24시간(1440분)을 넘을 수 없습니다.\n");
		printf("주차 시간(분)? ");
		scanf("%d", &time);
	}

	if (time == 0)
	{
		return 0;
	}

	return time;
}

int computeFee(int time)
{
	int fee = 0;

	if (time <= 30)
	{
		fee = 2000;
	}
	else
	{
		time -= 30;
		fee = 2000 + (time / 10) * 1000;
	}
	return fee;
}


void printFee(int result)
{
	printf("주차 요금: %d원\n", result);

	return;
}