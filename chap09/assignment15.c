/*
* �ۼ���: �����
* ���ϸ�: assignment15
* �ۼ���: 2025.07.17
* ����: ��, ��, �ʿ� �ش��ϴ� ���������� "hh:mm:ss"������ ���ڿ��� ����� �����ϴ� time_to_string �Լ��� �ۼ��Ͻÿ�. time_to_string �Լ�����
* ���ڹ迭�� �迭�� ũ��, ��, ��, �� ���� ���ڷ� �����ؾ��Ѵ�. ���޵� ��, ��, �� ���� �ùٸ� ���� �ƴ� ��� -1�� �����ϰ�
* �ð� ���ڿ��� ������ ��쿡�� ������ ���ڿ��� ���̸� �����ϵ��� �ۼ��Ͻÿ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    int h;
    int m;
    int s;
} TIME;

TIME scanTime(TIME t);
int time_to_string(char* buf, int size, TIME t);
void printResult(int len, const char* buf);

int main()
{
    TIME t = { 0, 0, 0 };
    char timestr[9];
    int len;

    t = scanTime(t);
    len = time_to_string(timestr, sizeof(timestr), t);
    printResult(len, timestr);

    return 0;
}

TIME scanTime(TIME t)
{
    printf("�� �� ��? ");
    scanf("%d %d %d", &t.h, &t.m, &t.s);
    return t;
}

int time_to_string(char* buf, int size, TIME t)
{
    if (t.h < 0 || t.h > 23 ||
        t.m < 0 || t.m > 59 ||
        t.s < 0 || t.s > 59)
    {
        return -1;
    }

    if (size < 9)
        return -1;

    snprintf(buf, size, "%02d:%02d:%02d", t.h, t.m, t.s);
    return (int)strlen(buf);
}

void printResult(int len, const char* buf)
{
    if (len < 0)
        printf("�߸��� �ð��Դϴ�.\n");
    else
        printf("%s\n", buf);
}