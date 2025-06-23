#include<stdio.h>
#include<string.h>
int main()
{
	struct Stu
	{
		char name[5];
	}s[2] = {0};
	int i;
	//scanf_s("%s", s[0].name,5);//输入法一：scanf %s法，更好！！！
	for (i = 0; i < 2; i++)//输入法二：gets法//！！！注意，由于空格也能被算进gets里面，所以输入时字符串的后面必须带有回车，否则：字符串后面的东西也会被gets吸收，可能导致字符串数组越域
	{
		gets_s(s[i].name);
	}
	for (i = 0; i < 2; i++)
	{
		printf("%s\n", s[i].name);
	}
	return 0;
}