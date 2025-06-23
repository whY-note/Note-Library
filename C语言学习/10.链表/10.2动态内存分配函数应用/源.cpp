//建立动态数组，输入5个学生的成绩，再用另外一个函数检查其中有无低于60分的，输出不合格的成绩

#include<stdio.h>
#include<stdlib.h>
int main()
{
	void check(int*);//用于检查其中有无低于60分的函数
	int* p1, i;
	//p1 = (int*)malloc(5 * sizeof(int));//开辟动态存储空间，sizeof()是测字节数的函数 
	p1 = (int*)calloc(5, sizeof(int));
	for (i = 0; i < 5; i++)
	{
		scanf_s("%d", p1 + i);
	}
	check(p1);
	return 0;
}
void check(int*p)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		if(*(p+i)<60)
		{
			printf("%d ", *(p + i));
		}
	}
	printf("\n");
}

