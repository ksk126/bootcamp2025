/*
* �ۼ���: �����
* ���ϸ�: assignment07
* �ۼ���: 2025.07.17
* ����: ��ȭ��ȣ ���ڿ��� �ùٸ� ������ ��ȭ��ȣ���� �˻��ϴ� check_phone_str �Լ��� �ۼ�.
* ��ȭ��ȣ�� "01012345678" �������� �Է¹޴´�. ������"010"�� �����ϴٰ� �����Ѵ�.
* check_phone_str �Լ��� �̿��ؼ� �Էµ� ���ڿ��� �ùٸ� ��ȭ��ȣ ���ڿ����� �˻��ؼ� ����ϴ� ���α׷�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    char str[1000];
} TEXT;

TEXT scanString(TEXT input);
int check_phone_str(TEXT input);
void printResult(int result, TEXT input);

int main()
{
    TEXT input = { "" };

    while (1)
    {
        input = scanString(input);

        if (strcmp(input.str, ".") == 0)
            break;

        int result = check_phone_str(input);

        printResult(result, input);
    }

    return 0;
}

TEXT scanString(TEXT input)
{
    printf("��ȭ��ȣ(.�Է� �� ����)? ");
    scanf(" %s", input.str);
    return input;
}

int check_phone_str(TEXT input)
{

    if (strlen(input.str) != 11)
        return 0;

    if (input.str[0] != '0' || input.str[1] != '1' || input.str[2] != '0')
        return 0;

    for (int i = 0; i < 11; i++) {
        if (!isdigit(input.str[i]))
            return 0;
    }

    return 1;
}

void printResult(int result, TEXT input)
{
    if (result)
        printf("%s�� ��ȿ�� ��ȭ��ȣ�Դϴ�.\n", input.str);
    else
        printf("�߸� �Է��߽��ϴ�. 01012345678 �������� �Է��ϼ���.\n");
    return;
}