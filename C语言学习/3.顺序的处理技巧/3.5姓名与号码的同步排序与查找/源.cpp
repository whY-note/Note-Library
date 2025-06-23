#include<stdio.h>
#include<string.h>
#define N 5
int main()
{
	void input(char name[][10], int num[]);
	void sort(char name[][10], int num[]);
	int search(int num[],int n);
	char name[N][10] = { 0 };
	int num[N];
	int place, n;
	input(name, num);
	sort(name, num);
	scanf_s("%d", &n);
	place=search(num, n);
	if (place == -1)
		printf("无\n");
	else
		printf("%s,%d\n", name[place], num[place]);
	return 0;
}
void input(char name[][10], int num[])
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("Name:");
		gets_s(name[i]);
		printf("Number:");
		scanf_s("%d", &num[i]);
		getchar();//用于吸收换行
	}
}
void sort(char name[][10], int num[])
{
	int i, j,t;
	char temp[10] = { 0 };
	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (num[i] > num[j])
			{
				//调换号码顺序
				t = num[i];
				num[i] = num[j];
				num[j] = t;
				//同时，调换名字顺序
				strcpy_s(temp, name[i]);
				strcpy_s(name[i], name[j]);
				strcpy_s(name[j], temp);
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		printf("%s,%d\n", name[i], num[i]);
	}
}
int search(int num[],int n)
{
	int lb = 0, ub = N-1;
	int mid, flag = 1;
	int place=-1;
	if (n >= num[lb] && n <= num[ub])
	{
		while (flag && (lb <= ub))
		{
			mid = (lb + ub) / 2;
			if (n == num[mid])
			{
				place = mid;
				flag = 0;
			}
			else if (n < num[mid])
			{
				ub = mid - 1;
			}
			else
			{
				lb = mid + 1;
			}
		}
	}
	return place;
}