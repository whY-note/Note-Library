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
	mu = n1 * n2 / d1;  //����С������
	printf("The greatest common divisor_1 is %d\n", d1);
	printf("The greatest common divisor_2 is %d\n", d2);
	printf("The greatest common divisor_3 is %d\n", greatest_common_divisor3(n1,n2));
	printf("The greatest common divisor_4 is %d\n", greatest_common_divisor4(n1, n2));
	printf("The least common multiple is %d\n",mu);
	return 0;
}
int greatest_common_divisor1(int x, int y)//�����Լ��(��һ��ö�ٷ�)
{
	int i,min;
	if (x> y)       
		min = y;
	else
		min = x;
	for (i = min; i >= 1; i--)
		if (x % i == 0 && y % i == 0)//�ؼ�
			return (i);               
}
int greatest_common_divisor2(int a, int b)//�����Լ��(������շת�����)
{
	// ����a=b*q+r
	// �� gcd(a, b) = gcd(b, r)
	int t,r;//"r" refers to remainder(����)

	//���ù�a,b�Ĵ�С��ֱ����շת������Ϳ�����
	while ((r = a % b) != 0)//�ؼ�:շת�������
	{
		a = b;
		b = r;
	}
	return (b);
}
int greatest_common_divisor3(int m, int n)//�����Լ��(������շת�����)
{
	if (m < n)//�Ѵ������m,С�ĸ�n
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
	return n;//����m,n�����ԣ���Ϊ��ʱm==n
}
int greatest_common_divisor4(int m, int n)//�����Լ��(���ģ��ݹ鷨)
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
