#include<stdio.h>
int main()
{
	void fun(int* p1, int* p2, int* p3);
	int five(int n);
	int a[10],n;
	int num=0,mul=1;
	int* p1=a, * p2=&num, * p3=&mul;//指针p1指向数组a，p2、p3分别指向普通变量num、mul
	for (p1 = a; p1 < (a + 3); p1++)
		scanf_s("%d", p1);
	p1 = a;
	fun(p1, p2, p3);
	printf("%d %d", num, mul);
	return 0;
}
int five(int n)
{
	int t = 0;
	if (n % 5 == 0)
		t = 1;
	return (t);
}
void fun(int* p1, int* p2, int* p3)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (five(*(p1 + i)))
		{
			*(p2) += 1;
			*(p3) = *(p3) * *(p1 + i);
		}
	}
}
