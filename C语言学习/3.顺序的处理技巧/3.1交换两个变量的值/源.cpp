#include<stdio.h>
int main()
{
	int a, b,c,d;
	scanf_s("%d%d", &a, &b);
	c = a, d = b;
	printf("initial:a=%d b=%d\ninitial:c=%d d=%d\n", a, b,c,d);
	//��һ������Ҫ��������������������
	a = a + b;
	b = a - b;
	a = a - b;
	printf("later:a=%d b=%d\n", a, b);
	//�����������м����
	int t;
	t = c;
	c = d;
	d = t;
	printf("later:c=%d d=%d\n", c, d);
	return 0;
}
