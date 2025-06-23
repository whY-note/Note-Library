#define _CRT_SECURE_NO_WARNINGS //避免警告strcpy不安全
#include<stdio.h>
#include<string.h>
#define N 6
void sort(int n, char str[][20])//n是数组的行数，数组每一行存放一个字符串
{
	int i, j;
	char s[20] = { 0 };//数组s用来做中间变量
	for (i = 0; i < n-1; i++)//选择排序法，与数值的排序相似
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(str[j], str[i]) < 0)//不同之处1：用strcmp来比较字符串的“大小”
			{
				strcpy(s, str[i]);//不同之处2：用strcpy来对字符串“赋值”
				strcpy(str[i], str[j]);
				strcpy(str[j], s);
			}//str[i], str[j]，s都是指一维数组名，都是代表每行的首元素的地址
		}
	}
}
int main()
{
	void sort(int n, char str[][20]);
	int i, j,n=N;
	char c[N][20] = { 0 };
	printf("Please input N strings:");
	for (i = 0; i < N; i++)
		gets_s(c[i]);//逐行输入字符数组c，每行占一个字符串
	sort(n, c);
	printf("The strings in order is:\n");
	for (j = 0; j < N; j++)
	{
		puts(c[j]);//逐行输出字符数组c
	}
	return 0;
}