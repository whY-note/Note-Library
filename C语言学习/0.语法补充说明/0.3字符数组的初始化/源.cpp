#include<stdio.h>
#include<string.h>
int main()
{
	int i;
	char x[6] = {"China"};//���д��x[5]�� ��ϵͳ��ʾ������Ϊû�ж�һ��λ����ϵͳ�Զ�����'\0'
	char y[5] = { 'C','h','i','n','a' };//û�ж�һ��λ����ϵͳ�Զ�����'\0'
	char z[6]= { 'C','h','i','n','a' };//����һ��λ��ϵͳ�Զ�����'\0'
	char w[6]= { 'C','h','i','n','a','\0'};//�˹�����'\0'
	char v[] = { 'C','h','i','n','a' };//ϵͳ�Զ�����Ϊv[5],��y[5]��ͬ
	char u[] = { "China" };//��w[6]��ͬ
	printf("%%sx=%s\n", x);//1.1
	printf("%%sy=%s\n", y);//2.1���ڡ�China��֮���������ַ�
	printf("%%sz=%s\n", z);//3.1
	printf("%%sw=%s\n", w);//4.1 ��1.1��3.1��4.1��Ч���ڡ�China��֮���������ַ�
	printf("%%sv=%s\n", v);
	printf("%%su=%s\n", u);
	for (i = 0; i < 6; i++)
	{
		printf("%%cx=%c ", x[i]);//1.2
	}
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		printf("%%cy=%c ", y[i]);//2.2������ޡ�%cy= ��
	}
	printf("\n");
	for (i = 0; i < 6; i++)
	{
		printf("%%cz=%c ", z[i]);//3.2
	}
	printf("\n");
	for (i = 0; i < 6; i++)
	{
		printf("%%cw=%c ", w[i]);//4.2��1.2��3.2��4.2��Ч������� ��%cw= ��
	}
	printf("\n");
	for (i = 0; i < 6; i++)
	{
		printf("%%cv=%c ", v[i]);
	}
	printf("\n");
	for (i = 0; i < 6; i++)
	{
		printf("%%cu=%c ", u[i]);
	}
	printf("\n");
	return 0;
}