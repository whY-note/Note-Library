/*���õݹ鷽�����������ʽ�� ����n��xΪ������������
�����������������ݲ����ú����õ������
*/
#include<stdio.h>
int main()
{
	double p(int n, int x);
	int n, x;
	double result;
	scanf_s("%d%d", &n, &x);
	result = p(n, x);
	printf("%.2lf", result);
	return 0;
}
double p(int n, int x)
{
	double re;
	if (n ==0)
	{
		re = 1;
	}
	else if (n == 1)
	{
		re = x;
	}
	else
	{
		re = ((2 * n - 1) * x * p(n - 1, x) - (n - 1) * p(n - 2, x)) / n;
	}
	return (re);
}