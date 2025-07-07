/*
* �ۼ���: �����
* ���ϸ�: assignment11
* �ۼ���: 2025.07.04
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
printf("��ǰ�� ����? ");
scanf("%d", &discount.price);
printf("������(%%)? ");
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
printf("���ΰ�: %d (%d�� ����)", discount.price - result, result);

return;
}