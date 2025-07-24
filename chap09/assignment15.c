/*
* 작성자: 김수경
* 파일명: assignment15
* 작성일: 2025.07.17
* 내용: 시, 분, 초에 해당하는 정수값으로 "hh:mm:ss"형식의 문자열로 만들어 리턴하는 time_to_string 함수를 작성하시오. time_to_string 함수에는
* 문자배열과 배열의 크기, 시, 분, 초 값을 인자로 전달해야한다. 전달된 시, 분, 초 값이 올바른 값이 아닌 경우 -1을 리턴하고
* 시간 문자열을 생성한 경우에는 생성된 문자열의 길이를 리턴하도록 작성하시오.
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
    printf("시 분 초? ");
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
        printf("잘못된 시간입니다.\n");
    else
        printf("%s\n", buf);
}