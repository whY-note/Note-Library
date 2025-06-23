/*输入字符串，要求将每个单词的第一个字母改为大写字母，并输出。（不需用函数）
如“hello world！”改为“Hello World!”*/
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