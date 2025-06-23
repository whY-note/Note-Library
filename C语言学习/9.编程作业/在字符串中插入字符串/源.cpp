/*编写函数insert(char str1[], char str2[],int n)，
其功能是：将str2数组里的字符串插入字符数组str1内第n个字符之后。
在main函数中，分别输入两个字符串（str1和str2，最大长度都小于10)、
一个整型数字n(不大于str1的实际长度)，调用函数insert，在main函数中输出插入合并后的字符串。
【需至少两条注释】
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
	for (i = len1 - 1; i >=n; i--)//注意：“i >=n”可以取等
	{
		str1[i + len2] = str1[i];
	}
	str1[len1 + len2] = '\0';
	for (j = n,k=0; j <= n + len2 - 1&&k<len2; j++,k++)
	{
		str1[j] = str2[k];
	}
}