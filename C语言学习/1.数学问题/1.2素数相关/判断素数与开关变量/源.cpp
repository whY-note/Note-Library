#include<stdio.h>
#include<math.h>
int main()
{
	int prime(int n);
	int n,t;
	printf("Please enter a integer number:");
	scanf_s("%d", &n);
	t = prime(n);
	if(t)  //通过t的值来区分不同的情况
		printf("%d is a prime.", n);
	else
		printf("%d is not a prime.", n);
	return 0;
}
int prime(int n)
{
	int i, t = 1;//注意t的作用：t是开关变量
	for (i = 2; i <= sqrt(n); i++)//注意i的范围是[2,sqrt(n)] (两边都是闭区间！！！)
	{
		if (n % i == 0)
		{
			t = 0;
			break;//有无break皆可，有则可以节省时间
		}
	}
	return (t);
}