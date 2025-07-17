/*
* 작성자: 김수경
* 파일명: assignment12
* 작성일: 2025.07.09
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void years();
int is_leap_year(int year);

int main()
{
	years();

	return 0;
}

void years() {

	printf("2000~2100사이의 윤년\n");

	int i, cnt = 0;
	for (i = 2000; i < 2100; i++)
	{
		if (is_leap_year(i) != 0)
		{
			printf(" %d", i);
			cnt++;
		}
		if (cnt >= 10)
		{
			printf("\n");
			cnt = 0;
		}
	}

	return;
}

int is_leap_year(int year)
{
	if ( year % 4 == 0 && ( year % 400 == 0 || year % 100 != 0 ))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}