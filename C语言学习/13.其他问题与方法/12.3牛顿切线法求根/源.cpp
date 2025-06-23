#include<stdio.h>
#include<math.h>
int main()
{
	double x0, x1, f, f1;
	x1 = 10.0;
	do
	{
		x0 = x1;
		f = 2 * pow(x0, 3) - 4 * pow(x0, 2) + 3 * x0 - 6;//原函数
		f1 = 6 * pow(x0, 2) - 8 * x0 + 3;//一阶导数
		x1 = x0 - f / f1;
	} while (fabs(x0 - x1) >= 1e-6);//检测精度
	printf("%lf\n", x1);
	return 0;
}