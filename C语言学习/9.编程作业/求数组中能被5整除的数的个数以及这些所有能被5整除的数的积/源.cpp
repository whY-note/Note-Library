/*��д����fun(int *p1,int *p2,int *p3)��
�书���ǣ���p1��ָһά�����е������ܱ�5���������ĸ���,�Լ���Щ�����ܱ�5���������Ļ���
�ֱ�����õĸ����Լ���ͨ��ָ��p2��p3������������
�������У��ɼ�������3����������һά����, ���ú���fun��, ��������������Ľ����
����: 
����: 10 2 5
���: 2  50
*/
#include<stdio.h>
int main()
{
	void fun(int* p1, int* p2, int* p3);
	int a[3] = { 0 };
	int i, n=0, mul=1;
	int* pn = &n, * pm = &mul;
	for (i = 0; i < 3; i++)
	{
		scanf_s("%d", &a[i]);
	}
	fun(a, pn, pm);
	printf("%d %d", *pn, *pm);
	return 0;
}
void fun(int* p1, int* p2, int* p3)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (p1[i] % 5 == 0)
		{
			(*p2)++;
			*p3 = (*p3) * p1[i];
		}
	}
}