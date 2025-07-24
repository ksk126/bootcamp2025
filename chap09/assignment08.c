/*
* �ۼ���: �����
* ���ϸ�: assignment08
* �ۼ���: 2025.07.17
* ����: ���ڿ��� Ű ��(ġȯ�� ������ �̵� �Ÿ�)�� �Է¹޾Ƽ� ������ȣ�� ��ȣȭ�� ���ڿ��� ����ϴ� ���α׷�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    char str[1000];
    int key;
} CIPHER;

CIPHER scanInput(CIPHER input);
CIPHER caesarEncrypt(CIPHER input);
void printResult(CIPHER result);

int main()
{
    CIPHER input = { "", 0 };
    CIPHER result;

    while (1)
    {
        input = scanInput(input);

        if (strcmp(input.str, ".") == 0)
            break;

        result = caesarEncrypt(input);
        printResult(result);
    }

    return 0;
}

CIPHER scanInput(CIPHER input)
{
    printf("���ڿ�? ");
    scanf(" %[^\n]", input.str);

    if (strcmp(input.str, ".") != 0) {

        getchar();

        printf("��ȣ Ű(����)? ");
        scanf("%d", &input.key);

        getchar();
    }

    return input;
}

CIPHER caesarEncrypt(CIPHER input)
{
    CIPHER output = { "", input.key };
    int i = 0;

    while (input.str[i] != '\0') {
        char c = input.str[i];

        if (c >= 'A' && c <= 'Z') {
            output.str[i] = ((c - 'A' + input.key) % 26) + 'A';
        }
        else if (c >= 'a' && c <= 'z') {
            output.str[i] = ((c - 'a' + input.key) % 26) + 'a';
        }
        else {
            output.str[i] = c;
        }

        i++;
    }

    output.str[i] = '\0';
    return output;
}

void printResult(CIPHER result)
{
    printf("��ȣȭ�� ���ڿ�: %s\n", result.str);
    return;
}