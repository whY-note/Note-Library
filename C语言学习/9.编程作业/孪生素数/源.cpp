/*Ѱ��[0,100]���������е����������������
����������ָ��Ϊ2���������������磬3��5��5��7��
��д����int prime(int n)���ж�������
*/
#include<stdio.h>
int main()
{
	int prime(int n);
	int num;
	for (num = 0; num <= 100; num++)
	{
		if (prime(num))
		{
			if (prime(num + 2))
			{
				printf("%d��%d\n", num, num + 2);
			}
		}
	}
	return 0;
}
int prime(int n)
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