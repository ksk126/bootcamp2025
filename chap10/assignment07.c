/*
* �ۼ���: �����
* ���ϸ�: assignment07
* �ۼ���: 2025.07.24
* ����: ��¥���� ���� 1~12������ ���̴�. 
* ���� ��Ÿ���� ����ü�� ���� ����� �����ϰ�, �� ����ü�� �̿��ϵ��� DATE ����ü�� ���Ǹ� �����Ͻÿ�. 
* ��¥�� "Jan 1 2019" �������� ����ϴ� print_date_eng �Լ��� �����Ͻÿ�. 
* set_as_today �Լ��� print_date_eng �Լ��� �̿��ؼ� ���� ��¥�� ����� ǥ������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
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
void printDateEng(Date d);

int main()
{
    Date today = getToday();
    printDateEng(today);
    return 0;
}

Date getToday()
{
    time_t t = time(NULL);
    struct tm* now = localtime(&t);

    Date d;
    d.year = now->tm_year + 1900;
    d.month = now->tm_mon + 1;
    d.day = now->tm_mday;
    return d;
}

void printDateEng(Date d)
{
    static const char* monthNames[] = {
        "", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    if (d.month < 1 || d.month > 12) {
        printf("Invalid month: %d\n", d.month);
        return;
    }

    printf("%s %d %d\n",
        monthNames[d.month],
        d.day,
        d.year);
}