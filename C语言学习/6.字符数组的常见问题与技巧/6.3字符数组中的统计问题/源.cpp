#include<stdio.h>
#include<string.h>
int main()
{
	char str[100] = { 0 };
	//一、统计单词个数
	int i, num = 0, word = 0;//word是开关变量，word==0表示当前不是单词，word==1表示当前是单词
	gets_s(str);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			word = 0;
		else //str[i]不是空格
			if (word == 0)/*此时的word是前一次判断后得出的结果，它表示前一个字符是不是空格。
						  如果此判断与else处的判断都成立，则表示前一个字符是空格，当前字符是字母*/
			{
				word = 1;
				num++;
			}
	}
	printf("%d", num);
	//二、统计各类型字符的出现次数
	char c[3][80];
	int i, j, k = 0, d = 0, x = 0, t = 0, s = 0;
	gets_s(c[0]);
	gets_s(c[1]);
	gets_s(c[2]);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; c[i][j] != '\0'; j++)//关键:c[i][j]!='\0',对。j<80，错。！！！
		{
			if (c[i][j] >= 'A' && c[i][j] <= 'Z')//统计大写字母
				d++;
			else if (c[i][j] >= 'a' && c[i][j] <= 'z')//统计小写字母
				x++;
			else if (c[i][j] == ' ')//统计空格
				k++;
			else if (c[i][j] >= '0' && c[i][j] <= '9')//统计数字
				s++;
			else if (c[i][j] != '\0')//统计其他字符
				t++;
		}
	}
	printf("upper case:%d\nlower case:%d\ndigit:%d\nspace:%d\nother:%d\n", d, x, s, k, t);
	return 0;
}