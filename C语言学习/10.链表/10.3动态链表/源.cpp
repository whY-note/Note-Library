//дһ������������һ����3��ѧ�����ݵĶ�̬����

#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct Student)

struct Student
{
	long num;//ѧ��
	float score;//����
	struct Student* next;//�ṹ�����͵�ָ��
};
int n;//n��ȫ�ֱ���,ͳ�ƽ���������ͳ��ѧ��������


//ע�⣺�ڶ�����ṹ��֮�󣬺���ʹ��Student�ṹ��ʱ��ǰ��ġ�struct�����п���
//1.��������ĺ����������ڴ���������
struct Student* creat() 
{
	struct Student* head, * p1, * p2;

	//1.1������Ϊ�������һ�����ݵ�����
	n = 0;
	p1 = p2 = (struct Student*)malloc(LEN);//(struct Student*)���ű�����ϣ���ʹʡ��struct��ҲҪ������ 
	printf("������ѧ�š�������\n");
	scanf_s("%ld %f", &p1->num, &p1->score);
	head = NULL;   //headһ��ʼ�ǿ�ָ��

	//1.2������Ϊ������֮�����������ݵ�����
	while (p1->num != 0)//p1->num!=0,˵��������һ��ѧ��������
	{
		n = n + 1;
		if (n == 1)
		{
			head = p1;
		}
		else
		{
			p2->next = p1;//��p1��ǰ�ĵ�ַ��p2�Ľṹ��ָ��
		}
		p2 = p1;
		p1= (struct Student*)malloc(LEN);
		scanf_s("%ld %f", &p1->num, &p1->score);
	}

	//1.3����������֮��
	p2->next = NULL;
	return(head);//���ص�һ�����ݵĵ�ַ
}

//2.�������ĺ���
void print(struct Student* head)
{
	struct Student* p;
	printf("These %d records are:\n", n);
	for (p = head; p != NULL; p = p->next)
	{
		printf("ѧ�ţ�%ld ������%.2f\n", p->num, p->score);
	}
}

//3.ɾ�����ĺ���
struct Student* del(struct Student* head, long num)
{
	struct Student* p1, * p2;

	//3.1�������л�û�н��
	if (head ==NULL)
	{
		printf("list null!\n");
		return (head);
	}

	//3.2���������Ѿ��н��
	//���������д�ͷ��β���������Ŀ����
	p1 =p2= head;
	while (num != p1->num && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	//3.2.1�ҵ�Ŀ����
	if (num == p1->num)
	{
		if (p1 == head)
			head = p1->next;
		else
			p2->next = p1->next;
		printf("delete:%ld\n", num);
		n = n - 1;
		free(p1);
	}

	//3.2.2�����в�����Ŀ����
	else
		printf("%ld not been found!\n", num);
	return(head);
}

//4.������ĺ���
struct Student* insert(struct Student* head, struct Student* stud)
{
	struct Student* p0, * p1, * p2;
	p1 =p2= head;
	p0 = stud;

	//4.1�������л�û�н��
	if (head == NULL)
	{
		head = p0;
		p0->next = NULL;
	}

	//4.2���������Ѿ��н��
	else
	{
		//4.2.1���������д�ͷ��β����������½���λ��
		while ((p0->num > p1->num) && (p1->next) != NULL)
		{
			p2 = p1;
			p1 = p1->next;
		}

		//4.2.2�����½��
		//4.2.2.1���½���λ�ò������һ��
		if (p0->num <= p1->num)
		{
			if (head == p1)
				head = p0;
			else
				p2->next = p0;
			p0->next = p1;
		}
		//4.2.2.2���½���λ�������һ��
		else
		{
			p1->next = p0;
			p0->next = NULL;
		}
	}
	n = n + 1;
	return(head);
}

int main()
{
	Student* head, stu;
	long del_num;

	//��������
	head = creat();
	print(head);//���ԭʼ����

	//ɾ��1�����
	printf("input the deleted number:");
	scanf_s("%ld", &del_num);
	head = del(head, del_num);
	print(head);//���ɾ���������

	//����1�����
	printf("input the inserted records:");
	scanf_s("%ld %f", &stu.num, &stu.score);
	head = insert(head, &stu);
	print(head);//�������������
	return 0;
}