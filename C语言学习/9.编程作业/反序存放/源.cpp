/*写一个函数，使输入的一个字符串按反序存放，在主函数中输入和输出字符串*/
#include<stdio.h>
#include<string.h>
int main()
{
	void inverse(char* p, int len);
	char s[100] = { 0 };
	char* p=s;
	int len;
	gets_s(s);
	len = strlen(s);
	inverse(p, len);
	printf("%s", s);
	return 0;
}
void inverse(char* p, int len)
{
	char* i, * j,t;//注意：这里的t是普通变量，不是地址变量！！！
	for (i = p, j = p + len - 1; i <= p + (len - 1) / 2; i++, j--)
	{
		t = *i;
		*i = *j;
		*j = t;
	}
}