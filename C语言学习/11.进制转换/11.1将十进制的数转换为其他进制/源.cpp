#include<stdio.h>
int main()
{
	int each[10] = {0};
	int i, j, number,scale;
	printf("�������ת����ʮ������:");
	scanf_s("%d",&number);
	printf("������Ҫת���ɵĽ���:");
	scanf_s("%d",&scale);
	for (i = 0; i < 10&&number!=0; i++)//����forѭ����ת�����ơ��ؼ���һ��number==0,��Ҫֹͣ
	{
		each[i] = number % scale;//n[i]��ת����ĸ�λ����
		number = (int)number / scale;
	}
	if (scale == 16)//ת����16���ơ���Ϊ�������ĸ������Ҫ��������
	{
		for (j = i - 1; j >= 0; j--)
		{
			if (each[j] < 10)
			{
				printf("%d", each[j]);
			}
			else
			{
				printf("%c", each[j] - 10 + 'A');
			}
		}
	}
	else
	{
		for (j = i - 1; j >= 0; j--)//�ѵ㣺��ĳ��λ�ÿ�ʼ�������
		{
			printf("%d", each[j]);
		}
	}
	return 0;
}