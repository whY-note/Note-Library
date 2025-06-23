#include<stdio.h>
int main()
{
	int a[11] = { 1,4,6,9,13,16,19,28,40,100 };
	int b[11] = { 0 };
	int p, i, j,u,temp1,temp2;
	scanf_s("%d", &p);
	//法一:引入b[ ]（更好）
	if (p < a[0])
	{
		for (i = 10; i >= 1; i--)
		{
			b[i] = a[i - 1];
		}
		b[0] = p;
	}
	else if (p > a[9])
	{
		b[10] = p;
		for (i = 9; i >= 0; i--)
		{
			b[i] = a[i];
		}
	}
	else
		for (i = 0; i < 9; i++)
		{
			if (a[i] <= p && p <= a[i + 1])
			{
				for (j = 10; j >= i + 2; j--)//用来把比p大的数以及p赋值
				{
					b[j] = a[j - 1];
					b[i + 1] = p;//for循环+if语句，为了避免后面对a[ ]赋的值对if的判断产生影响,所以引入b[ ]
				}
				for (u = i; u >= 0; u--)//用来把比p小的数赋值
					b[u] = a[u];
				break;//可以无。因为a[ ]没有改变，所以“if (a[i] <= p && p <= a[i + 1])”只会满足一次，之后就不满足，则不会运行if语句的程序。
			}
		}
	for (i = 0; i <= 10; i++)
	{
		printf("%d ", b[i]);
	}

	//法二：利用temp1，temp2来帮忙转换，不用引入b[ ]
	/*if (p > a[9])
	{
		a[10] = p;
	}
	else
	{
		for (i = 0; i < 10; i++)
		{
			if (a[i] > p)
			{
				temp1 = a[i];
				a[i] = p;
				for (j = i+1; j <11; j++)//下面5行：important
				{
					temp2 = a[j];
					a[j] = temp1;
					temp1 = temp2;
				}
				break;//一定要有。若没有，则会用新的a[ ]再次判断，导致无法达到预期结果。
			}
		}
	}
	for (i = 0; i <= 10; i++)
	{
		printf("%d ", a[i]);
	}*/
	return 0;
}