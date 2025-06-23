/*在main函数中，通过键盘分别读入字符串（最大长度不超3 0包含字母、数字)和一个字符，
利用自定义函数 findlet对字符串进行处理，
然后在main函数中输出 ：该字符在字符数组中第一次出现的位置（下标值）（若没有该字符，则输出-1）。
函数 void findlet(char *str, char * let, int *order) 的功能：
针对指针str指向的字符数组，找到指针let所指向的字符在该字符数组中第一次出现的位置（下标值）
（若没有该字符，则输出-1），并把该下标值存储到指针order所指向的变量。

如字符串 “12a89aaRry6ru”中，字母a第一次出现的下标值为2。而字母b没有出现，下标值为-1。
【要有至少两条注释】
示例：
输入：
12a89aaRry6ru
a
输出：
2
*/
#include<stdio.h>
int main()
{
	void findlet(char* str, char* let, int* order);
	int order=-1,* p=&order;
	char c, * pc = &c;
	char s[100] = { 0 };
	gets_s(s);
	scanf_s("%c", pc);
	findlet(s, pc, p);
	printf("%d", *p);
	return 0;
}
void findlet(char* str, char* let, int* order)
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == *let)
		{
			*order = i;
		}
	}
}