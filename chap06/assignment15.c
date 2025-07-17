/*
* 작성자: 김수경
* 파일명: assignment15
* 작성일: 2025.07.09
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int round_pos(int value, int digit);
void print_rounded_values(int value);

int main()
{
	int value = 1357;

	print_rounded_values(value);

	return 0;
}

int round_pos(int value, int digit)
{
	if ((value % digit) >= digit / 2)
		return value - (value % digit) + digit;
	else
		return value - (value % digit);
}

void print_rounded_values(int value)
{
	int i;

	for (i = 1; value >= pow(10, i); i++) {
		int digit = (int)pow(10, i);
		int rounded = round_pos(value, digit);
		printf("%d번째 자리에서 반올림한 결과: %d\n", i, rounded);
	}

	return;
}
