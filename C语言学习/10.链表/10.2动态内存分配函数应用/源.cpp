//������̬���飬����5��ѧ���ĳɼ�����������һ����������������޵���60�ֵģ�������ϸ�ĳɼ�

#include<stdio.h>
#include<stdlib.h>
int main()
{
	void check(int*);//���ڼ���������޵���60�ֵĺ���
	int* p1, i;
	//p1 = (int*)malloc(5 * sizeof(int));//���ٶ�̬�洢�ռ䣬sizeof()�ǲ��ֽ����ĺ��� 
	p1 = (int*)calloc(5, sizeof(int));
	for (i = 0; i < 5; i++)
	{
		scanf_s("%d", p1 + i);
	}
	check(p1);
	return 0;
}
void check(int*p)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		if(*(p+i)<60)
		{
			printf("%d ", *(p + i));
		}
	}
	printf("\n");
}

