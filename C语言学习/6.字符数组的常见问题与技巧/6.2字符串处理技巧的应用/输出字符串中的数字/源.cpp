/*����һ���ַ��������к������ֺͷ����֡�
�����е�����������Ϊһ�����������δ����һ�������С�
ͳ�ƹ��ж��ٸ��������������Щ����*/

#include<stdio.h>
int main()
{
	char str[] = "A123x456 17960?302tab5876";
	int i, j = 0;
	int num[10];
	int sum = 0;
	int flag = 1;//���ر������ж��ǲ�������
	for (i = 0; str[i] != 0; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (flag)
			{
				sum = str[i] - '0';
				flag = 0;
			}
			else
			{
				sum = 10 * sum + str[i] - '0';
			}
		}
		else
		{
			if (flag == 0)
			{
				flag = 1;
				num[j] = sum;
				j++;
				sum = 0;//��λ��һ��Ҫ�������
			}
		}
		if (str[i + 1] == '\0' && flag == 0)//��������λ��ĩβ������
		{
			num[j] = sum;
			j++;
		}
	}
	for (i = 0; i < j; i++)
	{
		printf("%d ", num[i]);
	}
	return 0;
}

