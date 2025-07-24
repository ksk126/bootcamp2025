/*
* �ۼ���: �����
* ���ϸ�: assignment05
* �ۼ���: 2025.07.17
* ����: ��ҹ��ڸ� �������� �ʰ� ���ڿ��� ���ϴ� strcmp_ic �Լ��� �ۼ� ��, strcmp_ic(lhs, rhs) �ռ��� ���ϰ���
* strcmp�� ���������� lhs�� rhs���� ũ�� 0���� ū ��, �� ���ڿ��� ������ 0, lhs�� rhs���� ������ 0���� ���� ����
* �����ϴ� strcmp_ic �Լ��� �̿��ؼ� �Է¹��� �� ���ڿ��� ���ϴ� ���α׷�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    char str[1000];
} TEXT;

TEXT scanString(TEXT input, const char *msg);
int strcmp_ic(TEXT lhs, TEXT rhs);
void printResult(int result, TEXT lhs, TEXT rhs);

int main()
{
    TEXT lhs = { "" };
    TEXT rhs = { "" };
    int result;

    lhs = scanString(lhs, "ù ��° ���ڿ� ? ");
    rhs = scanString(rhs, "�� ��° ���ڿ� ? ");

    result = strcmp_ic(lhs, rhs);

    printResult(result, lhs, rhs);

    return 0;
}

TEXT scanString(TEXT input, const char *msg)
{
    printf("%s", msg);
    scanf(" %[^\n]", input.str);
    return input;
}

int strcmp_ic(TEXT lhs, TEXT rhs)
{
    int i = 0;
    char a, b;

    while (lhs.str[i] != '\0' && rhs.str[i] != '\0') {
        a = lhs.str[i];
        b = rhs.str[i];

        if (a >= 'A' && a <= 'Z') a = a - 'A' + 'a';
        if (b >= 'A' && b <= 'Z') b = b - 'A' + 'a';

        if (a != b) return a - b;
        i++;
    }

    a = lhs.str[i];
    b = rhs.str[i];
    if (a >= 'A' && a <= 'Z') a = a - 'A' + 'a';
    if (b >= 'A' && b <= 'Z') b = b - 'A' + 'a';

    return a - b;
}

void printResult(int result, TEXT lhs, TEXT rhs)
{
    if (result > 0)
    {
        printf("%s�� %s���� Ů�ϴ�.", lhs.str, rhs.str);
    }
    else if (result == 0)
    {
        printf("%s�� %s�� �����ϴ�.", lhs.str, rhs.str);
    }
    else
    {
        printf("%s�� %s���� �۽��ϴ�.", lhs.str, rhs.str);
    }
    return;
}