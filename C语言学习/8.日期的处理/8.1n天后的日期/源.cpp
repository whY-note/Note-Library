#include<stdio.h>

bool leap(int year);
int startDaySum(int year, int month, int day);
void endDate(int year, int month, int day, int n);

int main()
{
	int year, month, day, n;
	printf("���ڵ�����:");
	scanf_s("%d%d%d", &year, &month, &day);
	printf("�������:");
	scanf_s("%d", &n);
	endDate(year, month, day, n);
	return 0;
}

bool leap(int year)//�ж�����
{
	if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
		return true;
	else
		return false;
}

int startDaySum(int year, int month, int day)//���㿪ʼ���ڵ� ��ʼ�������һ���12��31�վ����˶�����
{
	int n_startDaySum = day;
	int monthDay[12] = { 0,31,28,31,30,31,30,31,31,30,31,30 };
	monthDay[2] += leap(year);//�������2������+1

	for (int i = 0; i < month; i++)
	{
		n_startDaySum += monthDay[i];
	}
	return n_startDaySum;
}

void endDate(int startYear, int startMonth, int startDay, int n)//�����������
{
	int monthDay[12] = { 0,31,28,31,30,31,30,31,31,30,31,30 };
	int endYear = startYear, endMonth = 0, endDay = 0;
	int n_endDaySum = n + startDaySum(startYear, startMonth, startDay);//����ӿ�ʼ�����1��1�յ� �������� ��������

	//�������
	while (n_endDaySum > 365 + leap(endYear))
	{
		n_endDaySum = n_endDaySum - (365 + leap(endYear));
		endYear++;
	}

	monthDay[2] += leap(endYear);//����������������꣬��2������+1

	//�����·�
	int i = 0;
	while (n_endDaySum > monthDay[i] && i < 12)//ע��Ҫ����: i< 12
	{
		n_endDaySum = n_endDaySum - monthDay[i];
		i++;
	}
	endMonth = i;

	//ʣ����������Ǽ���
	endDay = n_endDaySum;

	printf("%4d��%2d��%2d��\n", endYear, endMonth, endDay);
}