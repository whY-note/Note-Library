/*дһ������������һ���ַ������ո񣩣��ܹ��ҵ��ַ�������ĵ��ʡ�
�������У������ַ����������Զ��庯���������ĵ��ʡ�
�������룺a aa aaa aaaa
�����aaaa
*/
#include<stdio.h>
int main()
{
	int longest(char str[]);
	char s[100] = { 0 };
	int i;
	gets_s(s);
	for(i =longest(s); s[i] != '\0' && s[i] != ' '; i++)
	{
		printf("%c", s[i]);
	}
	return 0;
}
int longest(char str[])
{
	int place=0,i,flag=0;
	int len=0, max_len =0,max_place=0;
	for (i = 0; str[i] != '\0'; i++)
	{
		place = i;
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))//�ж��ǲ�����ĸ
		{
			if (flag == 0)
			{
				flag = 1;
				len++;
			}
			else
				len++;
		}
		else//��������ַ��������������
		{
			flag = 0;
			(len > max_len) ?(max_len=len,max_place=place-len) :(max_len = max_len);//ע�⣺��max_place=place-len������Ϊ��ʱ��place�����ַ����ĺ�һ�����ַ�
			len = 0;
		}
		if (str[i + 1] == '\0')//��������ַ������������
		{
			(len > max_len) ? (max_len = len, max_place = place - len+1) : (max_len = max_len);//ע�⣺��max_place = place - len+1������Ϊ��ʱ��place�����ַ��������һ���ַ�
		}
	}
	return (max_place);
}