/*
* �ۼ���: �����
* ���ϸ�: assignment04
* �ۼ���: 2025.07.17
* ����: ���ڿ��� �������� ����� reverse_string �Լ� �ۼ� ��
* reverse_string �Լ��� �̿��ؼ� �Է¹��� �� ���� ���ڿ��� �������� ����ϴ� ���α׷�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    char str[1000];
} TEXT;

TEXT scanString(TEXT input);
TEXT reverse_string(TEXT input);
void printString(TEXT input);

int main()
{
    TEXT input = { "" };

    input = scanString(input);
    TEXT result = reverse_string(input);
    printString(result);

    return 0;
}

TEXT scanString(TEXT input)
{
    printf("���ڿ��� �Է��ϼ���: ");
    scanf(" %[^\n]", input.str);
    return input;
}

TEXT reverse_string(TEXT input)
{
    TEXT output = { "" };
    int len = 0;
    while (input.str[len] != '\0') {
        len++;
    }
    for (int i = 0; i < len; i++) {
        output.str[i] = input.str[len - 1 - i];
    }
    output.str[len] = '\0';
    return output;
}

void printString(TEXT input)
{
    printf("���� ���ڿ�: %s\n", input.str);
    return;
}