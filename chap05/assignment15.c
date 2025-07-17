/*
* 작성자: 김수경
* 파일명: assignment15
* 작성일: 2025.07.04
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct pay {
	int pay;
	int hour;
	int day;
	int select;
}PAY;

PAY scanPay(PAY p);
int computePay(PAY p);
void printPay(int result);

int main()
{
	PAY p = { 0 };

	p = scanPay(p);

	int result = computePay(p);

	printPay(result);

	return 0;
}

PAY scanPay(PAY p)
{
	printf("시간당 급여? ");
	scanf("%d", &p.pay);
	printf("일일 근무 시간? ");
	scanf("%d", &p.hour);
	printf("한달 근무 일수? ");
	scanf("%d", &p.day);
	printf("세금 적용 여부 0:미적용, 1:4대보험공제(8.41%%), 2:소득세공제(3.3%%)? ");
	scanf("%d", &p.select);

	return p;
}

int computePay(PAY p)
{
	int result = 0;

	switch (p.select)
	{
	case 0:
		result = p.pay * p.hour * p.day;
		break;

	case 1:
		result = (p.pay * p.hour * p.day);
		result -= (int)(result / 100 * 8.41);
		break;
	case 2:
		result = (p.pay * p.hour * p.day);
		result -= (int)(result / 100 * 3.3);
		break;
	}
	
	return result;
}

void printPay(int result)
{
	printf("예상 월급여: %d원", result);
}