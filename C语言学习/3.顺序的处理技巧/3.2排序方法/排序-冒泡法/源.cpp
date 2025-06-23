#include<stdio.h>
#define N 10
int main()
{
	int a[N];
	int i;
	void small_to_big(int* p);
	void big_to_small(int* p);
	printf("Please input %d integer:\n",N);
	for (i = 0; i < N; i++)
	{
		scanf_s("%d", &a[i]);
	}
	small_to_big(a);
	big_to_small(a);
	return 0;
}
void small_to_big(int* p)
{
	int i, j;
	int temp;
	for (i = 1; i < N; i++)//N个数用冒泡法排序，就要进行以下操作(N-1)趟。i表示第几趟。
	{
		for (j = 0; j < N - i; j++)//每一趟，需要比较并交换相邻两个数。此操作需要从第0个数开始，直至第(N-1-i)个数
		{
			if (p[j] > p[j + 1])//比较并交换相邻两个数
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
	printf("From small to big:");
	for (i = 0; i < N; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}
void big_to_small(int* p)
{
	int i, j;
	int temp;
	for (i = 1; i < N; i++)
	{
		for (j = 0; j < N - i; j++)
		{
			if (p[j] <p[j + 1])//比较并交换相邻两个数
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
	printf("From big to small:");
	for (i = 0; i < N; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}