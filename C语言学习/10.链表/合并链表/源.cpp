#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(Student)

struct Student
{
	long num;
	double score;
	struct Student* prep;
	struct Student* next;
};

Student* input(unsigned n);
Student* append(Student* head, Student* stu_append);
void print_all(Student* head);
void print_appointed(Student* head, unsigned n_appointed);
Student* del(Student* head, long del_num);
Student* insert(Student* head, Student* stu_in);
Student* combine(Student* head1, Student* head2);
void sort(Student* head);
void swap(Student* a, Student* b);

int main()
{
	Student* head1,* head2;
	//Student stu_insert;
	long del_num=0;

	unsigned n1, n2;
	printf("����������1�Ľ����:\n");
	scanf_s("%d", &n1);
	head1=input(n1);
	printf("����������2�Ľ����:\n");
	scanf_s("%d", &n2);
	head2 = input(n2);

	unsigned n_appointed;
	printf("��������ϣ���������1�Ľ����:");
	scanf_s("%d", &n_appointed);
	if (n_appointed >= n1)
	{
		printf("These %d records are:\n", n1);
		print_all(head1);
	}
	else
	{
		printf("These %d records are:\n", n_appointed);
		print_appointed(head1, n_appointed);
	}

	head1=combine(head1, head2);
	sort(head1);
	printf("\nAfter combining\nThese records are:\n");
	print_all(head1);
	return 0;
}

Student* append(Student* head, Student* stu_append)//������ĩβ��ӽ��
{
	Student* p1;
	if (head == NULL)
	{
		stu_append->prep = NULL;//�������д��stu_append->prep��������head->prep
		head = stu_append;
		head->next = NULL;
	}
	else
	{
		p1 = head;
		while (p1->next != NULL)//�ҵ����1��
		{
			p1 = p1->next;
		}
		if (p1->next == NULL)//���p1�����һ�����
		{
			p1->next = stu_append;
			stu_append->next = NULL;
		}
		stu_append->prep = p1;
	}
	return head;
}

Student* input(unsigned n)//��������
{
	Student* head=NULL,*stu;
	printf("���������������:\n");
	for (unsigned i = 1; i <= n; i++)
	{
		stu = (Student*)malloc(LEN);
		scanf_s("%ld %lf", &stu->num, &stu->score);
		head=append(head, stu);
	}
	printf("\n");
	return head;
}

void print_all(Student* head)//������н������
{
	Student* p;
	for (p = head; p != NULL; p = p->next)
	{
		printf("ѧ��:%ld ����:%.2lf\n", p->num, p->score);
	}

}

void print_appointed(Student* head, unsigned n_appointed)//���ָ�������Ľ�������
{
	Student* p;
	printf("These %d records are:\n", n_appointed);
	unsigned i = 1;
	for (p = head; p != NULL && i <= n_appointed; p = p->next)
	{
		printf("ѧ��:%ld ����:%.2lf\n", p->num, p->score);
		i += 1;
	}
}

Student* del(Student* head, long del_num)//ɾ�����
{
	Student* p1, * p2;
	if (head == NULL)
	{
		printf("������û�н�㣡\n");
	}
	else
	{
		p1 = p2 = head;
		while (del_num != p1->num && p1 != NULL)
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (del_num == p1->num)
		{
			if (p1 == head)
			{
				head = p1->next;
			}
			else
			{
				p2->next = p1->next;
			}
			printf("��ɾ���Ľ���ϵ�����:\nѧ��:%ld ����:%lf\n", p1->num, p1->score);
			free(p1);
		}
		else
		{
			printf("������û�иý�㣡\n");
		}
	}
	return head;
}

Student* insert(Student* head, Student* stu_in)//������
{
	Student* p1, * p2;
	p1 = p2 = head;
	if (head == NULL)  //����ԭ���޽��
	{
		head = stu_in;
		head->next = NULL;
	}
	else  //����ԭ���н��
	{
		while ((stu_in->num > p1->num) && (p1->next != NULL))
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (stu_in->num <= p1->num)
		{
			p2->next = stu_in;
			stu_in->next = p1;
		}
		else if (p1->next == NULL)
		{
			p1->next = stu_in;
			stu_in->next = NULL;
		}
	}
	return head;
}

Student* combine(Student* head1, Student* head2)
{
	/*������1������2�ϲ����ϲ��Ľ����������1*/
	Student* p1 = head1;
	if (head1 == NULL)
	{
		head1 = head2;
	}
	else
	{
		while (p1->next != NULL)
		{
			p1 = p1->next;
		}
		if (p1->next == NULL)//���p1�����һ�����
		{
			p1->next = head2;
			head2->prep = p1;
		}
	}
	return head1;
}
void sort(Student* head)
{
	/*���������������еĽ�㰴ѧ��˳�� ��������*/
	Student* pi, * pj;
	Student* i = NULL;
	int min = 0;
	//ѡ������
	for (pi = head; pi != NULL; pi = pi->next)
	{
		for (pj = pi; pj != NULL; pj = pj->next)
		{
			if (min> pj->num||pi==pj)//�ؼ���
			{
				i = pj;
				min = pj->num;
			}
		}
		swap(pi, i);
	}
}
void swap(Student* a, Student* b)
{
	/*�������λ�ú�����������������λ��*/
	Student* an, * ap, * bn, * bp;
	Student temp;
	an = a->next;
	ap = a->prep;
	bn = b->next;
	bp = b->prep;

	temp= *a;
	*a = *b;
	*b = temp;

	a->next = an;
	a->prep = ap;
	b->next = bn;
	b->prep = bp;
}