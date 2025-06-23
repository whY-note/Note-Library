/*输入一个字符串，其中含有数字和非数字。
将其中的连续数字作为一个整数，依次存放在一个数组中。
统计共有多少个整数，并输出这些数。*/

#include<stdio.h>
int main()
{
	char str[] = "A123x456 17960?302tab5876";
	int i, j = 0;
	int num[10];
	int sum = 0;
	int flag = 1;//开关变量，判断是不是数字
	for (i = 0; str[i] != 0; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (flag)
			{
				sum = str[i] - '0';
				flag = 0;
			}
			else
			{
				sum = 10 * sum + str[i] - '0';
			}
		}
		else
		{
			if (flag == 0)
			{
				flag = 1;
				num[j] = sum;
				j++;
				sum = 0;//复位。一定要放在最后！
			}
		}
		if (str[i + 1] == '\0' && flag == 0)//用来处理位于末尾的数字
		{
			num[j] = sum;
			j++;
		}
	}
	for (i = 0; i < j; i++)
	{
		printf("%d ", num[i]);
	}
	return 0;
}

