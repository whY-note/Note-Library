#include<stdio.h>
int main()
{
	void inv1(int x[], int n);
	void inv2(int *x, int n);
	void inv3(int *x, int n);
	int arr1[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int arr2[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int arr3[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int* parr3;
	int i, j;
	inv1(arr1, 10);
	inv2(arr2, 10);
	parr3 = arr3;
	inv3(parr3, 10);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	for (j = 0; j < 10; j++)
	{
		printf("%d ", arr2[j]);
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *parr3);
		parr3++;
	}
}
void inv1(int x[], int n)//����inv1�����������βκ�ʵ��
{
	int i, j,temp;
	int c = (n - 1) / 2;//�ؼ�����������������ע�⣺��i<=c������ȡ�ȣ�����
	for (i = 0,j=n-1; i <=c ; i++,j--)//˫����ͬʱѭ����
	{
		temp = x[i];
		x[i] = x[j];
		x[j] = temp;
	}
}
void inv2(int* x, int n)//����inv2����ַ�������βΣ���������ʵ��
{
	int temp,*i,*j,*p;
	int c = (n - 1) / 2;
	//����2��Ҳ����д��for()�е�һ��;ǰ
	i = x;//����Ԫ�ص�ַ
	j = x + n - 1;//��ĩԪ�ص�ַ
	p = x + c;//���м�Ԫ�ص�ַ
	for (; i <= p; i++, j--)//ѭ������������i<=p!!!
	{
		temp = *i;
		*i = *j;
		*j = temp;
	}
}
void inv3(int* x, int n)//����inv3����ַ�������βκ�ʵ��
{
	int temp, * i, * j, * p;
	int c = (n - 1) / 2;
	i = x;
	j = x + n - 1;
	p = x + c;
	for (; i <= p; i++, j--)
	{
		temp = *i;
		*i = *j;
		*j = temp;
	}
}