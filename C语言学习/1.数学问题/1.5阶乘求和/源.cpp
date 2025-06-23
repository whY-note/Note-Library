#include<stdio.h>
int main()
{
	long long int jiecheng(int n);//利用函数递归调用，求阶乘
	long long int sum1 = 0, sum2=0,n, i, t, mul;
	scanf_s("%lld", &n);
	for (i = 1; i <= n; i++)//一般方法
	{
		for (t = 1, mul = 1; t <= i; t++)
		{
			mul = mul * t;
		}
		sum1 = sum1+ mul;
	}
	printf("%lld\n", sum1);
	for (i = 1; i <= n; i++)
	{
		sum2 = sum2 + jiecheng(i);
	}
	printf("%lld\n", sum2);
	return 0;
}
long long int jiecheng(int x)
{
	long long int mul;
	if (x == 1 || x== 0)
		mul = 1;
	else
		mul = jiecheng(x - 1) * x;
	return (mul);
}
