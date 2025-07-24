/*
* 작성자: 김수경
* 파일명: assignment10
* 작성일: 2025.07.24
* 내용: 4바이트 데이터를 2바이트씩 나눠서 low word와 high word로 구분해서 사용하려고 한다.
* 4바이트 데이터를 2개의 word로 접근할 수 있도록 공용체 mydata를 정의하시오. 공용체의 멤버로는
* 4바이트 데이터로 접근하는 dword와 2개의 워드로 접근하는 words를 선언한다.
* low word, high word 값을 매개변수로 전달받아 mydata 공용체로 만들어 리턴하는 make_dword 함수를 정의하시오.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef union {
    unsigned int dword;
    struct {
        unsigned short lowWord;
        unsigned short highWord;
    } words;
} MyData;

MyData MakeDword(unsigned short low, unsigned short high);

int main(void)
{
    MyData data = MakeDword(0x1234, 0xABCD);

    printf("Low Word:   0x%04X\n", data.words.lowWord);
    printf("High Word:  0x%04x\n", data.words.highWord);
    printf("dword data: %08x\n", data.dword);

    return 0;
}

MyData MakeDword(unsigned short low, unsigned short high)
{
    MyData md;
    md.words.lowWord = low;
    md.words.highWord = high;
    return md;
}