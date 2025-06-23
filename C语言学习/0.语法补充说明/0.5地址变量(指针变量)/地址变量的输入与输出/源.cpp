#include<stdio.h>
int main()
{
	int i;
	int a1, a2;
	int arr1[5], arr2[5];
	int* pa1, * pa2;//pa1,pa2对应的都是普通变量的地址
	int* parr1, * parr2;
	//对a1,pa1的操作
	pa1 = &a1;
	scanf_s("%d", pa1);
	printf("%d\n", a1);
	//对a2,pa2的操作
	scanf_s("%d", &a2);
	pa2 = &a2;
	printf("%d\n", *pa2);
	//对arr1,parr1的操作
	parr1 = arr1;
	for (i = 0; i < 5; i++)
	{
		scanf_s("%d", parr1++);//输入
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	//对arr2,parr2的操作
	for (i = 0; i < 5; i++)
	{
		scanf_s("%d", &arr2[i]);//输入
	}
	parr2 = arr2;
	for (i = 0; i < 5; i++)
	{
		printf("%d ", *parr2++);
	}
	printf("\n");
	return 0;
}