/*
* �ۼ���: �����
* ���ϸ�: assignment03
* �ۼ���: 2025.07.19
* ����: LOGIN ����ü �迭�� �̿��ؼ� �α��� ������ ���α׷����� �ۼ��Ͻÿ�.
* ���̵� �Է¹޾Ƽ� LOGIN ����ü �迭���� ���̵� ã�� ���� �Է¹��� �н������ ��ϵ� �н����带 ���ؼ� ������ "�α��� ����"�̶�� ����Ѵ�.
* LOGIN ����ü �迭�� ũ�Ⱑ 5�� �迭�� �����ϰ� ������ ������ �ʱ�ȭ�ؼ� ����Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_USERS 5

typedef struct {
    char id[20];
    char pw[20];
} Login;

Login scanLogin(Login input);
int checkLogin(Login input, const Login users[], int size);
void printLoginResult(int result);

int main()
{
    Login users[MAX_USERS] = {
        {"qwer", "1234"},
        {"asdf", "5678"},
        {"qpwoeiru", "zxcv"},
        {"guest", "idontknow"},
        {"������", "���̻��"}
    };

    Login input = { "", "" };
    int result;

    while (1)
    {
        input = scanLogin(input);

        if (strcmp(input.id, ".") == 0)
            break;

        result = checkLogin(input, users, MAX_USERS);
        printLoginResult(result);
    }

    return 0;
}

Login scanLogin(Login input)
{
    printf("ID? ");
    scanf(" %19s", input.id);

    if (strcmp(input.id, ".") != 0) {
        printf("PW: ");
        scanf(" %19s", input.pw);
    }

    return input;
}

int checkLogin(Login input, const Login users[], int size)
{
    for (int i = 0; i < size; i++) {
        if (strcmp(users[i].id, input.id) == 0 &&
            strcmp(users[i].pw, input.pw) == 0)
        {
            return 1; //����
        }
    }
    return 0; //����
}

void printLoginResult(int result)
{
    if (result)
        printf("�α��� ����\n");
    else
        printf("�α��� ����\n");

    return;
}