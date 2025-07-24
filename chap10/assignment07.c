/*
* 작성자: 김수경
* 파일명: assignment07
* 작성일: 2025.07.24
* 내용: 날짜에서 월은 1~12사이의 값이다. 
* 월을 나타내는 열거체와 열거 상수를 정의하고, 이 열거체를 이용하도록 DATE 구조체의 정의를 변경하시오. 
* 날짜를 "Jan 1 2019" 형식으로 출력하는 print_date_eng 함수를 정의하시오. 
* set_as_today 함수와 print_date_eng 함수를 이용해서 오늘 날짜를 영어식 표기법으로 출력하는 프로그램을 작성하시오.
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