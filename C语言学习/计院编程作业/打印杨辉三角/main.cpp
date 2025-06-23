/*输入：行数 n
输出：杨辉三角。其中，需要打印出类似等腰三角形的样式。
每行各个数字之间用一个空格隔开（不考虑数字位数对齐），
最后一个数后面输出换行符。
例如：
		  1
		 1 1
		1 2 1
*/

#include<stdio.h>
#define N 20

int main()
{
	int n;
	scanf_s("%d", &n);
	int a[N][N];

	for (int i = 0; i < n; i++)
	{
		a[i][0] = 1;
		a[i][i] = 1;
	}

	for (int i = 2; i < n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
	}

	//print
	for (int i = 0; i < n; i++)
	{
		for (int k = 1; k <= n-1-i;k++)
		{
			
			putchar(' ');
		}
		for (int j = 0; j <= i; j++)
		{

			printf("%d ", a[i][j]);
		}
		
		putchar('\n');
	}

	return 0;
}