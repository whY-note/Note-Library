#include<stdio.h>
int main()
{
	int each[10] = {0};
	int i, j, number,scale;
	printf("请输入待转换的十进制数:");
	scanf_s("%d",&number);
	printf("请输入要转换成的进制:");
	scanf_s("%d",&scale);
	for (i = 0; i < 10&&number!=0; i++)//利用for循环来转换进制。关键：一旦number==0,则要停止
	{
		each[i] = number % scale;//n[i]是转换后的各位数字
		number = (int)number / scale;
	}
	if (scale == 16)//转换成16进制。因为会输出字母，所以要单独讨论
	{
		for (j = i - 1; j >= 0; j--)
		{
			if (each[j] < 10)
			{
				printf("%d", each[j]);
			}
			else
			{
				printf("%c", each[j] - 10 + 'A');
			}
		}
	}
	else
	{
		for (j = i - 1; j >= 0; j--)//难点：从某个位置开始逆向输出
		{
			printf("%d", each[j]);
		}
	}
	return 0;
}