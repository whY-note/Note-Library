/*有一个已排好序的数组{1,4,6,9,13,16,19,28,40,100}，
要求输入一个数后，按原来排序的规律将它插入数组中。*/
#include<stdio.h>
int main()
{
	int a[11] = { 1,4,6,9,13,16,19,28,40,100 };
	int b[11] = { 0 };
	int i, j,num,p;
	scanf_s("%d", &num);
	if (num > a[9])
	{
		a[11] = num;
		for (i = 0, j = 0; i < 11 && j < 11; i++, j++)
		{
			b[j] = a[i];
		}
	}
	else if (num < a[0])
	{
		b[0] = num;
		for (i = 0, j = 1; i < 10 && j < 11; i++, j++)
		{
			b[j] = a[i];
		}
	}
	else
		for (p = 0; p < 9; p++)
		{
			if (num >= a[p] && num < a[p + 1])
			{
				for (i = 0, j = 0; i <= p; i++, j++)
				{
					b[j] = a[i];
				}
				b[j] = num;
				j = j + 1;
				for ( ; i <10; i++, j++)
				{
					b[j] = a[i];
				}
			}
		}
	for (i = 0; i < 11; i++)
	{
		printf("%d ", b[i]);
	}
	return 0;
}