#include<stdio.h>
#include<math.h>
int main()
{
	int prime(int n);
	int n,t;
	printf("Please enter a integer number:");
	scanf_s("%d", &n);
	t = prime(n);
	if(t)  //ͨ��t��ֵ�����ֲ�ͬ�����
		printf("%d is a prime.", n);
	else
		printf("%d is not a prime.", n);
	return 0;
}
int prime(int n)
{
	int i, t = 1;//ע��t�����ã�t�ǿ��ر���
	for (i = 2; i <= sqrt(n); i++)//ע��i�ķ�Χ��[2,sqrt(n)] (���߶��Ǳ����䣡����)
	{
		if (n % i == 0)
		{
			t = 0;
			break;//����break�Կɣ�������Խ�ʡʱ��
		}
	}
	return (t);
}