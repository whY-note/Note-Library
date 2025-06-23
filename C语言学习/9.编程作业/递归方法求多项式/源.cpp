/*采用递归方法求下面多项式： 其中n和x为任意正整数。
在主函数中输入数据并调用函数得到结果。
*/
#include<stdio.h>
int main()
{
	double p(int n, int x);
	int n, x;
	double result;
	scanf_s("%d%d", &n, &x);
	result = p(n, x);
	printf("%.2lf", result);
	return 0;
}
double p(int n, int x)
{
	double re;
	if (n ==0)
	{
		re = 1;
	}
	else if (n == 1)
	{
		re = x;
	}
	else
	{
		re = ((2 * n - 1) * x * p(n - 1, x) - (n - 1) * p(n - 2, x)) / n;
	}
	return (re);
}