/*求一个3*3的整型矩阵主对角线元素之和 1,2,3 4,5,6 7,8,9*/
#include<stdio.h>
int main()
{
	int a[3][3] = { 1,2,3 ,4,5,6 ,7,8,9 };
	int i, sum=0;
	for (i = 0; i < 3; i++)
	{
		sum = sum + a[i][i];
	}
	printf("%d", sum);
	return 0;
}