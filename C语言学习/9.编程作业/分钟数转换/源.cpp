/*��д������ʾ�û����������������10000000����Ȼ����ʾ��Щ���Ӵ������������졣
Ϊ�˼����⣬����һ����365�죬����1�찴1���㡣*/
#include<stdio.h>
int main()
{
	int min, year, day,t;
	scanf_s("%d", &min);
	year = min/(24*60*365);
	day = (min-year*24*60*365) / (24 * 60);
	if (min - year * 24 * 60 * 365 - day * 24 * 60 > 0)
		day += 1;
	printf("%d��%d��\n", year, day);
	return 0;
}