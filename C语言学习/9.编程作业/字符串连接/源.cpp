/*编一程序，将两个字符串连接起来，不要用strcat函数*/
#include<stdio.h>
#include<string.h>
int main()
{
	char a[100] = { 0 }, b[50] = { 0 };
	gets_s(a);
	gets_s(b);
	int i = 0, j = 0;
	while (a[i++]);
	i = i - 1;
	while (a[i++] = b[j++]);
	printf("%s", a);
	//puts(a);
	return 0;
}