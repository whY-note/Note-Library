#include<stdio.h>
int main()
{
	int s1, s2, p = 6, q = 6;
	s1 = (p++) + (p++)+(p++)+ (p++) + (p++);
	s2 = (++q) + (++q)+ (++q)+ (++q) + (++q);
	printf("p=%d\n", p);
	printf("q=%d\n", q);
	printf("s1=%d\n", s1);//��p+p+p+p+p,��ִ��5��p++
	printf("s2=%d\n", s2);//��ִ��5��q++,��q+q+q+q+q
	return 0;
}