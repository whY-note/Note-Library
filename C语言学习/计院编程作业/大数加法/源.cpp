/*输入两个非负整数a和b，输出两个非负整数的和(a+b)。
数据规模:0<=a,b<=10的99次方-1
*/

#include<stdio.h>
#include<string.h>


int main()
{
	//用字符数组来存储两个大数
	char num1[101] = { 0 }, num2[101] = { 0 };//最多100位，多1位用来放'\0'
	scanf_s("%s", num1, 100);
	scanf_s("%s", num2, 100);

	char result[102] = { '\0' };//为了存储最高位的进位，num3要多1位
	
	int len1 = strlen(num1);
	int len2 = strlen(num2);

	//i1,i2分别指向num1,num2的最大下标
	int i1 = len1 - 1;
	int i2 = len2 - 1;
	//i3指向result的最大下标-1,最后1位用来放'\0'
	int i3 = 101 - 1;
	//进位标记
	int jin = 0;

	/**************************************************************/
//开始计算
//注意：这里从 个位 开始向 最高位 计算，对应到数组中就是从 最大下标 开始向 小的下标 计算

	while (i1 >= 0 && i2 >= 0)//当2个数都未结束时
	{
		int digit1 = num1[i1] - '0';
		int digit2 = num2[i2] - '0';
		int sum = digit1 + digit2 + jin;

		//判断有无进位
		if (sum >= 10)
		{
			jin = 1;
			sum = sum - 10;
		}
		else
		{
			jin = 0;
		}
		result[i3] = sum + '0';

		//计算完1位后，所有下标前移1位
		i3--;
		i2--;
		i1--;
	}

	//如果num2结束了，则只用计算num1的剩余位
	while (i1 >= 0)
	{
		int digit1 = num1[i1] - '0';
		int sum = digit1 + jin;

		//判断有无进位
		if (sum >= 10)
		{
			jin = 1;
			sum = sum - 10;
		}
		else
		{
			jin = 0;
		}
		result[i3] = sum + '0';

		//计算完1位后，所有下标前移1位
		i3--;
		i1--;
	}

	//如果num1结束了，则只用计算num2的剩余位
	while (i2 >= 0)
	{
		int digit2 = num2[i2] - '0';
		int sum = digit2 + jin;

		//判断有无进位
		if (sum >= 10)
		{
			jin = 1;
			sum = sum - 10;
		}
		else
		{
			jin = 0;
		}
		result[i3] = sum + '0';

		//计算完1位后，所有下标前移1位
		i3--;
		i2--;
	}

	//存放最后1次进位
	if (jin == 1)
	{
		result[i3] = 1 + '0';
	}

	//output
	for (int i=i3; i < 101; i++)
	{
		printf("%c", result[i]);
	}
	return 0;
}
