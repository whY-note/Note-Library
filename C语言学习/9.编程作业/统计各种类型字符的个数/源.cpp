/*��һƪ���£�����3�����֣�ÿ��С��80���ַ���
Ҫ��ֱ�ͳ�Ƴ�����Ӣ�Ĵ�д��ĸ��Сд��ĸ�����֡��ո��Լ������ַ��ĸ���*/
#include<stdio.h>
#include<string.h>
int main()
{
	char c[3][80] = { 0 };
	int d=0, x=0, s=0, k=0, q=0;
	int i, j;
	for (i = 0; i < 3; i++)
	{
		gets_s(c[i]);
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; c[i][j]!='\0'; j++)
		{
			if (c[i][j] >= 'A' && c[i][j] <= 'Z')
				d++;
			else if (c[i][j] >= 'a' && c[i][j] <= 'z')
				x++;
			else if (c[i][j] >= '1' && c[i][j] <= '9')
				s++;
			else if (c[i][j] == ' ')
				k++;
			else
				q++;
		}
	}
	printf("��д��ĸ:%d\nСд��ĸ:%d\n����:%d\n�ո�:%d\n�����ַ�:%d\n", d, x, s, k, q);
	return 0;
}