/*��3����ѡ�ˣ�ÿ��ѡ��ֻ��ͶƱѡһ�ˣ�
Ҫ���һ��ͳ��ѡƱ�ĳ����Ⱥ����뱻ѡ�˵����֣����������˵�Ʊ�����*/
#include<stdio.h>
#include<string.h>
int main()
{
	struct Person
	{
		char name[10];
		int count;
	}leader[3] = {"Zhao",0,"Qian",0,"Sun",0};
	int i,j;
	char na[10] = { 0 };
	for (i = 1; i <= 10; i++)
	{
		scanf_s("%s", na,10);
		for (j = 0; j < 3; j++)
		{
			if (strcmp(na, leader[j].name) == 0)
				leader[j].count++;
		}
	}
	for (j = 0; j < 3; j++)
	{
		printf("Name:%s Count:%d\n", leader[j].name, leader[j].count);
	}
	return 0;
}