/*
* 작성자: 김수경
* 파일명: assignment14
* 작성일: 2025.07.09
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct date {
	int year;
	int month;
	int day;
} DATE;

DATE get_date();
void print_date(DATE d);
int check_date(DATE d);
int get_days_of_month(int year, int month);
int is_leap_year(int year);

int main()
{
	DATE d = get_date();

	print_date(d);

	return 0;
}

DATE get_date()
{
	DATE d = { 0 };
	int valid = 0;

	while (valid==0) {
		printf("날짜 (연 월 일)? ");
		scanf("%d %d %d", &d.year, &d.month, &d.day);

		valid = check_date(d);

		if (valid==0)
			printf("잘못 입력하셨습니다. 유효한 날짜를 입력하세요.\n");
	}

	return d;
}

void print_date(DATE d)
{
	printf("입력한 날짜는 %d년 %d월 %d일입니다.\n", d.year, d.month, d.day);
}

int check_date(DATE d)
{
	if (d.month < 1 || d.month > 12)
		return 0;

	if (d.day < 1 || d.day > get_days_of_month(d.year, d.month))
		return 0;

	return 1;
}

int get_days_of_month(int year, int month)
{
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	if (month == 2 && is_leap_year(year))
		return 29;

	return days[month - 1];
}

int is_leap_year(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
