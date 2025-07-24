/*
* �ۼ���: �����
* ���ϸ�: assignment02
* �ۼ���: 2025.07.19
* ����: 1�� ���α׷��� ���̵�� �н����带 �׻� �ҹ��ڷθ� �����ϵ��� ó���Ϸ��� �Ѵ�.
* LOGIN ����ü�� �Ű������� ���޹޾� ����ü�� ����� ���̵�� �н����带 ��� �ҹ��ڷ� ����� make_lower �Լ��� 
* ���̵�� �н����带 ����ϴ� print_login �Լ��� �����Ͻÿ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

typedef struct {
    char id[20];
    char pw[20];
} LOGIN;

LOGIN scanLogin(LOGIN data);
LOGIN make_lower(LOGIN data);
void printLogin(LOGIN data);

int main()
{
    LOGIN user = { "", "" };

    user = scanLogin(user);
    user = make_lower(user);
    printLogin(user);

    return 0;
}

LOGIN scanLogin(LOGIN data)
{
    printf("ID? ");
    scanf(" %19s", data.id);

    printf("PW: ");
    scanf(" %19s", data.pw);

    return data;
}

LOGIN make_lower(LOGIN data)
{
    int i;

    for (i = 0; data.id[i] != '\0'; i++)
        data.id[i] = tolower(data.id[i]);

    for (i = 0; data.pw[i] != '\0'; i++)
        data.pw[i] = tolower(data.pw[i]);

    return data;
}

void printLogin(LOGIN data)
{
    int i;

    printf("ID: %s\n", data.id);
    printf("PW: ");
    for (i = 0; data.pw[i] != '\0'; i++)
        printf("*");
    printf("\n");
}