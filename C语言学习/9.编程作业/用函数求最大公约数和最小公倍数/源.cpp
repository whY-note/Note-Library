/*д2���������ֱ����������������Լ������С������������������������������������������
���������ɼ������롣*/
#include<stdio.h>
int main()
{
	int max_yue(int x, int y);
	int min_bei(int x, int y,int yue);
	int a, b,yue,bei;
	scanf_s("%d%d", &a, &b);
	yue=max_yue(a, b);
	bei=min_bei(a, b,yue);
	printf("%d\n%d\n", yue, bei);
	return 0;
}
int max_yue(int x, int y)
{
	int min,i,yue;
	(x > y) ? (min = y) : (min = x);
	for (i = min; i >= 1; i--)
	{
		if (x % i == 0 && y % i == 0)
		{
			yue = i;
			break;
		}
	}
	return (yue);
}
int min_bei(int x, int y,int yue)
{
	int bei;
	bei = x * y / yue;
	return (bei);
}