#define _CRT_SECURE_NO_WARNINGS //���⾯��strcpy����ȫ
#include<stdio.h>
#include<string.h>
#define N 6
void sort(int n, char str[][20])//n�����������������ÿһ�д��һ���ַ���
{
	int i, j;
	char s[20] = { 0 };//����s�������м����
	for (i = 0; i < n-1; i++)//ѡ�����򷨣�����ֵ����������
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(str[j], str[i]) < 0)//��֮ͬ��1����strcmp���Ƚ��ַ����ġ���С��
			{
				strcpy(s, str[i]);//��֮ͬ��2����strcpy�����ַ�������ֵ��
				strcpy(str[i], str[j]);
				strcpy(str[j], s);
			}//str[i], str[j]��s����ָһά�����������Ǵ���ÿ�е���Ԫ�صĵ�ַ
		}
	}
}
int main()
{
	void sort(int n, char str[][20]);
	int i, j,n=N;
	char c[N][20] = { 0 };
	printf("Please input N strings:");
	for (i = 0; i < N; i++)
		gets_s(c[i]);//���������ַ�����c��ÿ��ռһ���ַ���
	sort(n, c);
	printf("The strings in order is:\n");
	for (j = 0; j < N; j++)
	{
		puts(c[j]);//��������ַ�����c
	}
	return 0;
}