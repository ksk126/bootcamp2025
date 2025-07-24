/*
* �ۼ���: �����
* ���ϸ�: assignment10
* �ۼ���: 2025.07.24
* ����: 4����Ʈ �����͸� 2����Ʈ�� ������ low word�� high word�� �����ؼ� ����Ϸ��� �Ѵ�.
* 4����Ʈ �����͸� 2���� word�� ������ �� �ֵ��� ����ü mydata�� �����Ͻÿ�. ����ü�� ����δ�
* 4����Ʈ �����ͷ� �����ϴ� dword�� 2���� ����� �����ϴ� words�� �����Ѵ�.
* low word, high word ���� �Ű������� ���޹޾� mydata ����ü�� ����� �����ϴ� make_dword �Լ��� �����Ͻÿ�.
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