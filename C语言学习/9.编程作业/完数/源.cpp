/*һ�������ǡ�õ�����������֮�ͣ�������ͳ�Ϊ����������
���磬6������Ϊ1��2��3����6=1+2+3�����6�ǡ���������
����ҳ�1000֮�ڵ����������������¸�ʽ��������ӣ�6 its factors are 1 2 3*/
#include<stdio.h>
int main()
{
	int n, i,j,k,sum=0;
	for (n = 1; n <= 1000; n++)
	{
		sum = 0;//sum��ÿ��ѭ����ʼһ��Ҫ���㣨��ԭ��������
		for (i = 1; i < n; i++)
		{
			if (n % i == 0)
			{
				sum = sum + i;
			}
		}
		if (n == sum)
		{
			printf("%d its factors are ", n);
			for (i = 1; i < n; i++)
			{
				if (n % i == 0)
				{
					printf("%d ", i);
				}
			}
			printf("\n");
		}
	}
	return 0;
}