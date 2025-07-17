/*
* 작성자: 김수경
* 파일명: assignment11
* 작성일: 2025.07.09
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
		printf("수식 (0 0 0 입력 시 종료)? ");
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
			printf("오류: 0으로 나눌 수 없습니다.\n");
			return 0;
		}
		return c.a / c.b;
	}
}

void printCalculator(double result)
{
	printf("결과: %.2lf\n", result);

	return;
}
