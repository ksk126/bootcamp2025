/*
* �ۼ���: �����
* ���ϸ�: assignment06
* �ۼ���: 2025.07.24
* ����: DATE ����ü�� 2���� �Ű������� ���޹޾� ��¥�� ������ ���ϴ� is_same_date �Լ��� �����Ͻÿ�.
DATE ����ü �迭�� �����ؼ� �����Ͽ� �ش��ϴ� ��¥�� �ʱ�ȭ�� ���� �Է¹��� ��¥�� ���������� �˻��ϴ� ���α׷��� �ۼ��Ͻÿ�.
�Է¹��� ��¥�� "0 0 0"�̸� ���α׷��� �����Ѵ�.
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
    printf("��¥(������)? ");
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
        printf("%d/%d/%d�� �������Դϴ�.\n", d->Year, d->Month, d->Day);
    else
        printf("%d/%d/%d�� �������� �ƴմϴ�.\n", d->Year, d->Month, d->Day);
}