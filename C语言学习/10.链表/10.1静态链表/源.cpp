//建立一个存放3个学生数据的静态链表，并输出其中的数据
#include<stdio.h>
struct Student
{
	int num;//学号
	float score;
	struct Student* next;//结构体类型指针
};
int main()
{
	struct Student stu[3];
	struct Student* head, * p;
	int i;
	for (i = 0; i < 3; i++)
	{
		stu[i].num = i + 1;
		scanf_s("%f", &stu[i].score);
	}

	//每个结点的next存放下一个结点的地址
	head = &stu[0];
	stu[0].next = &stu[1];
	stu[1].next = &stu[2];
	stu[2].next = NULL;
	
	//输出数据
	for (p = head; p != NULL; p = p->next)
	{
		printf("学号:%d  分数:%5.2f\n", p->num, p->score);
	}
	return 0;
}