/*
* �ۼ���: �����
* ���ϸ�: assignment12
* �ۼ���: 2025.07.17
* ����: �Է¹��� ���ڿ��� ���Ͽ� �̵��� ���� ���� �Է¹޾� �����̳� ���������� ȸ��(rotate)�� �����
* ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ��� "abcdef"�� ���������� 2���� ȸ���ϸ� "efabcd"�� �ȴ�.
* �̵��� ���� ���� ������ ��������, ����� ���������� �̵��Ѵ�. �̵��� ���ڼ��� 0�� �ԷµǸ� ���α׷��� �����Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    char str[1000];
    char result[1000];
} TEXT;

TEXT scanInitial(TEXT input);
int scanShift();
TEXT rotateString(TEXT base, int shift);
void printResult(TEXT output);

int main()
{
    TEXT base = { "", "" };
    base = scanInitial(base);

    int shift;
    while ((shift = scanShift()) != 0)
    {
        TEXT output = rotateString(base, shift);
        printResult(output);
    }

    return 0;
}

TEXT scanInitial(TEXT input)
{
    printf("���ڿ�? ");
    scanf(" %[^\n]", input.str);
    return input;
}

int scanShift()
{
    int s;
    printf("�̵��� ���� ��? ");
    scanf("%d", &s);
    return s;
}

TEXT rotateString(TEXT base, int shift)
{
    int len = strlen(base.str);
    if (len == 0)
    {
        base.result[0] = '\0';
        return base;
    }

    int k = shift % len;
    if (k < 0)
        k = (k + len) % len;

    for (int i = 0; i < len; i++)
    {
        int src = (i - k + len) % len;
        base.result[i] = base.str[src];
    }
    base.result[len] = '\0';

    return base;
}

void printResult(TEXT output)
{
    printf("%s\n", output.result);
    return;
}