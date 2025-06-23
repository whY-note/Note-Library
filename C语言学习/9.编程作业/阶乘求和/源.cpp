/*求1!+2!+…+20!，其中x!=1*2*…*x，表示阶乘。*/
#include<stdio.h>
int main()
{
	unsigned long long int sum=0, mul=1,i,j;
	for (i = 1; i <= 20; i++)
	{
		mul = 1;
		for (j = 1; j <= i; j++)
		{
			mul = mul * j;
		}
		sum = sum + mul;
	}
	printf("%lld", sum);
	return 0;
}