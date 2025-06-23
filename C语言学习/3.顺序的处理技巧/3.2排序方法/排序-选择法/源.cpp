#include<stdio.h>
int main()
{
	void sort(int array[], int n);
	int a[10] = { 1,12,4,9,10,22,-7,0,99,8 };
	int b[10] = { 1,12,4,9,10,22,-7,0,99,8 };
	int i, j, t;
	for (i = 0; i <= 9; i++)
	{
		for (j = 9; j > i; j--)
		{
			if (a[i] > a[j])
			{
				t = a[j];
				a[j] = a[i];
				a[i] = t;
			}
		}
	}
	for (i = 0; i <= 9; i++)
	{
		printf("%d ",a[i] );
	}
	printf("\n");
	sort(b, 10);
	for (i = 0; i <= 9; i++)
	{
		printf("%d ", b[i]);
	}
	return 0;
}
void sort(int array[], int n)
{
	int i, j,t;
	for (i = 0; i < n-1; i++)
	{
		for (j = i + 1; j < n;j++)
		{
			if (array[i] > array[j])
			{
				t = array[i];
				array[i] = array[j];
				array[j] = t;
			}
		}
	}
}