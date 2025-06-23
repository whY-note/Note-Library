/*输入两个正整数m和n，求其最大公约数和最小公倍数*/
#include<stdio.h>
int main()
{
	int m, n,min,yue,bei;
	int i;
	scanf_s("%d%d", &m, &n);
	(m > n) ? (min = n) : (min = m);
	for (i = min; i >= 1; i--)
	{
		if (m % i == 0 && n % i == 0)
		{
			yue = i;
			break;
		}
	}
	bei = m * n / yue;
	printf("最大公约数：%d\n最小公倍数：%d\n", yue, bei);
	return 0;
}