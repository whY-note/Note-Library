#include<stdio.h>

int leap(int year);
int count_monthday(int year, int month);
int count_yearday(int star_year, int end_year);

int main()
{
	int start_year, start_month, start_day, end_year, end_month, end_day;
	int difference;
	printf("start date:");
	scanf_s("%d%d%d", &start_year, &start_month, &start_day);
	printf("end data:");
	scanf_s("%d%d%d", &end_year, &end_month, &end_day);

	//����֮��=����֮���������-��ʼ��������ʼ��ĵڼ���+���������ǽ�����ĵڼ���
	difference = count_yearday(start_year, end_year) - (count_monthday(start_year, start_month) + start_day) + (count_monthday(end_year, end_month) + end_day);
	printf("���%d��\n", difference);
	printf("��%d��%d��%d���𣬵�%d��", start_year, start_month, start_day, difference + 1);
	return 0;
}
int leap(int year)//�ж�����
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return 1;
	else
		return 0;
}
int count_monthday(int year, int month)//�������������ĵڼ���
{
	int monthday[12] = { 0,31,28 + leap(year),31,30,31,30,31,31,30,31,30 };
	int i, sum = 0;

	for (i = 1; i < month; i++)
	{
		sum = sum + monthday[i];
	}
	return sum;
}
int count_yearday(int start_year, int end_year)//��������֮���������
{
	int sum = 0, i;
	for (i = start_year; i < end_year; i++)
	{
		sum = sum + 365 + leap(i);
	}
	return sum;
}
