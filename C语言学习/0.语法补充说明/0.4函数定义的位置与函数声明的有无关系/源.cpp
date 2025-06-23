#include<stdio.h>
int max(int x, int y);
int max(int x, int y)
{
	int z;
	z = x > y ? x : y;
	return (z);
}
int main()
{
	//int max(int x, int y);
	int a=2, b=5;
	int c;
	c = max(a, b);
	printf("%d", c);
	return 0;
}
