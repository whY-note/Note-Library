/*键盘输入一个长度为10的int型数组，删除数组中重复出现的数据 
如，原数组是： 1 4 2 3 4 1 2 5 5 9，输出：1 4 2 3 5 9*/
#include<stdio.h>
int main()
{
	int a[10] = { 0 };
	int i,j,t=1;
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &a[i]);
	}
	for (i = 0; i < 10; i++)
	{
		if (a[i] == 0)
		{
			t = 0;
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = i+1; j < 10; j++)
		{
			if (a[i] == a[j])
			{
				a[j] = 0;
			}
		}
	}
	if (t==0)
		printf("0 ");
	for (i = 0; i < 10; i++)
		{
			if (a[i] != 0)
			{
				printf("%d ", a[i]);
			}
		}
	for (i = 0; i < 10; i++)
		{
			if (a[i] != 0)
			{
				printf("%d ", a[i]);
			}
		}
	return 0;
}