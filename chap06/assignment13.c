/*
* 작성자: 김수경
* 파일명: assignment13
* 작성일: 2025.07.09
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int scan_year();
void print_year(int year);
int get_days_of_month(int year, int month);

int main()
{
	int year = scan_year();

	print_year(year);

	return 0;
}

int scan_year()
{
	int year = 0;
	printf("연도? ");
	scanf("%d", &year);
	printf("[ %d년 ]\n", year);


	return year;
}

void print_year(int year)
{
	int cnt = 0;

	for (int i = 0; i < 12; i++)
	{
		printf("%3d월: %d일", i + 1, get_days_of_month(year, i));
		cnt++;

		if (cnt > 6) {
			printf("\n");
			cnt = 0;
		}
	}

	return;
}

int get_days_of_month(int year, int month)
{
	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31 };

	if (is_leap_year(year) == 1)
	{
		days[1] += 1;
	}

	return days[month];
}

int is_leap_year(int year)
{
	if (year % 4 == 0 && (year % 400 == 0 || year % 100 != 0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}