/*
* �ۼ���: �����
* ���ϸ�: assignment04
* �ۼ���: 2025.07.09
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int discount_price();
int product_price();
void print_price(int price, double discount);

int main()
{
	int discount = 0, price = 0;

	discount = discount_price(price);

	while (1)
	{
		price = product_price();

		if (price == 0)
		{
			return 0;
		}

		print_price(price, discount);
	}

	return 0;
}

int discount_price()
{
	double discount = 0;

	printf("������(%%)? ");
	scanf("%lf", &discount);

	return discount;
}

int product_price()
{
	int price = 0;

	printf("��ǰ�� ����? ");
	scanf("%d", &price);

	return price;
}

void print_price(int price, double discount)
{
	printf("���ΰ�: %.0lf��\n", price * (1 - (discount / 100)));

	return;
}