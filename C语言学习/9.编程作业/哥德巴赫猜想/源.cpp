/*��°ͺղ��룺�κ�һ������4��ż�������Ա�ʾΪ��������֮�͡�
��֤[6,50]֮���ż��
д����void guest(int n)���ҵ���������������ԣ�ÿ��������֮�;�����ż��n��
��дmain����������[6,50]�����е�ż��������guest�������Ҳ���������ԡ�
�����ʽ���£�
40=3+37 40=11+29 40=17+23�����У�
*/
#include<stdio.h>
int main()
{
	void guest(int n);
	int prime(int n);
	int num;
	for (num = 6; num <= 50; num=num+2)
	{
		guest(num);
		printf("\n");
	}
	return 0;
}
int prime(int n)//prime�����Ķ���Ҫ��guest֮ǰ����Ϊguest�����е�����prime����
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
void guest(int n)
{
	int i;
	for (i = 2; i <= n / 2; i++)//ע�⣺�� i <= n / 2��������ȡ�ȣ�����
	{
		if (prime(i))
		{
			if (prime(n - i))
			{
				printf("%d=%d+%d ", n, i, n - i);
			}
		}
	}
}