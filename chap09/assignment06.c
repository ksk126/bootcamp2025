/*
* �ۼ���: �����
* ���ϸ�: assignment06
* �ۼ���: 2025.07.17
* ����: �ð� ���ڿ��� ��ȿ�� �ð����� Ȯ���ϴ� check_time_str �Լ��� �ۼ�.
* ���� ��� "120000"�� 12:00:00�� �ش��ϴ� ��ȿ�� �ð����ڿ������� "327892"�� ��ȿ�� �ð� ���ڿ��� �ƴϴ�.
* check_time_str �Լ��� �̿��ؼ� �Էµ� ���ڿ��� �ùٸ� �ð� ���ڿ����� �˻��ؼ� ����ϴ� ���α׷�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    char str[1000];
} TEXT;

TEXT scanString(TEXT input);
int check_time_str(TEXT input);
void printResult(int result, TEXT input);

int main()
{
    TEXT input = { "" };

    while (1)
    {
        input = scanString(input);

        if (strcmp(input.str, ".") == 0)
            break;

        int result = check_time_str(input);

        printResult(result, input);
    }

    return 0;
}

TEXT scanString(TEXT input)
{
    printf("�ð�(.�Է� �� ����)? ");
    scanf(" %s", input.str);
    return input;
}

int check_time_str(TEXT input)
{
    if (strlen(input.str) != 6)
        return 0;

    for (int i = 0; i < 6; i++) {
        if (!isdigit(input.str[i]))
            return 0;
    }

    int hour = (input.str[0] - '0') * 10 + (input.str[1] - '0');
    int minute = (input.str[2] - '0') * 10 + (input.str[3] - '0');
    int second = (input.str[4] - '0') * 10 + (input.str[5] - '0');

    if (hour < 0 || hour > 23) return 0;
    if (minute < 0 || minute > 59) return 0;
    if (second < 0 || second > 59) return 0;

    return 1;
}

void printResult(int result, TEXT input)
{
    if (result)
        printf("%s�� ��ȿ�� �ð��Դϴ�.\n", input.str);
    else
        printf("�߸� �Է��߽��ϴ�. hhmmss�������� �Է��ϼ���.\n");
    return;
}