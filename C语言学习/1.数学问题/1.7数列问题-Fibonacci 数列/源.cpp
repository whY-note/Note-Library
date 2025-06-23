#include<stdio.h>
int main()
{
	void f_array(int* f);
	void f_circle(int f1,int f2);
	int f[20] = { 1,1 };
	int f1 = 1, f2 = 1;
	f_array(f);
	f_circle(f1, f2);
	return 0;
}
void f_array(int* f)//利用数组
{
	int i, j;
	for (j = 2; j < 20; j++)
	{
		f[j] = f[j - 1] + f[j - 2];//递推公式
	}
	for (i = 0; i < 20; i++)
	{
		printf("%5d", f[i]);
		if (i % 5 == 4)
			printf("\n");
	}
}
void f_circle(int f1, int f2)//利用循环结构
{
	int i;
	for (i = 1; i <= 10; i++)
	{
		printf("%5d %5d", f1, f2);
		if (i % 2 == 0)
			printf("\n");//控制每输出两次，即每输出4个数字，换行一次
		f1 = f1 + f2;//以下这两行是递推
		f2 = f2 + f1;//
	}
}