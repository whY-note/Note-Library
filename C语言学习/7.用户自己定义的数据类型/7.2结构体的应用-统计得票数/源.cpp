#include<stdio.h>
#include<string.h>
struct Person
{
	char name[20];
	int count;
}leader[3] = { "Li",0,"Zhang",0,"Sun",0 };//����ṹ������

int main()
{
	int i, j;
	char leader_name[20];
	for (i = 0; i < 10; i++)
	{
		scanf_s("%s", leader_name,20);//�����ѡ�˵�����
		for (j = 0; j < 3; j++)
		{
			if (strcmp(leader_name, leader[j].name) == 0)
				leader[j].count++;//�ҵ���Ӧ��ѡ�˵�count����ʹ��+1
		}
	}
	printf("\nResult:\n");
	for (j = 0; j < 3; j++)
	{
		printf("%5s:%d\n", leader[j].name, leader[j].count);//���������ѡ�˵ĵ�Ʊ��
	}
	return 0;
}