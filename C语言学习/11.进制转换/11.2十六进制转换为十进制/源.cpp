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
			n = n * 16 + s[i] - '0';//注意要 -'0'
		}
		if (s[i] >= 'a' && s[i] <= 'f')
		{
			n = n * 16 + s[i] - 'a' + 10;//注意:'a'对应10，所以要 - 'a' + 10
		}
		if (s[i] >= 'A' && s[i] <= 'F')
		{
			n = n * 16 + s[i] - 'A' + 10;//注意:'A'对应10，所以要 - 'A' + 10
		}
	}
	return n;
}