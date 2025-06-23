/*输出一个以下的杨辉三角形，要求输出10行 1 1 1 1 2 1 1 3 3 1 1 4 6 4 1*/
#include<stdio.h>
int main()
{
	int y[10][10] = { 1};
	int i, j;
	for (i = 0; i < 10; i++)
	{
		y[i][0] = 1;
		y[i][i] = 1;
	}
	for (i = 2; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			y[i][j] = y[i - 1][j - 1] + y[i - 1][j];
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (y[i][j] != 0)
			{
				printf("%d ", y[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}