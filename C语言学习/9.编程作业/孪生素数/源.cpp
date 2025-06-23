/*寻找[0,100]区间内所有的孪生素数并输出。
孪生素数是指差为2的两个素数，例如，3和5，5和7。
编写函数int prime(int n)，判断素数。
*/
#include<stdio.h>
int main()
{
	int prime(int n);
	int num;
	for (num = 0; num <= 100; num++)
	{
		if (prime(num))
		{
			if (prime(num + 2))
			{
				printf("%d和%d\n", num, num + 2);
			}
		}
	}
	return 0;
}
int prime(int n)
{
	int i,t=1;
	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			t = 0;
			break;
		}
	}
	return (t);
}