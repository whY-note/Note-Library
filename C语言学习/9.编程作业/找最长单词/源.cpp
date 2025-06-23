/*写一个函数，对于一行字符（含空格），能够找到字符串中最长的单词。
主函数中，输入字符串，调用自定义函数并输出最长的单词。
比如输入：a aa aaa aaaa
输出：aaaa
*/
#include<stdio.h>
int main()
{
	int longest(char str[]);
	char s[100] = { 0 };
	int i;
	gets_s(s);
	for(i =longest(s); s[i] != '\0' && s[i] != ' '; i++)
	{
		printf("%c", s[i]);
	}
	return 0;
}
int longest(char str[])
{
	int place=0,i,flag=0;
	int len=0, max_len =0,max_place=0;
	for (i = 0; str[i] != '\0'; i++)
	{
		place = i;
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))//判断是不是字母
		{
			if (flag == 0)
			{
				flag = 1;
				len++;
			}
			else
				len++;
		}
		else//对于最长子字符串不在最后的情况
		{
			flag = 0;
			(len > max_len) ?(max_len=len,max_place=place-len) :(max_len = max_len);//注意：“max_place=place-len”，因为此时的place是子字符串的后一个非字符
			len = 0;
		}
		if (str[i + 1] == '\0')//对于最长子字符串在最后的情况
		{
			(len > max_len) ? (max_len = len, max_place = place - len+1) : (max_len = max_len);//注意：“max_place = place - len+1”，因为此时的place是子字符串中最后一个字符
		}
	}
	return (max_place);
}