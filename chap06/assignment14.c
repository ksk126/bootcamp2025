/*
* �ۼ���: �����
* ���ϸ�: assignment14
* �ۼ���: 2025.07.09
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
		printf("��¥ (�� �� ��)? ");
		scanf("%d %d %d", &d.year, &d.month, &d.day);

		valid = check_date(d);

		if (valid==0)
			printf("�߸� �Է��ϼ̽��ϴ�. ��ȿ�� ��¥�� �Է��ϼ���.\n");
	}

	return d;
}

void print_date(DATE d)
{
	printf("�Է��� ��¥�� %d�� %d�� %d���Դϴ�.\n", d.year, d.month, d.day);
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
