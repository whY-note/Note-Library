#include<stdio.h>
#define N 10
int main()
{
	void sort(int *x);
	int search(int x[], int y);
	int a[10] = { 1,11,3,5,2,8,6,7,-10,4 };
	int i;
	int y, place;
	//先排序
	sort(a);
	printf("排序后的数组：\n");
	for (i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("请输入要查找的数字:");
	scanf_s("%d", &y);
    //折半查找
	place=search(a, y);
	if (place == -1)
		printf("无\n");
	else
		printf("%d\n", place);
	return 0;
}
void sort(int* x)
{
	int i, j,t;
	for (i = 0; i < 10; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (*(x + i) > *(x + j))
			{
				t = *(x + i);
				*(x + i) = *(x + j);
				*(x + j) = t;
			}
		}
	}
}
int search(int x[], int y)
{
	int place = -1;
	int i;
	int lb=0, ub=N-1;
	int mid;
	int  flag = 1;//未找到数字时，flag=1
	
	if (y>=x[lb] && y<=x[ub])
	{
		while (flag&&(lb<=ub))//关键
		{
			mid = (lb + ub) / 2;
			if (y == x[mid])
			{
				place = mid;
				flag = 0;
			}
			else if (y < x[mid])
			{
				ub = mid-1;//关键
			}
			else
			{
				lb = mid+1;//关键
			}
		}
	}
	return place;
}