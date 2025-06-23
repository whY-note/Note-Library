//写一个函数，建立一个有3个学生数据的动态链表

#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct Student)

struct Student
{
	long num;//学号
	float score;//分数
	struct Student* next;//结构体类型的指针
};
int n;//n是全局变量,统计结点个数。即统计学生的数量


//注意：在定义完结构体之后，后面使用Student结构体时，前面的“struct”可有可无
//1.建立链表的函数，并且在此输入数据
struct Student* creat() 
{
	struct Student* head, * p1, * p2;

	//1.1以下是为了输入第一组数据的设置
	n = 0;
	p1 = p2 = (struct Student*)malloc(LEN);//(struct Student*)括号必须加上，即使省略struct后也要加括号 
	printf("请输入学号、分数：\n");
	scanf_s("%ld %f", &p1->num, &p1->score);
	head = NULL;   //head一开始是空指针

	//1.2以下是为了输入之后其他组数据的设置
	while (p1->num != 0)//p1->num!=0,说明输入了一个学生的数据
	{
		n = n + 1;
		if (n == 1)
		{
			head = p1;
		}
		else
		{
			p2->next = p1;//把p1当前的地址给p2的结构体指针
		}
		p2 = p1;
		p1= (struct Student*)malloc(LEN);
		scanf_s("%ld %f", &p1->num, &p1->score);
	}

	//1.3输入完数据之后
	p2->next = NULL;
	return(head);//返回第一组数据的地址
}

//2.输出链表的函数
void print(struct Student* head)
{
	struct Student* p;
	printf("These %d records are:\n", n);
	for (p = head; p != NULL; p = p->next)
	{
		printf("学号：%ld 分数：%.2f\n", p->num, p->score);
	}
}

//3.删除结点的函数
struct Student* del(struct Student* head, long num)
{
	struct Student* p1, * p2;

	//3.1若链表中还没有结点
	if (head ==NULL)
	{
		printf("list null!\n");
		return (head);
	}

	//3.2若链表中已经有结点
	//先在链表中从头到尾，逐个查找目标结点
	p1 =p2= head;
	while (num != p1->num && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	//3.2.1找到目标结点
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

	//3.2.2链表中不存在目标结点
	else
		printf("%ld not been found!\n", num);
	return(head);
}

//4.插入结点的函数
struct Student* insert(struct Student* head, struct Student* stud)
{
	struct Student* p0, * p1, * p2;
	p1 =p2= head;
	p0 = stud;

	//4.1若链表中还没有结点
	if (head == NULL)
	{
		head = p0;
		p0->next = NULL;
	}

	//4.2若链表中已经有结点
	else
	{
		//4.2.1先在链表中从头到尾，逐个查找新结点的位置
		while ((p0->num > p1->num) && (p1->next) != NULL)
		{
			p2 = p1;
			p1 = p1->next;
		}

		//4.2.2插入新结点
		//4.2.2.1若新结点的位置不在最后一个
		if (p0->num <= p1->num)
		{
			if (head == p1)
				head = p0;
			else
				p2->next = p0;
			p0->next = p1;
		}
		//4.2.2.2若新结点的位置在最后一个
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

	//创建链表
	head = creat();
	print(head);//输出原始链表

	//删除1个结点
	printf("input the deleted number:");
	scanf_s("%ld", &del_num);
	head = del(head, del_num);
	print(head);//输出删除后的链表

	//插入1个结点
	printf("input the inserted records:");
	scanf_s("%ld %f", &stu.num, &stu.score);
	head = insert(head, &stu);
	print(head);//输出插入后的链表
	return 0;
}