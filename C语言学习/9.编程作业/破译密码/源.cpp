/*输入一行电文，已按下面规律译成密码： A->Z a->z B->Y b->y C->X c->x 
即第1个字母变成第26个字母，第i个字母变成第(26-i+1)个字母，非字母字符不变。
要求编程序将密码译回原文，并输出原文。*/
#include<stdio.h>
#include<string.h>
int main()
{
	char y[100] = { 0 }, p[100] = { 0 };
	int i, j;
	gets_s(y);
	for (i = 0; i < 100; i++)
	{
		if (y[i] >= 'A' && y[i] <= 'Z')
		{
			p[i] = 155 - y[i];//注意：要用ASCII码来计算
		}
		if (y[i] >= 'a' && y[i] <= 'z')
		{
			p[i] = 219 - y[i];//注意：要用ASCII码来计算
		}
	}
	printf("%s", p);
	return 0；
}