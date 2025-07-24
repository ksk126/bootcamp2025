/*
* 작성자: 김수경
* 파일명: assignment05
* 작성일: 2025.07.19
* 내용: DATE 구조체를 매개변수로 전달받아 날짜를 오늘 날짜로 지정하는 set_as_today 함수를 정의하시오.
* 시스템을오부터 현재 날짜와 시간을 구할 때는 <time.h>의 time 함수와 localtime 함수를 이용한다.
* DATE 구조체와 set_as_today, print_date 함수를 이용해서 오늘 날짜를 출력하는 프로그램을 작성하시오.
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
    printf("오늘 날짜는 %d/%d/%d 입니다.\n", d.year, d.month, d.day);

    return;
}

