/*哥德巴赫猜想：任何一个大于4的偶数都可以表示为两个素数之和。
验证[6,50]之间的偶数
写函数void guest(int n)，找到并输出所有素数对，每个素数对之和均等于偶数n。
编写main函数，遍历[6,50]间所有的偶数，调用guest函数查找并输出素数对。
输出格式如下：
40=3+37 40=11+29 40=17+23（换行）
*/
#include<stdio.h>
int main()
{
	void guest(int n);
	int prime(int n);
	int num;
	for (num = 6; num <= 50; num=num+2)
	{
		guest(num);
		printf("\n");
	}
	return 0;
}
int prime(int n)//prime函数的定义要在guest之前，因为guest函数中调用了prime函数
{
	int i,t=1;
	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			t = 0;
			break;
		}
	}
	return (t);
}
void guest(int n)
{
	int i;
	for (i = 2; i <= n / 2; i++)//注意：“ i <= n / 2”，可以取等！！！
	{
		if (prime(i))
		{
			if (prime(n - i))
			{
				printf("%d=%d+%d ", n, i, n - i);
			}
		}
	}
}