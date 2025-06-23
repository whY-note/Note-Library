/*写一个函数，其功能是：将一个字符串中的元音字母复制到另一个字符串。
在主函数中输入字符串，调用自定义函数，然后在主函数中输出处理后的字符串。
*/
#include<stdio.h>
int main()
{
	void yuan(char x[], char y[]);
	char x[100] = { 0 }, y[100] = { 0 };
	gets_s(x);
	yuan(x, y);
	puts(y);
	return 0;
}
void yuan(char x[], char y[])
{
	int i, j=0;
	for (i = 0; x[i] != '\0'; i++)
	{
		if (x[i] == 'a' ||x[i] == 'A' || x[i] == 'e'|| x[i] == 'E' || x[i] == 'i' || x[i] == 'I' || x[i] == 'o' || x[i] == 'O' || x[i] == 'u' || x[i] == 'U' )
		{
			y[j] = x[i];
			j++;
		}
	}
}