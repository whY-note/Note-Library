/*有5个整数，使前面各数顺序向后移m个位置，最后m个数变成最前面m个数，
写一个函数实现以上功能，在主函数中输入5个整数和输出调整后的5个数*/
#include<stdio.h>
int main()
{
	void move(int* arr, int n, int m);
	int a[5] = { 0 };
	int n=5, m,i;
	for (i = 0; i < 5; i++)
	{
		scanf_s("%d", &a[i]);
	}
	scanf_s("%d", &m);
	move(a, n, m);
	for (i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
void move(int* arr, int n, int m)
{
	int x[5] = { 0 };
	int i, j,k;
	for (i = n - m,j=0; i < n; i++,j++)
	{
		x[j] = arr[i];
	}
	for (k = n-m-1; k >=0; k--)//注意：逆序移动！！！
	{
		arr[k + m] = arr[k];
	}
	for (k = 0; k < j; k++)
	{
		arr[k] = x[k];
	}
}