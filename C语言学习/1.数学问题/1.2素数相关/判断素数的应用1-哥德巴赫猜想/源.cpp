/*��°ͺղ��룺�κ�һ������4��ż�������Ա�ʾΪ��������֮�͡���֤[6,50]֮���ż��

д����void guest(int n)���ҵ���������������ԣ�ÿ��������֮�;�����ż��n��

��дmain����������[6,50]�����е�ż��������guest�������Ҳ���������ԡ�

	�����ʽ���£�

	40=3+37 40=11+29 40=17+23�����У�*/
#include<stdio.h>
#include<math.h>
int prime(int x)//�ж�����
{
	int t=1, i;
	for (i = 2; i <= sqrt(x); i++)//ע�⡰ i <= sqrt((double)x)����Ҫȡ��
		if (x % i == 0)
			t = 0;
	return (t);
}
void guest(int n)
{
	int j, k;
	for (j = 2; j < n / 2; j++)//���ơ�j<=n/2��,�����ظ������ͬ��������
	{
		if (prime(j))//���j������
		{
			k = n - j;
			if (prime(k))//�����ж�k�ǲ�������
				printf("%d=%d+%d ", n, j, k);//���kҲ�������������
		}
	}
	printf("\n");
}
int main()
{
	int i;
	for (i = 6; i <= 50; i=i+2)//��Ϊ��ż�������ԡ�i=i+2��
	{
		guest(i);
	}
	return 0;
}