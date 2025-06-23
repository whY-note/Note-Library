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
	int i, flag = 1, len = 0, length = 0, n;//flag是开关变量，遇到与ch相同的字符则变成0，未遇到时为1
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
		else//如果字符不是ch对应的字符，则比较当前子字符串与最长子字符串的长度
		{
			flag = 1;
			if (len > length)
				length = len;
			len = 0;
		}
		if (i == n - 1)//如果该字符是整个字符串的最后一位，那么需要另外比较一次当前子字符串与最长子字符串的长度
			if (len > length)
				length = len;
	}
	return (length);//返回最长子字符串的长度
}