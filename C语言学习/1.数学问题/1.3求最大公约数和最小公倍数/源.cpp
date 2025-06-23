#include<stdio.h>

int greatest_common_divisor1(int x, int y);
int greatest_common_divisor2(int max, int min);
int greatest_common_divisor3(int m, int n);
int greatest_common_divisor4(int m, int n);

int main()
{
	
	int n1, n2,d1,d2,mu;
	printf("Please enter two integer number:");
	scanf_s("%d%d", &n1, &n2);
	d1=greatest_common_divisor1(n1, n2);
	d2=greatest_common_divisor2(n1, n2);
	mu = n1 * n2 / d1;  //求最小公倍数
	printf("The greatest common divisor_1 is %d\n", d1);
	printf("The greatest common divisor_2 is %d\n", d2);
	printf("The greatest common divisor_3 is %d\n", greatest_common_divisor3(n1,n2));
	printf("The greatest common divisor_4 is %d\n", greatest_common_divisor4(n1, n2));
	printf("The least common multiple is %d\n",mu);
	return 0;
}
int greatest_common_divisor1(int x, int y)//求最大公约数(法一：枚举法)
{
	int i,min;
	if (x> y)       
		min = y;
	else
		min = x;
	for (i = min; i >= 1; i--)
		if (x % i == 0 && y % i == 0)//关键
			return (i);               
}
int greatest_common_divisor2(int a, int b)//求最大公约数(法二：辗转相除法)
{
	// 假设a=b*q+r
	// 则 gcd(a, b) = gcd(b, r)
	int t,r;//"r" refers to remainder(余数)

	//不用管a,b的大小，直接用辗转相除法就可以了
	while ((r = a % b) != 0)//关键:辗转相除法。
	{
		a = b;
		b = r;
	}
	return (b);
}
int greatest_common_divisor3(int m, int n)//求最大公约数(法三：辗转相减法)
{
	if (m < n)//把大的数给m,小的给n
	{
		int t = m;
		m = n;
		n = t;
	}
	while ((m - n) != 0)
	{
		int t = m - n;
		m = n;
		n = t;
	}
	return n;//返回m,n都可以，因为这时m==n
}
int greatest_common_divisor4(int m, int n)//求最大公约数(法四：递归法)
{
	if (m == 0 || n == 0)
	{
		return 0;
	}
	else if(m%n==0)
	{
		return n;
	}
	else
	{
		return greatest_common_divisor3(n, m % n);
	}
}
