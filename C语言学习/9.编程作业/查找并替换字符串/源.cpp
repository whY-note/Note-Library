/*��д����replace(char *str,char *fstr,char *rstr)��
��str��ָ�ַ����з�����fstr�ַ�����ͬ���ַ��滻��rstr��rstr��fstr���ַ����Ȳ�һ����ͬ����
��������������ԭʼ�ַ���"iffordowhileelsewhilebreak"�������ַ���"while"���滻�ַ���"struct"��
���ú����õ������*/
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
			t[k] = '\0';//����޴˾䣬���ڵڶ����滻ʱ�����������һ��t�����е�Ԫ��
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