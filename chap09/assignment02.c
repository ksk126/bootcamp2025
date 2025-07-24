/*
* �ۼ���: �����
* ���ϸ�: assignment02
* �ۼ���: 2025.07.17
* ����: �� ���� ���ڿ��� �Է¹޾Ƽ� ���� ����(' ', '\n', '\t', '\f', '\r', '\v')�� ��� �����ϴ� remove_space �Լ���
* �ۼ� �� remove_space �Լ��� �̿��ؼ� �Է¹��� ���ڿ����� ��ĭ�� ��� �����ϰ� ����ϴ� ���α׷�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    char str[1000];
} TEXT;

TEXT scanString(TEXT input);
TEXT remove_space(TEXT input);
void printString(TEXT input);

int main()
{
    TEXT input = { "" };

    input = scanString(input);
    TEXT result = remove_space(input);
    printString(result);

    return 0;
}

TEXT scanString(TEXT input)
{
    printf("���ڿ��� �Է��ϼ���: ");
    scanf(" %[^\n]", input.str);
    return input;
}

TEXT remove_space(TEXT input)
{
    TEXT output = { "" };
    int j = 0;
    for (int i = 0; input.str[i] != '\0'; i++) {
        switch (input.str[i]) {
        case ' ':
        case '\t':
        case '\f':
        case '\r':
        case '\v':
            continue;
        default:
            output.str[j++] = input.str[i];
            break;
        }
    }
    output.str[j] = '\0';
    return output;
}

void printString(TEXT input)
{
    printf("��� ���ڿ�: %s\n", input.str);
    return;
}