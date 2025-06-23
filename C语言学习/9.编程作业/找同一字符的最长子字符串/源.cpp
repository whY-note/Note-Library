/*编写函数intsearch(char *cpSource, char ch)，
该函数在一个字符串中找到可能的最长的子字符串，该字符串是由同一字符组成的。
从主函数中输入"aabbcccddddeeeeeffffff"和'e'，调用函数得到结果。
*/
#include<stdio.h>
int main()
{
	int search(char* cpSource, char ch);
	char s[100] = { 0 };
	char c;
	int len,i;
	gets_s(s);
	scanf_s("%c", &c);
	len=search(s, c);
	for (i = 0; i < len;i++)
	{
		printf("%c", c);
	}
	return 0;
}
int search(char* cpSource, char ch)
{
	int len = 0, flag = 0,ml=0,i;
	for (i = 0; cpSource[i] != '\0'; i++)
	{
		if (cpSource[i] == ch)
		{
			if (flag == 0)
			{
				flag = 1;
				len++;
			}
			else
				len++;
		}
		else
		{
			flag = 0;
			(len > ml) ? (ml = len) : (ml = ml);
			len = 0;
		}
		if (cpSource[i + 1] == '\0')
		{
			(len > ml) ? (ml = len) : (ml = ml);
		}
	}
	return(ml);
}