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
int leap(int year)//�ж�����
{
	int t = 0;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		t = 1;
	return (t);
}
int sum_day(int year,int month, int day)//��ڼ���
{
	int i,sum=day;
	int days_of_months[12] = {0, 31,28,31,30,31,30,31,31,30,31,30 };//��n����ֻҪ��ǰn-1���µ����������ټ��������е�����(�����ڽ����շ�)
	for (i = 0; i < month; i++)//�����е�һ��Ԫ��0����ռλ������������ֱ��д"i < month"
		sum = sum + days_of_months[i];
	if(month>=3)//����3�¼����ϣ���Ҫ�������������
		sum = sum + leap(year);//��������꣬�����leap�����ķ���ֵ1������������꣬����Ϸ���ֵ0
	return (sum);
}