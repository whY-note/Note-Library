/*�����ַ�����Ҫ��ÿ�����ʵĵ�һ����ĸ��Ϊ��д��ĸ����������������ú�����
�硰hello world������Ϊ��Hello World!��*/
#include<stdio.h>
int main()
{
	char s[100] = { 0 };
	int i,flag=0;
	gets_s(s);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			if (flag == 0)
			{
				flag = 1;
				s[i] = s[i] - 32;
			}
		}
		else
		{
			flag = 0;
		}
	}
	printf("%s", s);
	return 0;
}