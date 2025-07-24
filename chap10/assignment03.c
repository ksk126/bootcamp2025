/*
* 작성자: 김수경
* 파일명: assignment03
* 작성일: 2025.07.19
* 내용: LOGIN 구조체 배열을 이용해서 로그인 과정을 프로그램으로 작성하시오.
* 아이디를 입력받아서 LOGIN 구조체 배열에서 아이디를 찾은 다음 입력받은 패스워드와 등록된 패스워드를 비교해서 같으면 "로그인 성공"이라고 출력한다.
* LOGIN 구조체 배열은 크기가 5인 배열로 선언하고 적당한 값으로 초기화해서 사용한다.
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
        {"가나다", "일이삼사"}
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
            return 1; //성공
        }
    }
    return 0; //실패
}

void printLoginResult(int result)
{
    if (result)
        printf("로그인 성공\n");
    else
        printf("로그인 실패\n");

    return;
}