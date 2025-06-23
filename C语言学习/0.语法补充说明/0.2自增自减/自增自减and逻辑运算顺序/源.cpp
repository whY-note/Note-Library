#include<stdio.h>
int main()
{
	int a=2, b=3,c,d,a1,b1,t,u,v,x,y,z, x1, y1, z1,s1,s2,p=6,q=6;
	c = a + b;//因为程序是逐行执行的，此行在下两行之前，所以此时a=2,b=3
	a1=++a;//先加1，后赋值
	b1=b++;//先赋值，后加1
	d = a + b;//此行在上两行之前，此时a=3,b=4
	printf("c=%d\n", c);
	printf("d=%d\n", d);
	printf("a1=%d\n", a1);
	printf("b1=%d\n", b1);
	u = 10, v = 20;
	t =!(u++)&&(++v) ;
	x = 10, y = 0;
	z = !(x++) || (y++);
	x1 = 10, y1 = 0;
	z1= !(x1++) || (++y1);
	printf("u=%d\n", u);
	printf("v=%d\n", v);
	printf("t=%d\n", t);
	printf("x=%d\n", x);
	printf("y=%d\n", y);
	printf("z=%d\n", z);
	printf("x1=%d\n", x1);
	printf("y1=%d\n", y1);
	printf("z1=%d\n", z1);
	s1 = (p++) + (p++);
	s2 = (++q) + (++q);
	printf("s1=%d\n", s1);
	printf("s2=%d\n", s2);
	return 0;
}