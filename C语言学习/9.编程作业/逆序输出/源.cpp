/*输入一个不多于5位的正整数，
要求:（1）求出它是几位数 
(2)按逆序输出各位数字，例如原数为321，应输出123*/
#include<stdio.h>
int main()
{
	int num,i,x,j;
	int a[5] = { 0 };
	scanf_s("%d", &num);
	x = num;
	for (i = 0; i < 5 && x != 0; i++)
	{
		a[i] = x % 10;
		x = (int)x / 10;
	}
	printf("%d位数字\n", i);
	for (j=0;j<i;j++)
	{
		printf("%d ", a[j]);
	}
	return 0;
}