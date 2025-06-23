/*哥德巴赫猜想：任何一个大于4的偶数都可以表示为两个素数之和。验证[6,50]之间的偶数

写函数void guest(int n)，找到并输出所有素数对，每个素数对之和均等于偶数n。

编写main函数，遍历[6,50]间所有的偶数，调用guest函数查找并输出素数对。

	输出格式如下：

	40=3+37 40=11+29 40=17+23（换行）*/
#include<stdio.h>
#include<math.h>
int prime(int x)//判断素数
{
	int t=1, i;
	for (i = 2; i <= sqrt(x); i++)//注意“ i <= sqrt((double)x)”，要取等
		if (x % i == 0)
			t = 0;
	return (t);
}
void guest(int n)
{
	int j, k;
	for (j = 2; j < n / 2; j++)//限制“j<=n/2”,避免重复输出相同的素数对
	{
		if (prime(j))//如果j是素数
		{
			k = n - j;
			if (prime(k))//则再判断k是不是素数
				printf("%d=%d+%d ", n, j, k);//如果k也是素数，则输出
		}
	}
	printf("\n");
}
int main()
{
	int i;
	for (i = 6; i <= 50; i=i+2)//因为是偶数，所以“i=i+2”
	{
		guest(i);
	}
	return 0;
}