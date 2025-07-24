/*
* �ۼ���: �����
* ���ϸ�: assignment05
* �ۼ���: 2025.07.19
* ����: DATE ����ü�� �Ű������� ���޹޾� ��¥�� ���� ��¥�� �����ϴ� set_as_today �Լ��� �����Ͻÿ�.
* �ý����������� ���� ��¥�� �ð��� ���� ���� <time.h>�� time �Լ��� localtime �Լ��� �̿��Ѵ�.
* DATE ����ü�� set_as_today, print_date �Լ��� �̿��ؼ� ���� ��¥�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

Date getToday();
void printDate(Date d);

int main()
{
    Date today = getToday();
    printDate(today);
    return 0;
}

Date getToday()
{
    Date d = { 0, 0, 0 };
    time_t t = time(NULL);
    struct tm* now = localtime(&t);

    d.year = now->tm_year + 1900;
    d.month = now->tm_mon + 1;
    d.day = now->tm_mday;

    return d;
}

void printDate(Date d)
{
    printf("���� ��¥�� %d/%d/%d �Դϴ�.\n", d.year, d.month, d.day);

    return;
}

