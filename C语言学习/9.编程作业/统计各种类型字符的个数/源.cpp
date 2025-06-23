/*有一篇文章，共有3行文字，每行小于80个字符。
要求分别统计出其中英文大写字母、小写字母、数字、空格以及其他字符的个数*/
#include<stdio.h>
#include<string.h>
int main()
{
	char c[3][80] = { 0 };
	int d=0, x=0, s=0, k=0, q=0;
	int i, j;
	for (i = 0; i < 3; i++)
	{
		gets_s(c[i]);
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; c[i][j]!='\0'; j++)
		{
			if (c[i][j] >= 'A' && c[i][j] <= 'Z')
				d++;
			else if (c[i][j] >= 'a' && c[i][j] <= 'z')
				x++;
			else if (c[i][j] >= '1' && c[i][j] <= '9')
				s++;
			else if (c[i][j] == ' ')
				k++;
			else
				q++;
		}
	}
	printf("大写字母:%d\n小写字母:%d\n数字:%d\n空格:%d\n其他字符:%d\n", d, x, s, k, q);
	return 0;
}