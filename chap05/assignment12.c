/*
* �ۼ���: �����
* ���ϸ�: assignment12
* �ۼ���: 2025.07.04
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct money {
	int money;
	double interest;
}MONEY;

MONEY scanMoney(MONEY m);
void printMoney(MONEY m);

int main()
{
	MONEY money = { 0 };

	money = scanMoney(money);

	printMoney(money);

	return 0;

}

MONEY scanMoney(MONEY m)
{
	printf("����? ");
	scanf("%d", &m.money);
	printf("������ (%%)? ");
	scanf("%lf", &m.interest);

	return m;
}

void printMoney(MONEY m)
{
	double money = m.money;
	double rate = m.interest / 100.0;

	for (int i = 1; i <= 10; i++)
	{
		double interest = money * rate;
		money += interest;
		printf("%d��° ����: %.2lf, �����հ�: %.2lf\n", i, interest, money);
	}

	return;
}