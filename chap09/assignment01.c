/*
* 작성자: 김수경
* 파일명: assignment01
* 작성일: 2025.07.17
* 내용: 한 줄의 문자열을 입력받아서 공백 문자(' ', '\n', '\t', '\f', '\r', '\v')의 개수를 세는 프로그램.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    char str[1000];
    int count;
} SPACE;

SPACE scanString(SPACE input);
int computeSpaces(SPACE input);
void printSpaces(int result);

int main()
{
    SPACE input = { "", 0 };

    input = scanString(input);
    input.count = computeSpaces(input);
    printSpaces(input.count);

    return 0;
}

SPACE scanString(SPACE input)
{
    printf("문자열을 입력하세요: ");
    scanf(" %[^\n]", input.str);
    return input;
}

int computeSpaces(SPACE input)
{
    int result = 0;
    for (int i = 0; input.str[i] != '\0'; i++) {
        switch (input.str[i]) {
        case ' ':
        case '\t':
        case '\f':
        case '\r':
        case '\v':
            result++;
            break;
        default:
            break;
        }
    }
    return result;
}

void printSpaces(int result)
{
    printf("공백 문자 개수: %d개\n", result);
    return;
}