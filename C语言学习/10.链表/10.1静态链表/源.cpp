//����һ�����3��ѧ�����ݵľ�̬������������е�����
#include<stdio.h>
struct Student
{
	int num;//ѧ��
	float score;
	struct Student* next;//�ṹ������ָ��
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

	//ÿ������next�����һ�����ĵ�ַ
	head = &stu[0];
	stu[0].next = &stu[1];
	stu[1].next = &stu[2];
	stu[2].next = NULL;
	
	//�������
	for (p = head; p != NULL; p = p->next)
	{
		printf("ѧ��:%d  ����:%5.2f\n", p->num, p->score);
	}
	return 0;
}