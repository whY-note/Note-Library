/*��д����insert(char str1[], char str2[],int n)��
�书���ǣ���str2��������ַ��������ַ�����str1�ڵ�n���ַ�֮��
��main�����У��ֱ����������ַ�����str1��str2����󳤶ȶ�С��10)��
һ����������n(������str1��ʵ�ʳ���)�����ú���insert����main�������������ϲ�����ַ�����
������������ע�͡�
*/
#include<stdio.h>
#include<string.h>
int main()
{
	void insert(char str1[], char str2[], int n);
	char s1[20] = { 0 }, s2[10] = { 0 };
	int n;
	gets_s(s1);
	gets_s(s2);
	scanf_s("%d", &n);
	insert(s1, s2, n);
	printf("%s", s1);
	return 0;
}
void insert(char str1[], char str2[], int n)
{
	int i, j,k;
	int len1 = strlen(str1), len2 = strlen(str2);
	for (i = len1 - 1; i >=n; i--)//ע�⣺��i >=n������ȡ��
	{
		str1[i + len2] = str1[i];
	}
	str1[len1 + len2] = '\0';
	for (j = n,k=0; j <= n + len2 - 1&&k<len2; j++,k++)
	{
		str1[j] = str2[k];
	}
}