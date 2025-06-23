#include<stdio.h>
int main()
{
	int leap(int year);
	int sum_day(int year,int month, int day);
	int y, m, d,sum;
	scanf_s("%d%d%d", &y, &m, &d);
	sum = sum_day(y, m, d);
	printf("%d", sum);
}
int leap(int year)//判断闰年
{
	int t = 0;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		t = 1;
	return (t);
}
int sum_day(int year,int month, int day)//求第几天
{
	int i,sum=day;
	int days_of_months[12] = {0, 31,28,31,30,31,30,31,31,30,31,30 };//第n个月只要求前n-1个月的总天数，再加上日期中的日数(类似于阶梯收费)
	for (i = 0; i < month; i++)//数组中第一个元素0用来占位，因此这里可以直接写"i < month"
		sum = sum + days_of_months[i];
	if(month>=3)//对于3月及以上，需要考虑闰年的问题
		sum = sum + leap(year);//如果是闰年，则加上leap函数的返回值1；如果不是闰年，则加上返回值0
	return (sum);
}