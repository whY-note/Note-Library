/*编写函数replace(char *str,char *fstr,char *rstr)，
将str所指字符串中凡是与fstr字符串相同的字符替换成rstr（rstr与fstr的字符长度不一定相同）。
从主函数中输入原始字符串"iffordowhileelsewhilebreak"、查找字符串"while"和替换字符串"struct"，
调用函数得到结果。*/
#include<stdio.h>
#include<string.h>
int main()
{
	void replace(char* str, char* fstr, char* rstr);
	char s[100] = { 0 }, f[100] = { 0 }, r[100] = { 0 };
	gets_s(s);
	gets_s(f);
	gets_s(r);
	replace(s, f, r);
	printf("%s", s);
	return 0;
}
void replace(char* str, char* fstr, char* rstr)
{
	int flag = 0, i, j, k;
	int lens = strlen(str), lenf = strlen(fstr), lenr = strlen(rstr);
	char t[100] = { 0 };
	for (i = 0; str[i]!='\0'; i++)
	{
		for (j = i, k = 0; str[j] == fstr[k]; j++, k++)
		{
			if (fstr[k+1] == '\0')
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			for (j = i + lenf ,k=0; str[j] != '\0'; j++,k++)
			{
				t[k] = str[j];
			}
			t[k] = '\0';//如果无此句，则在第二次替换时，会残留有上一次t数组中的元素
			for (j = i, k = 0; rstr[k] != '\0'; j++, k++)
			{
				str[j] = rstr[k];
			}
			for (k = 0; t[k] != '\0'; k++, j++)
			{
				str[j] = t[k];
			}
			str[j] = '\0';
		}
		flag = 0;
	}
}