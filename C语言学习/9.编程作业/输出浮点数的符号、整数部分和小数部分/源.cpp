/*��д���򣬴Ӽ�������һ��������0�ĸ�������Ȼ��ֱ��������������ķ��š��������ֺ�С�����֡���������-123.456�����Ӧ���ǣ������и�ʽ�������

Sign:-

Integral part:123

Decimal fraction part:0.456000*/
#include<stdio.h>
#include<math.h>
int main()
{
	double num, xi,n;//���ھ��ȵ����⣬һ��Ҫ��double,������float
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