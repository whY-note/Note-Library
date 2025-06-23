/*编写程序，从键盘输入一个不等于0的浮点数，然后分别输出这个浮点数的符号、整数部分和小数部分。例如输入-123.456，输出应该是（按下列格式输出）：

Sign:-

Integral part:123

Decimal fraction part:0.456000*/
#include<stdio.h>
#include<math.h>
int main()
{
	double num, xi,n;//由于精度的问题，一定要用double,不能用float
	int zh;
	scanf_s("%lf", &num);
	if (num > 0)
		printf("Sign:+\n");
	else
		printf("Sign:-\n");
	n = fabs(num);
	zh = (int)num;
	xi =n - zh;
	printf("Integral part:%d\nDecimal fraction part:%lf\n", zh,xi);
}