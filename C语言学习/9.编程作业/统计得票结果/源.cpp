/*有3个候选人，每个选民只能投票选一人，
要求编一个统计选票的程序，先后输入被选人的名字，最后输出各人得票结果。*/
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