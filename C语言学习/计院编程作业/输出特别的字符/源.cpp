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
{//ת���ַ�
	/*����������ݣ�
	"\/"
	%
	"/\"
	*/
	printf("\\/\n");// 2��'\'�ſ������1��'\'
	printf("%%\n"); // 2��'%'�ſ������1��'%'
	printf("/\\\n");// 2��'\'�ſ������1��'\'
}
void print2()
{//���ֽ��Ƶ����
	int a = 123;
	printf("ʮ����:%d\n�˽���:%o\nʮ������:%x,%X\n", a, a, a, a);
}
void print3()
{//��ʽ�����
	double x = 12.345678;
	printf("%lf\n", x);
	printf("%.2lf\n", x);

	//��ʽ��m.n 
	//m ��ʾλ��
	//n ��ʾ������λС��
	printf("%9.3lf\n", x);//��'-',�Ҷ���
	printf("%-9.3lf\n", x);//��'-',�����
}