#include<stdio.h>
#include<string.h>
int main()
{
	int search(char* cpSource, char ch);
	char str[100] = { '\0' }, * c, ch;
	int le, i;
	gets_s(str);
	c = str;
	scanf_s("%c", &ch);
	le = search(c, ch);
	for (i = 0; i < le; i++)
	{
		printf("%c", ch);
	}
	return 0;
}
int search(char* cpSource, char ch)
{
	int i, flag = 1, len = 0, length = 0, n;//flag�ǿ��ر�����������ch��ͬ���ַ�����0��δ����ʱΪ1
	n = strlen(cpSource);
	for (i = 0; *cpSource != '\0'; i++, cpSource++)
	{
		if (*cpSource == ch)
		{
			if (flag)
			{
				len = len + 1;
				flag = 0;
			}
			else
				len = len + 1;
		}
		else//����ַ�����ch��Ӧ���ַ�����Ƚϵ�ǰ���ַ���������ַ����ĳ���
		{
			flag = 1;
			if (len > length)
				length = len;
			len = 0;
		}
		if (i == n - 1)//������ַ��������ַ��������һλ����ô��Ҫ����Ƚ�һ�ε�ǰ���ַ���������ַ����ĳ���
			if (len > length)
				length = len;
	}
	return (length);//��������ַ����ĳ���
}