/*编写函数计算一维实型数组前n个元素的最大值、最小值和平均值。
数组、n、最大值、最小值和平均值均作为函数形参，函数无返回值；
在主函数中输入数据，调用函数得到结果。（要求用指针方法实现）*/
#include<stdio.h>
#define N 10
int main()
{
	void fun(double x[],int n,double* pmax, double* pmin, double* pave);
	double a[N] = { 0 };
	double max, min, ave;
	double* pmax = &max, * pmin = &min, * pave = &ave;
	int n=N,i;
	for (i = 0; i < N; i++)
	{
		scanf_s("%lf", &a[i]);
	}
	fun(a, n, pmax, pmin, pave);
	printf("max=%.2lf\nmin=%.2lf\naverage=%.2lf\n", *pmax, *pmin, *pave);
	return 0;
}
void fun(double x[], int n, double* pmax, double* pmin, double* pave)
{
	int i;
	double sum=0, max=x[0], min=x[0];
	for (i = 0; i < n; i++)
	{
		sum = sum + x[i];
		max = (x[i] > max) ? x[i] : max;
		min = (x[i] < min) ? x[i] : min;
	}
	*pmax = max;
	*pmin = min;
	*pave = sum / n;
}