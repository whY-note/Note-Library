/*��5��������ʹǰ�����˳�������m��λ�ã����m���������ǰ��m������
дһ������ʵ�����Ϲ��ܣ���������������5������������������5����*/
#include<stdio.h>
int main()
{
	void move(int* arr, int n, int m);
	int a[5] = { 0 };
	int n=5, m,i;
	for (i = 0; i < 5; i++)
	{
		scanf_s("%d", &a[i]);
	}
	scanf_s("%d", &m);
	move(a, n, m);
	for (i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
void move(int* arr, int n, int m)
{
	int x[5] = { 0 };
	int i, j,k;
	for (i = n - m,j=0; i < n; i++,j++)
	{
		x[j] = arr[i];
	}
	for (k = n-m-1; k >=0; k--)//ע�⣺�����ƶ�������
	{
		arr[k + m] = arr[k];
	}
	for (k = 0; k < j; k++)
	{
		arr[k] = x[k];
	}
}