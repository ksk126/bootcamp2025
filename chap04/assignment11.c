/*
* 작성자: 김수경
* 파일명: assignment11
* 작성일: 2025.07.04
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct unit {
int price;
int percent;
} UNIT;

UNIT scanDiscount(UNIT discount);
int computeDiscount(UNIT discount);
void printDiscount(UNIT discount, int result);

int main()
{
UNIT discount = { 0 };

discount = scanDiscount(discount);

int result = computeDiscount(discount);

printDiscount(discount, result);

return 0;
}

UNIT scanDiscount(UNIT discount)
{
printf("제품의 가격? ");
scanf("%d", &discount.price);
printf("할인율(%%)? ");
scanf("%d", &discount.percent);

return discount;
}

int computeDiscount(UNIT discount)
{
int result = (int)(discount.price * ((double)discount.percent / 100));

return result;
}

void printDiscount(UNIT discount, int result)
{
printf("할인가: %d (%d원 할인)", discount.price - result, result);

return;
}