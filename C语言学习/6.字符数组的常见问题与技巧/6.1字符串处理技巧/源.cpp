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
//一、寻找子字符串str_find,并统计其出现次数
int compare(char str_main[], char str_find[])
{
	int len_main = strlen(str_main);
	int len_find = strlen(str_find);
	int i, j, k;
	int frequent = 0;//出现次数
	for (i = 0; i < len_main;i++)
	{
		for (j = i, k = 0; str_main[j] == str_find[k]; j++, k++)//关键:str_main[j] == str_find[k]！！!
		{
			if (str_find[k + 1] == '\0')//当str_find结束时，出现次数+1
			{
				frequent++;//不一定是统计出现次数，可以换成其他操作
				break;//!!!关键：若无break，则str_main已有字符后面的未知字符可能会被算进来
			}
		}
	}
	return (frequent);
}
//二、字符串拼接
void connect(char str_main[], char str_add[])
{
	int i = 0,j = 0;
	while (str_main[i])
		i++;          /*或者写成“while(a[i++]);//因为系统会必会执行一次while( )内的判断语句，所以如果a[i++]==0,i仍会+1，所以此while循环结束后，需要i=i-1
					   i = i - 1; ”*/

	while (str_main[i++] = str_add[j++]);//等价于 while ((str_main[i++] = str_add[j++])!='\0');
}

//三、插入字符串 
//法一:先后移，再插入
void insert1(char str_main[], char str_in[], int place)//place是插入的位置,表示在第place个字符后面插入
{
	int i, j;
	int len_main = strlen(str_main);
	int len_in=strlen(str_in);
	for (i = len_main - 1; i >= place; i--)
		str_main[i + len_in] = str_main[i];//先将str_main在插入位置之后的元素向后移
	for (j = 0,i=place; str_in[j] != '\0'; j++, i++)
	{
		str_main[i] = str_in[j];//再插入str_in
	}
}
//法二:先另外储存，再插入
void insert2(char str_main[], char str_in[], int place)
{
	int i, j, k;
	char str_help[100] = { 0 };
	for (i = place,k=0; str_main[i] != '\0'; i++,k++)
	{
		str_help[k] = str_main[i];//先将str_main在插入位置之后的元素储存在str_help
	}
	str_help[k] = '\0';
	for (i = place, j = 0; str_in[j] != '\0'; i++, j++)
	{
		str_main[i] = str_in[j];//再插入str_in
	}
	for (k = 0; str_help[k] != '\0'; k++, i++)
	{
		str_main[i] = str_help[k];//最后将str_help内的元素放在后面
	}
}