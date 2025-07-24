/*
* �ۼ���: �����
* ���ϸ�: assignment16
* �ۼ���: 2025.07.17
* ����: ���ͳ� ����Ʈ�� �α����Ϸ��� ����ڷκ��� ���̵�� �н����带 �Է¹޾� �α��� ������ ó���Ϸ��� �Ѵ�.
* ����� 5���� ���̵�� �н����尡 �̹� ��ϵǾ� ���� ��, �Է¹��� ���̵� �ش��ϴ� �н������ ����ڰ� �Է���
* �н����尡 ��ġ�ϸ� �α����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
* ����ڰ� �Է��� ���̵� �������� �ʰų�, ���̵� �ش��ϴ� �н����尡 ��ġ���� ������ ���� �޼��� ��� ��
* ���̵�� �н����带 �ٽ� �Է¹ް� �Ѵ�. 3���� ��õ� �Ŀ��� �ùٸ� ���̵�� �н����带 �Է����� ���ϸ� �α��� ���� ���� �޼����� ����Ѵ�.
* ���̵� ���ڿ� �迭�� �н����� ���ڿ� �迭�� ������� ���ؼ� ����Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    char id[100];
    char pw[100];
} CRED;

CRED scanCred(CRED c);
int checkLogin(const CRED input);
void printResult(const CRED input, int code);

enum {
    LOGIN_OK,
    LOGIN_ID_NOT_FOUND,
    LOGIN_PW_MISMATCH
};

int main()
{
    CRED input = { "", "" };
    int code, attempts = 0;

    do {
        input = scanCred(input);
        code = checkLogin(input);
        printResult(input, code);
        attempts++;
    } while (code != LOGIN_OK && attempts < 3);

    if (code != LOGIN_OK)
        printf("�α��� ����.\n");

    return 0;
}

CRED scanCred(CRED c)
{
    printf("���̵�: ");
    scanf(" %99s", c.id);
    printf("�н�����: ");
    scanf(" %99s", c.pw);
    return c;
}

int checkLogin(const CRED input)
{
    const char* valid_ids[] = {
        "user1", "user2", "admin", "guest", "test"
    };
    const char* valid_pws[] = {
        "pass1", "pass2", "admin123", "guest123", "test123"
    };
    int n = sizeof(valid_ids) / sizeof(valid_ids[0]);

    for (int i = 0; i < n; i++) {
        if (strcmp(input.id, valid_ids[i]) == 0) {
            if (strcmp(input.pw, valid_pws[i]) == 0)
                return LOGIN_OK;
            else
                return LOGIN_PW_MISMATCH;
        }
    }
    return LOGIN_ID_NOT_FOUND;
}

void printResult(const CRED input, int code)
{
    switch (code) {
    case LOGIN_OK:
        printf("�α��� ����!\n");
        break;
    case LOGIN_ID_NOT_FOUND:
        printf("�ش� id�� �����ϴ�.\n");
        break;
    case LOGIN_PW_MISMATCH:
        printf("�н����尡 Ʋ�Ƚ��ϴ�.\n");
        break;
    }
}