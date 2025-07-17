/*
* 작성자: 김수경
* 파일명: assignment13
* 작성일: 2025.07.14
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 16

void inputImages(unsigned char img1[], unsigned char img2[], int size);
void calculateImage(unsigned char img1[], unsigned char img2[], unsigned char img3[], int size);
void printImages(unsigned char img1[], unsigned char img2[], unsigned char img3[], int size);

int main()
{
	unsigned char image1[SIZE], image2[SIZE], image3[SIZE];

	inputImages(image1, image2, SIZE);
	calculateImage(image1, image2, image3, SIZE);
	printImages(image1, image2, image3, SIZE);

	return 0;
}

void inputImages(unsigned char img1[], unsigned char img2[], int size)
{
	int i;
	srand((unsigned int)time(0));
	for (i = 0; i < size; i++)
	{
		img1[i] = rand() % 256;
		img2[i] = rand() % 256;
	}
	return;
}

void calculateImage(unsigned char img1[], unsigned char img2[], unsigned char img3[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		img3[i] = img1[i] | img2[i];
	}
	return;
}

void printImages(unsigned char img1[], unsigned char img2[], unsigned char img3[], int size)
{
	int i;
	printf("image1:");
	for (i = 0; i < size; i++)
	{
		printf(" %02X", img1[i]);
	}
	printf("\nimage2:");
	for (i = 0; i < size; i++)
	{
		printf(" %02X", img2[i]);
	}
	printf("\nimage3:");
	for (i = 0; i < size; i++)
	{
		printf(" %02X", img3[i]);
	}
	printf("\n");
	return;
}
