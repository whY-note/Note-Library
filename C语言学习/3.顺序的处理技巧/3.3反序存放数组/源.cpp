#include<stdio.h>
int main()
{
	void inv1(int x[], int n);
	void inv2(int *x, int n);
	void inv3(int *x, int n);
	int arr1[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int arr2[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int arr3[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int* parr3;
	int i, j;
	inv1(arr1, 10);
	inv2(arr2, 10);
	parr3 = arr3;
	inv3(parr3, 10);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	for (j = 0; j < 10; j++)
	{
		printf("%d ", arr2[j]);
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *parr3);
		parr3++;
	}
}
void inv1(int x[], int n)//函数inv1：数组名作形参和实参
{
	int i, j,temp;
	int c = (n - 1) / 2;//关键：调换次数！！！注意：“i<=c”可以取等！！！
	for (i = 0,j=n-1; i <=c ; i++,j--)//双变量同时循环。
	{
		temp = x[i];
		x[i] = x[j];
		x[j] = temp;
	}
}
void inv2(int* x, int n)//函数inv2：地址变量作形参，函数名作实参
{
	int temp,*i,*j,*p;
	int c = (n - 1) / 2;
	//以下2行也可以写在for()中第一个;前
	i = x;//赋首元素地址
	j = x + n - 1;//赋末元素地址
	p = x + c;//赋中间元素地址
	for (; i <= p; i++, j--)//循环限制条件：i<=p!!!
	{
		temp = *i;
		*i = *j;
		*j = temp;
	}
}
void inv3(int* x, int n)//函数inv3：地址变量作形参和实参
{
	int temp, * i, * j, * p;
	int c = (n - 1) / 2;
	i = x;
	j = x + n - 1;
	p = x + c;
	for (; i <= p; i++, j--)
	{
		temp = *i;
		*i = *j;
		*j = temp;
	}
}