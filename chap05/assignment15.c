/*
* �ۼ���: �����
* ���ϸ�: assignment15
* �ۼ���: 2025.07.04
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
	printf("�ð��� �޿�? ");
	scanf("%d", &p.pay);
	printf("���� �ٹ� �ð�? ");
	scanf("%d", &p.hour);
	printf("�Ѵ� �ٹ� �ϼ�? ");
	scanf("%d", &p.day);
	printf("���� ���� ���� 0:������, 1:4�뺸�����(8.41%%), 2:�ҵ漼����(3.3%%)? ");
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
	printf("���� ���޿�: %d��", result);
}