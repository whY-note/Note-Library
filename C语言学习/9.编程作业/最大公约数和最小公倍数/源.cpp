/*��������������m��n���������Լ������С������*/
#include<stdio.h>
int main()
{
	int m, n,min,yue,bei;
	int i;
	scanf_s("%d%d", &m, &n);
	(m > n) ? (min = n) : (min = m);
	for (i = min; i >= 1; i--)
	{
		if (m % i == 0 && n % i == 0)
		{
			yue = i;
			break;
		}
	}
	bei = m * n / yue;
	printf("���Լ����%d\n��С��������%d\n", yue, bei);
	return 0;
}