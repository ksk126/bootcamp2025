/*
* 작성자: 김수경
* 파일명: assignment16
* 작성일: 2025.07.17
* 내용: 인터넷 사이트에 로그인하려는 사용자로부터 아이디와 패스워드를 입력받아 로그인 과정을 처리하려고 한다.
* 사용자 5명의 아이디와 패스워드가 이미 등록되어 있을 때, 입력받은 아이디에 해당하는 패스워드와 사용자가 입력한
* 패스워드가 일치하면 로그인을 허용하는 프로그램을 작성하시오.
* 사용자가 입력한 아이디가 존재하지 않거나, 아이디에 해당하는 패스워드가 일치하지 않으면 에러 메세지 출력 후
* 아이디와 패스워드를 다시 입력받게 한다. 3번의 재시도 후에도 올바른 아이디와 패스워드를 입력하지 못하면 로그인 실패 에러 메세지를 출력한다.
* 아이디 문자열 배열과 패스워드 문자열 배열은 마음대로 정해서 사용한다.
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
        printf("로그인 실패.\n");

    return 0;
}

CRED scanCred(CRED c)
{
    printf("아이디: ");
    scanf(" %99s", c.id);
    printf("패스워드: ");
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
        printf("로그인 성공!\n");
        break;
    case LOGIN_ID_NOT_FOUND:
        printf("해당 id가 없습니다.\n");
        break;
    case LOGIN_PW_MISMATCH:
        printf("패스워드가 틀렸습니다.\n");
        break;
    }
}