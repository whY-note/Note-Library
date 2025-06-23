/*写2个函数，分别求两个整数的最大公约数和最小公倍数，用主函数调用这两个函数，并输出结果。
两个整数由键盘输入。*/
#include<stdio.h>
int main()
{
	int max_yue(int x, int y);
	int min_bei(int x, int y,int yue);
	int a, b,yue,bei;
	scanf_s("%d%d", &a, &b);
	yue=max_yue(a, b);
	bei=min_bei(a, b,yue);
	printf("%d\n%d\n", yue, bei);
	return 0;
}
int max_yue(int x, int y)
{
	int min,i,yue;
	(x > y) ? (min = y) : (min = x);
	for (i = min; i >= 1; i--)
	{
		if (x % i == 0 && y % i == 0)
		{
			yue = i;
			break;
		}
	}
	return (yue);
}
int min_bei(int x, int y,int yue)
{
	int bei;
	bei = x * y / yue;
	return (bei);
}