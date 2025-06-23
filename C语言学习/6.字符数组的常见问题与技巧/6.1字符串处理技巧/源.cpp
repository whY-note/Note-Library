#include<stdio.h>
#include<string.h>
int main()
{
	char str1[20] = "abcdefghde";
	char str2[100] = "abmndeopdeanddeor";
	char str3[10] = "de";
	int frequent;
	int compare(char str_main[], char str_find[]);
	void connect(char str_main[], char str_add[]);
	void insert1(char str_main[], char str_in[], int place);
	void insert2(char str_main[], char str_in[], int place);
	frequent=compare(str1, str3);
	printf("frequent=%d\n", frequent);
	connect(str2, str1);
	printf("%s\n", str2);
	insert1(str1, str3, 2);
	printf("%s\n",str1);
	insert2(str1, str3, 1);
	printf("%s\n", str1);
	return 0;
}
//һ��Ѱ�����ַ���str_find,��ͳ������ִ���
int compare(char str_main[], char str_find[])
{
	int len_main = strlen(str_main);
	int len_find = strlen(str_find);
	int i, j, k;
	int frequent = 0;//���ִ���
	for (i = 0; i < len_main;i++)
	{
		for (j = i, k = 0; str_main[j] == str_find[k]; j++, k++)//�ؼ�:str_main[j] == str_find[k]����!
		{
			if (str_find[k + 1] == '\0')//��str_find����ʱ�����ִ���+1
			{
				frequent++;//��һ����ͳ�Ƴ��ִ��������Ի�����������
				break;//!!!�ؼ�������break����str_main�����ַ������δ֪�ַ����ܻᱻ�����
			}
		}
	}
	return (frequent);
}
//�����ַ���ƴ��
void connect(char str_main[], char str_add[])
{
	int i = 0,j = 0;
	while (str_main[i])
		i++;          /*����д�ɡ�while(a[i++]);//��Ϊϵͳ��ػ�ִ��һ��while( )�ڵ��ж���䣬�������a[i++]==0,i�Ի�+1�����Դ�whileѭ����������Ҫi=i-1
					   i = i - 1; ��*/

	while (str_main[i++] = str_add[j++]);//�ȼ��� while ((str_main[i++] = str_add[j++])!='\0');
}

//���������ַ��� 
//��һ:�Ⱥ��ƣ��ٲ���
void insert1(char str_main[], char str_in[], int place)//place�ǲ����λ��,��ʾ�ڵ�place���ַ��������
{
	int i, j;
	int len_main = strlen(str_main);
	int len_in=strlen(str_in);
	for (i = len_main - 1; i >= place; i--)
		str_main[i + len_in] = str_main[i];//�Ƚ�str_main�ڲ���λ��֮���Ԫ�������
	for (j = 0,i=place; str_in[j] != '\0'; j++, i++)
	{
		str_main[i] = str_in[j];//�ٲ���str_in
	}
}
//����:�����ⴢ�棬�ٲ���
void insert2(char str_main[], char str_in[], int place)
{
	int i, j, k;
	char str_help[100] = { 0 };
	for (i = place,k=0; str_main[i] != '\0'; i++,k++)
	{
		str_help[k] = str_main[i];//�Ƚ�str_main�ڲ���λ��֮���Ԫ�ش�����str_help
	}
	str_help[k] = '\0';
	for (i = place, j = 0; str_in[j] != '\0'; i++, j++)
	{
		str_main[i] = str_in[j];//�ٲ���str_in
	}
	for (k = 0; str_help[k] != '\0'; k++, i++)
	{
		str_main[i] = str_help[k];//���str_help�ڵ�Ԫ�ط��ں���
	}
}