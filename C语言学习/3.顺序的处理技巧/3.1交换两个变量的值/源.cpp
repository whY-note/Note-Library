#include<stdio.h>
int main()
{
	int a, b,c,d;
	scanf_s("%d%d", &a, &b);
	c = a, d = b;
	printf("initial:a=%d b=%d\ninitial:c=%d d=%d\n", a, b,c,d);
	//法一：不需要引入第三个变量就能完成
	a = a + b;
	b = a - b;
	a = a - b;
	printf("later:a=%d b=%d\n", a, b);
	//法二：引入中间变量
	int t;
	t = c;
	c = d;
	d = t;
	printf("later:c=%d d=%d\n", c, d);
	return 0;
}
