#include<stdio.h>
int main()
{
	int runnian1(int year);
	int runnian2(int year);
	int year, leap1,leap2;
	scanf_s("%d",&year);
	leap1= runnian1(year);
	leap2 = runnian2(year);
	if (leap2)
		printf("����");
	else
		printf("No");
	return 0;
}
int runnian1(int year)
{
	int leap;
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				leap = 1;
			else
				leap = 0;
		}
		else
			leap = 1;
	}
	else
		leap = 0;
	return (leap);
}
int runnian2(int year)//����࣬����
{
	int leap;
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		leap = 1;
	else
		leap = 0;
	return (leap);
}