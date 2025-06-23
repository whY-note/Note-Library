#include<stdio.h>
int main()
{
	int i, j,k;
	//5.1输出平行四边形
	//法一：不用数组
	for (i = 0; i < 5; i++)
	{
		for (j = 1; j <=i; j++)
		{
			printf(" ");
		}
		for (k = 0; k < 5; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	//法二：用字符数组
	char a[] = { "*****" };
	char space = ' ';
	for (i = 0; i < 5; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%c", space);
		}
		printf("%s\n", a);
	}
	//5.2输出菱形
	for (i = 0; i < 7; i++)
	{
		if (i <= 3)//分成上下两层，i<=3是上层
		{
			for (j = 0; j <= 2 - i; j++)
				printf(" ");
			for (k = 1; k <= (2 * i + 1); k++)//k控制每行输出“*”的个数。难点：人工找出k的规律
				printf("*");
			printf("\n");
		}
		else//其余的i>4&&i<7是下层
		{
			for (j = 0; j < i - 3; j++)
				printf(" ");
			for (k = 1; k <= (13 - 2 * i); k++)//下层k的规律是：第i层与第(6-i)层的k相等。所以k<=2*(6-i)+1==13-2*i
				printf("*");
			printf("\n");
		}
	}
	//5.3输出金字塔形
	//5.3.1输出的内容是*
	int n;
	printf("请输入行数:");
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++)
		{
			putchar(' ');
		}//输出前面的空格
		for (k = 1; k <= 2 * i - 1; k++)
		{
			putchar('*');
		}//输出内容:*
		printf("\n");
	}
	//5.3.2输出的内容是数字
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++)
		{
			putchar(' ');
		}//输出前面的空格
		for (k = 1; k <= 2 * i - 1; k++)
		{
			printf("%d", i);
		}//输出内容:数字
		printf("\n");
	}
	return 0;
}