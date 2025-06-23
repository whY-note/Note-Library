#include<stdio.h>
void print1();
void print2();
void print3();
int main()
{
	print1();
	print2();
	print3();
	return 0;
}

void print1()
{//转义字符
	/*输出以下内容：
	"\/"
	%
	"/\"
	*/
	printf("\\/\n");// 2个'\'才可以输出1个'\'
	printf("%%\n"); // 2个'%'才可以输出1个'%'
	printf("/\\\n");// 2个'\'才可以输出1个'\'
}
void print2()
{//各种进制的输出
	int a = 123;
	printf("十进制:%d\n八进制:%o\n十六进制:%x,%X\n", a, a, a, a);
}
void print3()
{//格式化输出
	double x = 12.345678;
	printf("%lf\n", x);
	printf("%.2lf\n", x);

	//格式：m.n 
	//m 表示位宽
	//n 表示保留几位小数
	printf("%9.3lf\n", x);//无'-',右对齐
	printf("%-9.3lf\n", x);//有'-',左对齐
}