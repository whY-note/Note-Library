#include<stdio.h>
int main()
{
	int i, j,k;
	//5.1���ƽ���ı���
	//��һ����������
	for (i = 0; i < 5; i++)
	{
		for (j = 1; j <=i; j++)
		{
			printf(" ");
		}
		for (k = 0; k < 5; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	//���������ַ�����
	char a[] = { "*****" };
	char space = ' ';
	for (i = 0; i < 5; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%c", space);
		}
		printf("%s\n", a);
	}
	//5.2�������
	for (i = 0; i < 7; i++)
	{
		if (i <= 3)//�ֳ��������㣬i<=3���ϲ�
		{
			for (j = 0; j <= 2 - i; j++)
				printf(" ");
			for (k = 1; k <= (2 * i + 1); k++)//k����ÿ�������*���ĸ������ѵ㣺�˹��ҳ�k�Ĺ���
				printf("*");
			printf("\n");
		}
		else//�����i>4&&i<7���²�
		{
			for (j = 0; j < i - 3; j++)
				printf(" ");
			for (k = 1; k <= (13 - 2 * i); k++)//�²�k�Ĺ����ǣ���i�����(6-i)���k��ȡ�����k<=2*(6-i)+1==13-2*i
				printf("*");
			printf("\n");
		}
	}
	//5.3�����������
	//5.3.1�����������*
	int n;
	printf("����������:");
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++)
		{
			putchar(' ');
		}//���ǰ��Ŀո�
		for (k = 1; k <= 2 * i - 1; k++)
		{
			putchar('*');
		}//�������:*
		printf("\n");
	}
	//5.3.2���������������
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++)
		{
			putchar(' ');
		}//���ǰ��Ŀո�
		for (k = 1; k <= 2 * i - 1; k++)
		{
			printf("%d", i);
		}//�������:����
		printf("\n");
	}
	return 0;
}