/*在主函数中，从键盘上输⼊5个数据到⼀维数组中。
编写函数int max(int *p)，功能为：找出数组中的最⼤值所在的元素下标。
在主函数中调用max函数，并输出数组中的最⼤值所在的元素下标。*/
#include<stdio.h>
int main()
{
	int max(int* p);
	int a[5] = { 0 };
	int i,place;
	for (i = 0; i < 5; i++)
	{
		scanf_s("%d", &a[i]);
	}
	printf("%d", max(a));
	return 0;
}
int max(int* p)
{
	int i,place=0,max=*p;
	for (i=1;i<5;i++)
	{
		if (*(p + i) > max)
		{
			max = *(p + i);
			place = i;
		}
	}
	return (place);
}