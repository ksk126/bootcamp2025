/*
* 작성자: 김수경
* 파일명: assignment06
* 작성일: 2025.07.24
* 내용: DATE 구조체를 2개를 매개변수로 전달받아 날짜가 같은지 비교하는 is_same_date 함수를 정의하시오.
DATE 구조체 배열을 선언해서 공휴일에 해당하는 날짜로 초기화한 다음 입력받은 날짜가 공휴일인지 검사하는 프로그램을 작성하시오.
입력받은 날짜가 "0 0 0"이면 프로그램을 종료한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int Year;
    int Month;
    int Day;
} Date;

void    RunHolidayChecker(void);
Date    InputDate(void);
bool    IsHoliday(const Date* d, const Date holidays[], size_t count);
void    PrintHolidayMessage(const Date* d, bool isHoliday);

int main(void)
{
    RunHolidayChecker();
    return 0;
}

void RunHolidayChecker(void)
{
    static const Date holidays[] = {
        {2020,  1,  1}, {2020,  1, 24}, {2020,  1, 25},
        {2020,  1, 26}, {2020,  1, 27}, {2020,  3,  1},
        {2020,  4, 15}, {2020,  4, 30}, {2020,  5,  5},
        {2020,  6,  6}, {2020,  8, 15}, {2020,  9, 30},
        {2020, 10,  1}, {2020, 10,  2}, {2020, 10,  3},
        {2020, 10,  9}, {2020, 12, 25}
    };
    const size_t holidayCount = sizeof holidays / sizeof holidays[0];

    while (1)
    {
        Date d = InputDate();
        if (d.Year == 0 && d.Month == 0 && d.Day == 0)
            break;

        bool holiday = IsHoliday(&d, holidays, holidayCount);
        PrintHolidayMessage(&d, holiday);
    }
}

Date InputDate(void)
{
    Date d;
    printf("날짜(연월일)? ");
    scanf("%d %d %d", &d.Year, &d.Month, &d.Day);
    return d;
}

bool IsHoliday(const Date* d, const Date holidays[], size_t count)
{
    for (size_t i = 0; i < count; i++)
        if (d->Year == holidays[i].Year &&
            d->Month == holidays[i].Month &&
            d->Day == holidays[i].Day)
            return true;
    return false;
}

void PrintHolidayMessage(const Date* d, bool isHoliday)
{
    if (isHoliday)
        printf("%d/%d/%d은 공휴일입니다.\n", d->Year, d->Month, d->Day);
    else
        printf("%d/%d/%d은 공휴일이 아닙니다.\n", d->Year, d->Month, d->Day);
}