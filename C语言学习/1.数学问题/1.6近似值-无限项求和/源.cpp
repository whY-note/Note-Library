#include<stdio.h>
#include<math.h>
int main()
{
	double divide_pi_into_4();
	double pi;
	printf("pi=%lf\n", pi= 4 * divide_pi_into_4());
	return 0;
}
double divide_pi_into_4()
{
	double sum = 0.0, n = 1.0, term = 1.0;
	int sign = 1;
	while (fabs(term - 0) >= 1e-6)//用此法来控制精确度
	{
		sum = sum + term;
		sign = (-1) * sign;
		n = n + 2;
		term = sign / n;
	}
	return (sum);
}
