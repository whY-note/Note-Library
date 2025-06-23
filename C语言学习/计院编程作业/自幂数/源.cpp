/*“阿姆斯特朗数”（Armstrong number），也称为“自幂数”。
一个n位数是阿姆斯特朗数，如果它等于其各位数字的n次方和。
例如，153是一个3位的阿姆斯特朗数。
请编写一个程序，找出 [0,999] 范围内所有的阿姆斯特朗数，并打印它们。*/

#include<stdio.h>
#include<math.h>

bool isArmstrong(int n);

int main()
{
	for (int i = 0; i < 1000; i++)
	{
		if (isArmstrong(i))
		{
			printf("%d ", i);
		}
	}
	return 0;
}

bool isArmstrong(int n)
{
	int wei = 0;
	if (n < 10) wei = 1;
	else if (n < 100) wei = 2;
	else if (n < 1000) wei = 3;

	int nn = n;
	int n_new = 0;
	while (nn != 0)
	{
		n_new += (int)pow((nn % 10),wei);
		nn /= 10;
	}
	if (n_new == n) return 1;
	else return 0;


}