/*编写程序，提示用户输入分钟数（例如10000000），然后显示这些分钟代表多少年多少天。
为了简化问题，假设一年有365天，不足1天按1天算。*/
#include<stdio.h>
int main()
{
	int min, year, day,t;
	scanf_s("%d", &min);
	year = min/(24*60*365);
	day = (min-year*24*60*365) / (24 * 60);
	if (min - year * 24 * 60 * 365 - day * 24 * 60 > 0)
		day += 1;
	printf("%d年%d天\n", year, day);
	return 0;
}