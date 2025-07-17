/*
* �ۼ���: �����
* ���ϸ�: assignment08
* �ۼ���: 2025.07.09
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void scanRGB();
void make_rgb(int rgb);
int get_red(int rgb);
int get_green(int rgb);
int get_blue(int rgb);

int rgb = 0;

int main()
{
    scanRGB();
    make_rgb(rgb);
    return 0;
}

void scanRGB()
{
    printf("RGB ����? ");
    scanf("%x", &rgb);
    return;
}

void make_rgb(int rgb)
{
    int r = get_red(rgb);
    int g = get_green(rgb);
    int b = get_blue(rgb);

    printf("RGB %06X�� red: %d, green: %d, blue: %d\n", rgb, r, g, b);
    return;
}

int get_red(int rgb)
{
    return rgb & 0xFF;
}

int get_green(int rgb)
{
    return (rgb >> 8) & 0xFF;
}

int get_blue(int rgb)
{
    return (rgb >> 16) & 0xFF;
}
