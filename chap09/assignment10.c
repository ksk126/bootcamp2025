/*
* �ۼ���: �����
* ���ϸ�: assignment10
* �ۼ���: 2025.07.17
* ����: �������� �� �̸��� �Է¹޾� �̴ϼ��� ����ϴ� ���α׷�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[1000];
    char initials[1000];
} NAME;

NAME scanName(NAME input);
NAME extractInitials(NAME input);
void printInitials(NAME input);

int main()
{
    NAME input = { "", "" };
    NAME result;

    while (1)
    {
        input = scanName(input);

        if (strcmp(input.name, ".") == 0)
            break;

        result = extractInitials(input);
        printInitials(result);
    }

    return 0;
}

NAME scanName(NAME input)
{
    printf("���� �̸�? ");
    scanf(" %[^\n]", input.name);
    return input;
}

NAME extractInitials(NAME input)
{
    NAME output = { "", "" };
    int i = 0, j = 0;

    while (input.name[i] != '\0') {
        if (i == 0 || input.name[i - 1] == ' ') {
            char c = input.name[i];
            if (c >= 'a' && c <= 'z')
                c = c - 'a' + 'A';
            output.initials[j++] = c;
        }
        i++;
    }
    output.initials[j] = '\0';
    return output;
}

void printInitials(NAME input)
{
    printf("�̴ϼ�: %s\n", input.initials);
    return;
}