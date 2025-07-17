/*
* 작성자: 김수경
* 파일명: assignment12
* 작성일: 2025.07.04
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
	printf("원금? ");
	scanf("%d", &m.money);
	printf("연이율 (%%)? ");
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
		printf("%d번째 이자: %.2lf, 원리합계: %.2lf\n", i, interest, money);
	}

	return;
}