#include<stdio.h>
int main()
{
	int i;
	int a1, a2;
	int arr1[5], arr2[5];
	int* pa1, * pa2;//pa1,pa2��Ӧ�Ķ�����ͨ�����ĵ�ַ
	int* parr1, * parr2;
	//��a1,pa1�Ĳ���
	pa1 = &a1;
	scanf_s("%d", pa1);
	printf("%d\n", a1);
	//��a2,pa2�Ĳ���
	scanf_s("%d", &a2);
	pa2 = &a2;
	printf("%d\n", *pa2);
	//��arr1,parr1�Ĳ���
	parr1 = arr1;
	for (i = 0; i < 5; i++)
	{
		scanf_s("%d", parr1++);//����
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	//��arr2,parr2�Ĳ���
	for (i = 0; i < 5; i++)
	{
		scanf_s("%d", &arr2[i]);//����
	}
	parr2 = arr2;
	for (i = 0; i < 5; i++)
	{
		printf("%d ", *parr2++);
	}
	printf("\n");
	return 0;
}