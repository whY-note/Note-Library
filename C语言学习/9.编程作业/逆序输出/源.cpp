/*����һ��������5λ����������
Ҫ��:��1��������Ǽ�λ�� 
(2)�����������λ���֣�����ԭ��Ϊ321��Ӧ���123*/
#include<stdio.h>
int main()
{
	int num,i,x,j;
	int a[5] = { 0 };
	scanf_s("%d", &num);
	x = num;
	for (i = 0; i < 5 && x != 0; i++)
	{
		a[i] = x % 10;
		x = (int)x / 10;
	}
	printf("%dλ����\n", i);
	for (j=0;j<i;j++)
	{
		printf("%d ", a[j]);
	}
	return 0;
}