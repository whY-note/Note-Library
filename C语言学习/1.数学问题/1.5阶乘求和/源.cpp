#include<stdio.h>
int main()
{
	long long int jiecheng(int n);//���ú����ݹ���ã���׳�
	long long int sum1 = 0, sum2=0,n, i, t, mul;
	scanf_s("%lld", &n);
	for (i = 1; i <= n; i++)//һ�㷽��
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
