#include<stdio.h>
#include<string.h>
int main()
{
	void replace1(char* str, char* fstr, char* rstr);
	void replace2(char* str_main, char* str_find, char* str_replace);
	void replace3(char str_main[], char str_find[], char str_replace[]);

	char s [100]= {'\0'}, f[100]= { '\0' }, r[100]= { '\0' };
	char* st, * fs, * rs;
	scanf_s("%s%s%s", s,100,f,100,r,100);
	st = s; fs = f; rs = r;
	//replace1(st, fs, rs);
	replace2(st, fs, rs);
	//replace3(st, fs, rs);
	printf("%s\n",s);
	return 0;
}
//��һ
void replace1(char* str, char* fstr, char* rstr)
{
	int i,j,k=0,len1,len2,len3,u,v;
	char* place = str;//ָ�����place�������ָ�����strĿǰ��ָ��Ԫ�صĵ�ַ��Ҳ���Ǵ��str��ָ����������Ԫ�صĵ�ַ���Ա��ں�����������ʹstr����ָ����һ��ַ
	char t[100] = { '\0' };//�ַ�����t��������ʱ���
	len1= strlen(fstr);
	printf("fstr=%d\n", len1);
	len2 = strlen(rstr);
	printf("rstr=%d\n", len2);
	len3= strlen(str);
	printf("str=%d\n", len3);
	for (k = 0; *str != '\0'; k++, str++)//��forѭ������str��ָ���ַ���������Ԫ��
		{
			if (*str == *fstr)//���str��ָ���ַ�����ĳ���ַ���fstr��ָ���ַ��������ַ���ͬ����Ƚ���fstr��ָ���ַ�����ͬ���ȵ��ַ���
			{
				printf("%d\n", k);
				for (i = 0; i < len1; i++)
				{
					t[i] = *(str + i);//��:��str��ָ���ַ����Ӹ�Ԫ�ؿ�ʼ����fstr��ָ���ַ���������ͬ���ַ������Ƶ�����t
				}
				printf("%s\n", t);
				if (strcmp(t, fstr) == 0)//�ٱȽ�����t��fstr��ָ���ַ����Ƿ���ͬ�������ͬ�������������滻����
				{
					for (j = len3 - 1; j >= k+len1; j--)
					{
						*(str - k + j + len2 - len1) = *(str - k + j);//�����滻�ַ���������ַ�������
					}
					*(str - k + len3 + len2 - len1) = '\0';
					for (u = k, v = 0; v < len2; u++, v++)
					{
						*(str - k + u) = *(rstr + v);//��rstr��ָ����ַ����滻
					}
					//printf("v=%d\n", v);
					//len3 = len3 + len2 - len1;
					//printf("len3=%d\n", len3);
					k = 0;//������k=0,��ʾ������һ���滻����
					break;//���ڵ�33~37�еĲ���ʹstr��ָ����ַ��������Ч���ȸı��ˡ��������break����������forѭ����������str��ָ���ַ�����ԭ������Ч���Ƚ��У����³�����˱���ʹ��break������ѭ����Ȼ���õ�48~51�е�if����ж��Ƿ���Ҫ�ٴ��滻��
				}
			}
		}
	str = place;//��str����ָ��str��ָ���������Ԫ��
	if (k == 0)//���k=0����ʾ�������滻����Ҫ����replace��������Ƿ���Ҫ�ٴ��滻�����k!=0����ʾ�Ѿ��滻��ɡ�
	{
		replace1(str, fstr, rstr);
	}
}
//������ʹ��flag��Best!!!
void replace2(char* str_main, char* str_find, char* str_replace)
{
	int i, j, k;
	int flag = 0;//�ҵ�str_find,��1������0

	int len_main = strlen(str_main);
	int len_find = strlen(str_find);
	int len_replace = strlen(str_replace);

	for (i = 0; str_main[i] != '\0'; i++)
	{
		//����str_find
		for (j = i, k = 0; str_main[j] == str_find[k]; j++, k++)
		{
			if (str_find[k + 1] == '\0')
			{
				flag = 1;
			}
		}

		if (flag)//�ҵ�str_find,��ʼ�滻
		{
			if (len_find <= len_replace)
			{
				for (j = len_main - 1; j >= i + len_find; j--)//�ȰѺ����Ԫ�� ���ҵ��� ����
				{
					str_main[j + len_replace - len_find] = str_main[j];
				}
				str_main[len_main + len_replace - len_find] = '\0';//��ĩβ����'\0'
				for (j = i, k = 0; str_replace[k] != '\0'; j++, k++)//�ٲ���
				{
					str_main[j] = str_replace[k];
				}
			}
			else//len_find>len_replace
			{
				for (j = i + len_find; j < len_main; j++)//�ȰѺ����Ԫ�� ������ ǰ��
				{
					str_main[j + len_replace - len_find] = str_main[j];
				}
				str_main[len_main + len_replace - len_find] = '\0';//��ĩβ����'\0'
				for (j = i, k = 0; str_replace[k] != '\0'; j++, k++)//�ٲ���
				{
					str_main[j] = str_replace[k];
				}
			}
			len_main = strlen(str_main);//���²ⳤ�ȡ��ؼ���
			flag = 0;//�滻��ϣ���λ
		}
	}
}
//����:��ʹ��flag,����һ��ѭ��
void replace3(char str_main[], char str_find[], char str_replace[])
{
	int i, j, k, p, q;
	char t;
	int len_main = strlen(str_main);
	int len_find = strlen(str_find);
	int len_replace = strlen(str_replace);
	for (i = 0; str_main[i] != '\0'; i++)
	{
		for (j = i, k = 0; str_main[j] == str_find[k]; j++, k++)
		{
			if (str_find[k + 1] == '\0')//���ҵ���str_find��ͬ�����ַ������ͽ����滻��str_replace
			{
				if (len_find <= len_replace)//���str_find��str_replace����
				{
					for (p = len_main - 1; p >= i - 1 + len_find; p--)//Ϊ�˱��⸲�ǣ����������������
					{
						str_main[p - len_find + len_replace] = str_main[p];
					}
					str_main[len_main - len_find + len_replace] = '\0';//�������Ͽ��ַ�
					len_main = strlen(str_main);//����len_main��������һ��ִ�е�������һ�У�����ͬһλ�ü��Ͽ��ַ���SUPER IMPORTANT!!!
				}
				else //���str_find��str_replace����
				{
					for (p = i - 1 + len_find; p <= len_main - 1; p++)//Ϊ�˱��⸲�ǣ����������������
					{
						str_main[p - len_find + len_replace] = str_main[p];
					}
					str_main[len_main - len_find + len_replace] = '\0';//�������Ͽ��ַ�
					len_main = strlen(str_main);//����len_main��������һ��ִ�е�������һ�У�����ͬһλ�ü��Ͽ��ַ���SUPER IMPORTANT!!!
				}
				for (p = i, q = 0; str_replace[q] != '\0'; p++, q++)
				{
					str_main[p] = str_replace[q];
				}
				break;
			}
		}
	}
}