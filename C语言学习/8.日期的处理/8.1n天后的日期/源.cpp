#include<stdio.h>

bool leap(int year);
int startDaySum(int year, int month, int day);
void endDate(int year, int month, int day, int n);

int main()
{
	int year, month, day, n;
	printf("现在的日期:");
	scanf_s("%d%d%d", &year, &month, &day);
	printf("多少天后:");
	scanf_s("%d", &n);
	endDate(year, month, day, n);
	return 0;
}

bool leap(int year)//判断闰年
{
	if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
		return true;
	else
		return false;
}

int startDaySum(int year, int month, int day)//计算开始日期到 开始那年的上一年的12月31日经过了多少天
{
	int n_startDaySum = day;
	int monthDay[12] = { 0,31,28,31,30,31,30,31,31,30,31,30 };
	monthDay[2] += leap(year);//闰年则把2月天数+1

	for (int i = 0; i < month; i++)
	{
		n_startDaySum += monthDay[i];
	}
	return n_startDaySum;
}

void endDate(int startYear, int startMonth, int startDay, int n)//计算结束日期
{
	int monthDay[12] = { 0,31,28,31,30,31,30,31,31,30,31,30 };
	int endYear = startYear, endMonth = 0, endDay = 0;
	int n_endDaySum = n + startDaySum(startYear, startMonth, startDay);//计算从开始那年的1月1日到 结束那天 的总天数

	//计算年份
	while (n_endDaySum > 365 + leap(endYear))
	{
		n_endDaySum = n_endDaySum - (365 + leap(endYear));
		endYear++;
	}

	monthDay[2] += leap(endYear);//如果结束那年是闰年，则2月天数+1

	//计算月份
	int i = 0;
	while (n_endDaySum > monthDay[i] && i < 12)//注意要限制: i< 12
	{
		n_endDaySum = n_endDaySum - monthDay[i];
		i++;
	}
	endMonth = i;

	//剩余的天数就是几日
	endDay = n_endDaySum;

	printf("%4d年%2d月%2d日\n", endYear, endMonth, endDay);
}