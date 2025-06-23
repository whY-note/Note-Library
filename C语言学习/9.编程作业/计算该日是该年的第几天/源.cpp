/*给出年、月、日，用函数计算该日是该年的第几天*/
#include<stdio.h>
int main()
{
	int run(int year);
	int m_to_d(int year,int month);
	int y, m, d,alldays;
	scanf_s("%d%d%d",&y, &m, &d);
	alldays=d+m_to_d(y, m);
	printf("%d", alldays);
	return 0;
}
int run(int year)
{
	int r;
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		r = 1;
	else
		r = 0;
	return (r);
}
int m_to_d(int year,int month)
{
	int m[12] = { 0,31,28,31,30,31,30,31,31,30,31,30 };
	int days=0,i;
	if (month < 3)
	{
		for (i = 0; i < month; i++)
		{
			days = days + m[i];
		}
	}
	else
	{
		for (i = 0; i < month; i++)
		{
			days = days + m[i];
		}
		if (run(year))
			days = days + 1;
	}
	return (days);
}