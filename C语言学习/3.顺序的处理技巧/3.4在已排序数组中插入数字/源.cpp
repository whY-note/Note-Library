#include<stdio.h>
int main()
{
	int a[11] = { 1,4,6,9,13,16,19,28,40,100 };
	int b[11] = { 0 };
	int p, i, j,u,temp1,temp2;
	scanf_s("%d", &p);
	//��һ:����b[ ]�����ã�
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
				for (j = 10; j >= i + 2; j--)//�����ѱ�p������Լ�p��ֵ
				{
					b[j] = a[j - 1];
					b[i + 1] = p;//forѭ��+if��䣬Ϊ�˱�������a[ ]����ֵ��if���жϲ���Ӱ��,��������b[ ]
				}
				for (u = i; u >= 0; u--)//�����ѱ�pС������ֵ
					b[u] = a[u];
				break;//�����ޡ���Ϊa[ ]û�иı䣬���ԡ�if (a[i] <= p && p <= a[i + 1])��ֻ������һ�Σ�֮��Ͳ����㣬�򲻻�����if���ĳ���
			}
		}
	for (i = 0; i <= 10; i++)
	{
		printf("%d ", b[i]);
	}

	//����������temp1��temp2����æת������������b[ ]
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
				for (j = i+1; j <11; j++)//����5�У�important
				{
					temp2 = a[j];
					a[j] = temp1;
					temp1 = temp2;
				}
				break;//һ��Ҫ�С���û�У�������µ�a[ ]�ٴ��жϣ������޷��ﵽԤ�ڽ����
			}
		}
	}
	for (i = 0; i <= 10; i++)
	{
		printf("%d ", a[i]);
	}*/
	return 0;
}