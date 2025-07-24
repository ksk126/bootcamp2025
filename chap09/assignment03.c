/*
* �ۼ���: �����
* ���ϸ�: assignment03
* �ۼ���: 2025.07.17
* ����: �Է¹��� ���ڿ��� �ҹ��ڴ� �빮�ڷ�, �빮�ڴ� �ҹ��ڷ� ��ȯ�ϴ� ���α׷�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    char str[1000];
} TEXT;

TEXT scanString(TEXT input);
TEXT convertCase(TEXT input);
void printString(TEXT input);

int main()
{
    TEXT input = { "" };

    input = scanString(input);
    TEXT result = convertCase(input);
    printString(result);

    return 0;
}

TEXT scanString(TEXT input)
{
    printf("���ڿ��� �Է��ϼ���: ");
    scanf(" %[^\n]", input.str);
    return input;
}

TEXT convertCase(TEXT input)
{
    TEXT output = { "" };
    int i = 0;
    while (input.str[i] != '\0') {
        char c = input.str[i];
        if (c >= 'a' && c <= 'z') {
            output.str[i] = c - 'a' + 'A';
        }
        else if (c >= 'A' && c <= 'Z') {
            output.str[i] = c - 'A' + 'a';
        }
        else {
            output.str[i] = c;
        }
        i++;
    }
    output.str[i] = '\0';
    return output;
}

void printString(TEXT input)
{
    printf("��ȯ�� ���ڿ�: %s\n", input.str);
    return;
}