#include<stdio.h>
int main()
{
	  //强制类型转换运算符
	   /*注意：“三对应”：
			   1.数据类型的定义
			   2.强制类型转换运算符的选用
			   3.printf所输出的数据类型*/
	double b;//定义b为double型
	int a;//定义a为整型
	b = 10.0;  
	a = (int)b;//选用强制取整运算符
	printf("a=%d\n", a);//输出%d，即输出整数
	printf("a=%lf\n", a);//类型不符，输出0.000000

	b = (double)a;//选用强制转换成double的运算符
	printf("b=%d\n", b);//类型不符，输出0
	printf("b=%lf\n", b);//输出%lf，即输出小数
	return 0;
}