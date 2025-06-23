#include<stdio.h>
#include<stdlib.h>

class Node
{public:
	int age;
	char name[10];
	Node* prev;
	Node* next;
};
Node* input(unsigned n);
Node* append(Node* head,Node* person_append);
void output_all(Node* head);

int main()
{
	Node* head = NULL;
	unsigned n;
	printf("The number of node:");
	scanf_s("%d", &n);
	head = input(n);
	output_all(head);
	return 0;
}

Node* input(unsigned n)
{
	Node* head = NULL;
	Node* new_node;
	for (unsigned i = 0; i < n; i++)
	{
		new_node = new Node[1];//创建1个内存大小为Node的对象
		scanf_s("%d", &new_node->age);
		gets_s(new_node->name);
		head= append(head,new_node);
	}
	return head;
}

Node* append(Node* head, Node* new_node)
{
	Node* p1;
	while (head == NULL)
	{	
		new_node->prev = NULL;
		head = new_node;
		head->next = NULL;
	}
	if (head != NULL)
	{
		p1 = head;
		while (p1->next != NULL)
		{
			p1 = p1->next;
		}
		if (p1->next == NULL)
		{
			p1->next = new_node;
			new_node->next = NULL;
			new_node->prev = p1;
		}
	}
	return head;
}
void output_all(Node* head)
{
	Node* p1 = head;
	if (head == NULL)
	{
		printf("None");
	}
	else
	{
		for (; p1!= NULL; p1 = p1->next)
		{
			printf("%d", p1->age);
			puts(p1->name);
		}
	}
}

