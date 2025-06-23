#include<stdio.h>
#include<string.h>
int main()
{
	int alphabetic(char c);
	int longest(char string[]);
	int i;
	char line[100];
	gets_s(line);
	for (i = longest(line); alphabetic(line[i]); i++)//从最长单词的起始位置开始输出，直至字符不是字母
		printf("%c", line[i]);
	return 0;
}
int alphabetic(char c)//判断当前字符是否为字母
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return(0);
}
int longest(char string[])//找最长单词
{
	int len = 0;//len代表当前单词已经累计的字母个数
	int i;
	int lengh = 0;//lengh表示之前的单词中最长的单词
	int flag = 1;//flag为开关变量。flag=1表示单词开始，flag=0表示单词未开始
	int place = 0;//place表示最长单词的起始位置
	int point;//point表示当前单词的起始位置
	for (i = 0; i <=strlen(string); i++)// i <=strlen(string) 这里最好要取等号，否则要另外讨论最长单词在末尾的情况!!!
	{
		if (alphabetic(string[i]))//出现字母
		{
			if (flag)//如果flag=1，单词开始
			{
				point = i;//记下单词首字母的位置
				flag = 0;//令flag=0,表示新的单词未开始，仍是当前的单词
			}
			else//如果flag=0,仍是当前的单词
				len++;//则len+1。从而记下单词的长度
		}
		else//如果不是字母，表明前一个单词结束，则比较当前单词与最长单词的长度
		{
			flag = 1;
			if (len >= lengh)//如果当前的单词比之前最长的单词更长
			{
				place = point;//则记下当前单词的起始位置
				lengh = len;//记下当前单词的长度
				len = 0;//令len=0，然后重新记录新单词的长度!!!
			}
		}
	}
	return (place);//return最长单词的起始位置
}