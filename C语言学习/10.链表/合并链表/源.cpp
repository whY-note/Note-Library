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
	printf("请输入链表1的结点数:\n");
	scanf_s("%d", &n1);
	head1=input(n1);
	printf("请输入链表2的结点数:\n");
	scanf_s("%d", &n2);
	head2 = input(n2);

	unsigned n_appointed;
	printf("请输入你希望输出链表1的结点数:");
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

Student* append(Student* head, Student* stu_append)//向链表末尾添加结点
{
	Student* p1;
	if (head == NULL)
	{
		stu_append->prep = NULL;//这里必须写成stu_append->prep，不能是head->prep
		head = stu_append;
		head->next = NULL;
	}
	else
	{
		p1 = head;
		while (p1->next != NULL)//找到最后1个
		{
			p1 = p1->next;
		}
		if (p1->next == NULL)//如果p1是最后一个结点
		{
			p1->next = stu_append;
			stu_append->next = NULL;
		}
		stu_append->prep = p1;
	}
	return head;
}

Student* input(unsigned n)//创建链表
{
	Student* head=NULL,*stu;
	printf("请输入链表的数据:\n");
	for (unsigned i = 1; i <= n; i++)
	{
		stu = (Student*)malloc(LEN);
		scanf_s("%ld %lf", &stu->num, &stu->score);
		head=append(head, stu);
	}
	printf("\n");
	return head;
}

void print_all(Student* head)//输出所有结点数据
{
	Student* p;
	for (p = head; p != NULL; p = p->next)
	{
		printf("学号:%ld 分数:%.2lf\n", p->num, p->score);
	}

}

void print_appointed(Student* head, unsigned n_appointed)//输出指定数量的结点的数据
{
	Student* p;
	printf("These %d records are:\n", n_appointed);
	unsigned i = 1;
	for (p = head; p != NULL && i <= n_appointed; p = p->next)
	{
		printf("学号:%ld 分数:%.2lf\n", p->num, p->score);
		i += 1;
	}
}

Student* del(Student* head, long del_num)//删除结点
{
	Student* p1, * p2;
	if (head == NULL)
	{
		printf("链表中没有结点！\n");
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
			printf("被删除的结点上的数据:\n学号:%ld 分数:%lf\n", p1->num, p1->score);
			free(p1);
		}
		else
		{
			printf("链表中没有该结点！\n");
		}
	}
	return head;
}

Student* insert(Student* head, Student* stu_in)//插入结点
{
	Student* p1, * p2;
	p1 = p2 = head;
	if (head == NULL)  //链表原来无结点
	{
		head = stu_in;
		head->next = NULL;
	}
	else  //链表原来有结点
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
	/*把链表1与链表2合并，合并的结果放在链表1*/
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
		if (p1->next == NULL)//如果p1是最后一个结点
		{
			p1->next = head2;
			head2->prep = p1;
		}
	}
	return head1;
}
void sort(Student* head)
{
	/*排序函数：把链表中的结点按学号顺序 升序排列*/
	Student* pi, * pj;
	Student* i = NULL;
	int min = 0;
	//选择排序法
	for (pi = head; pi != NULL; pi = pi->next)
	{
		for (pj = pi; pj != NULL; pj = pj->next)
		{
			if (min> pj->num||pi==pj)//关键句
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
	/*交换结点位置函数：交换两个结点的位置*/
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