/*
* �ۼ���: �����
* ���ϸ�: assignment10
* �ۼ���: 2025.07.15
*/

#include <stdio.h>

#define ROW 3
#define COL 9

void addMat(int* x, int* y, int* z);
void printMat(int* mat, int col);
void initMat(int* x, int* y);

int main()
{
	int arr[ROW][COL];
	int* x = arr[0];
	int* y = arr[1];
	int* z = arr[2];

	addMat(x, y);

	printf("x ���:\n");
	printMat(x, COL);

	printf("\ny ���:\n");
	printMat(y, COL);

	addMat(x, y, z);

	printf("\nx + y ���:\n");
	printMat(z, COL);

	return 0;
}

void addMat(int* x, int* y, int* z)
{
	int i;
	for (i = 0; i < COL; i++)
	{
		z[i] = x[i] + y[i];
	}
	return;
}

void printMat(int* mat, int col)
{
	int i;
	for (i = 0; i < col; i++)
	{
		printf(" %2d", mat[i]);
		if (i % 3 == 2)
			printf("\n");
	}
	return;
}

void initMat(int* x, int* y)
{
	int i;
	int x_val = 0, y_val = 9;
	for (i = 0; i < COL; i++)
	{
		x_val += 10;
		x[i] = x_val;
		y[i] = y_val;
		y_val--;
	}
	return;
}
