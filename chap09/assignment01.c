/*
* �ۼ���: �����
* ���ϸ�: assignment01
* �ۼ���: 2025.07.17
* ����: �� ���� ���ڿ��� �Է¹޾Ƽ� ���� ����(' ', '\n', '\t', '\f', '\r', '\v')�� ������ ���� ���α׷�.
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
    printf("���ڿ��� �Է��ϼ���: ");
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
    printf("���� ���� ����: %d��\n", result);
    return;
}