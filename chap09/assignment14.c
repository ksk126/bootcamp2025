/*
* �ۼ���: �����
* ���ϸ�: assignment14
* �ۼ���: 2025.07.17
* ����: ���ͳ� ����Ʈ�� ȸ�������� �Ϸ��� ����ڷκ��� ���̵� �Է¹޾� ��ȿ�� ���̵����� �˻��ϴ� ���α׷��� �ۼ�.
* ���̵�� �����ڷ� �����ؾ��ϰ�, �����ڿ� ���ڷθ� �����Ǹ� �ּ� 8�ڰ� �Ǿ���Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    char str[1000];
} TEXT;

TEXT scanID(TEXT input);
int checkID(const TEXT input);
void printResult(const TEXT input, int code);

enum {
    ID_OK,
    ID_TOO_SHORT,
    ID_NOT_ALPHA_START,
    ID_INVALID_CHAR
};

int main()
{
    TEXT input = { "" };
    int code;

    do {
        input = scanID(input);
        code = checkID(input);
        printResult(input, code);
    } while (code != ID_OK);

    return 0;
}

TEXT scanID(TEXT input)
{
    printf("���̵� �Է�: ");
    scanf(" %999s", input.str);
    return input;
}

int checkID(const TEXT input)
{
    int len = (int)strlen(input.str);

    if (len < 8)
        return ID_TOO_SHORT;

    if (!isalpha((unsigned char)input.str[0]))
        return ID_NOT_ALPHA_START;

    for (int i = 0; i < len; i++) {
        if (!isalnum((unsigned char)input.str[i]))
            return ID_INVALID_CHAR;
    }

    return ID_OK;
}

void printResult(const TEXT input, int code)
{
    switch (code) {
    case ID_TOO_SHORT:
        printf("ID�� 8�� �̻��̾���մϴ�.\n");
        break;
    case ID_NOT_ALPHA_START:
        printf("ID�� �����ڷ� �����ؾ��մϴ�.\n");
        break;
    case ID_INVALID_CHAR:
        printf("ID�� �����ڿ� ���ڷθ� �����Ǿ�� �մϴ�.\n");
        break;
    case ID_OK:
        printf("%s�� ID�� ����� �� �ֽ��ϴ�.\n", input.str);
        break;
    }
}