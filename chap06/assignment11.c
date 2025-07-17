/*
* �ۼ���: �����
* ���ϸ�: assignment11
* �ۼ���: 2025.07.09
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct calculate {
	double a;
	double b;
	char type;
} CALCULATE;

CALCULATE scanCalculator(CALCULATE c);
double calculator(CALCULATE c);
void printCalculator(double result);

int main()
{
	CALCULATE c = { 0 };
	
	c = scanCalculator(c);

	if (!(c.a == 0 && c.type == '0' && c.b == 0)) {
		double result = calculator(c);
		printCalculator(result);
	}

	return 0;
}

CALCULATE scanCalculator()
{
	CALCULATE c;

	for (;;) {
		printf("���� (0 0 0 �Է� �� ����)? ");
		scanf("%lf %c %lf", &c.a, &c.type, &c.b);

		if (c.a == 0 && c.type == '0' && c.b == 0) {
			break;
		}

		return c;
	}

	return c;
}

double calculator(CALCULATE c)
{
	switch (c.type) {
	case '+':
		return c.a + c.b;
	case '-':
		return c.a - c.b;
	case '*':
		return c.a * c.b;
	case '/':
		if (c.b == 0) {
			printf("����: 0���� ���� �� �����ϴ�.\n");
			return 0;
		}
		return c.a / c.b;
	}
}

void printCalculator(double result)
{
	printf("���: %.2lf\n", result);

	return;
}
