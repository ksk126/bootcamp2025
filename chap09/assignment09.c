/*
* �ۼ���: �����
* ���ϸ�: assignment09
* �ۼ���: 2025.07.17
* ����: ���� �̸��� Ȯ���ڸ� �Է����� �޾Ƽ� Ȯ���ڸ� ������ ���ϸ��� ����ϴ� ���α׷�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[1000];
    char ext[100];
    char full[1100];
} FILEINFO;

FILEINFO scanInput(FILEINFO input);
FILEINFO buildFullName(FILEINFO input);
void printResult(FILEINFO input);

int main()
{
    FILEINFO file = { "", "", "" };
    file = scanInput(file);
    file = buildFullName(file);
    printResult(file);
    return 0;
}

FILEINFO scanInput(FILEINFO input)
{
    printf("���ϸ�? ");
    scanf(" %999s", input.name);
    printf("Ȯ����? ");
    scanf(" %99s", input.ext);
    return input;
}

FILEINFO buildFullName(FILEINFO input)
{
    strcpy(input.full, input.name);
    strcat(input.full, ".");
    strcat(input.full, input.ext);
    return input;
}

void printResult(FILEINFO input)
{
    printf("��ü ���ϸ�: %s\n", input.full);
    return;
}