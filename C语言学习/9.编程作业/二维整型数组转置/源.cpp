/*写一个函数，使给定的一个3*3的二维整型数组转置，即行列互换。
在main函数中：给定下列数组，调用自定义函数，并在main函数中输出转换后的二维数组。
原数组： 
1 2 3 
3 4 5 
4 5 6
*/
#include<stdio.h>
int main()
{
	void t(int x[][3]);
	int i, j;
	int a[3][3] = { 1,2,3,4,5,6,7,8,9 };
	t(a);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
void t(int x[][3])
{
	int i, j,t;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j <=i; j++)//关键：“j <=i”。若写成“j<3",则会转置两次，相当于没有转置
		{
			t = x[i][j];
			x[i][j] = x[j][i];
			x[j][i] = t;
		}
	}
}