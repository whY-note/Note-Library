/*输出所有的“水仙花数”，
所谓“水仙花数”是指一个3位数，其各位数字立方和等于该数字本身。*/
#include<stdio.h>
int main()
{
	int n,i,t;
	int a[3] = { 0 };
	for (n = 100; n <= 999; n++)
	{
		t = n;
		for (i = 0; t!=0&&i < 3; i++)
		{
			a[i] = t % 10;
			t = (int)t / 10;
		}
		if (n ==a[0] * a[0] * a[0] + a[1] * a[1] * a[1] + a[2] * a[2] * a[2])
			printf("%d\n", n);
	}
	return 0;
}