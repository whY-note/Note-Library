/*一个数如果恰好等于它的因子之和，这个数就称为“完数”。
例如，6的因子为1，2，3，且6=1+2+3，因此6是“完数”。
编程找出1000之内的所有完数，按如下格式输出其因子：6 its factors are 1 2 3*/
#include<stdio.h>
int main()
{
	int n, i,j,k,sum=0;
	for (n = 1; n <= 1000; n++)
	{
		sum = 0;//sum在每次循环开始一定要归零（复原）！！！
		for (i = 1; i < n; i++)
		{
			if (n % i == 0)
			{
				sum = sum + i;
			}
		}
		if (n == sum)
		{
			printf("%d its factors are ", n);
			for (i = 1; i < n; i++)
			{
				if (n % i == 0)
				{
					printf("%d ", i);
				}
			}
			printf("\n");
		}
	}
	return 0;
}