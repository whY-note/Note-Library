#include<stdio.h>
int main()
{
	int jin16(char s[]);
	char s[10] = { 0 };
	scanf_s("%s", s,10);
	printf("%d\n",jin16(s));
	return 0;
}
int jin16(char s[])
{
	int i, n=0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			n = n * 16 + s[i] - '0';//ע��Ҫ -'0'
		}
		if (s[i] >= 'a' && s[i] <= 'f')
		{
			n = n * 16 + s[i] - 'a' + 10;//ע��:'a'��Ӧ10������Ҫ - 'a' + 10
		}
		if (s[i] >= 'A' && s[i] <= 'F')
		{
			n = n * 16 + s[i] - 'A' + 10;//ע��:'A'��Ӧ10������Ҫ - 'A' + 10
		}
	}
	return n;
}