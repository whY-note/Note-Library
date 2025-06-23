#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	//打开一个文件，从中读取一行
	FILE* f1; //定义文件指针
	char ch1;
	if ((f1 = fopen("E:/exampledata/exampleText2.txt", "r")) == NULL) //“r”是只读模式
	{
		printf("Cannot open this file.\n");
		exit(0);
	}
	while ((ch1 = fgetc(f1))!='\n')//从文件f1读入一个字符ch1
	{
		printf("%c:", ch1);
		printf("feof(f1):%d\n",feof(f1));
	}
	
	printf("\n");
	
	//从文件f1读入一个字符串
	char str1[10];
	fgets(str1, 10, f1); //从文件f1中读入一个长度为（10-1）的字符串到数组str，系统自动在数组str的最后一位添上'\0'
	printf("%s\n", str1);
	

	fclose(f1);  //关闭文件

	//打开一个文件，写入一个字符串
	FILE* f2;
	char ch, filename[50];
	printf("\n请输入文件名\n");
	scanf_s("%s", filename,50);
	getchar();//接收最后输入的回车符
	if ((f2 = fopen(filename, "w")) == NULL)
	{
		printf("Cannot open this file.\n");
		exit(0);
	}
	printf("请输入一个字符串，以#来结尾\n");
	ch = getchar();
	while (ch != '#')
	{
		fputc(ch, f2);  //把一个字符ch写入文件f2
		putchar(ch);
		ch = getchar();
	}
	fclose(f2);  //关闭文件

	//把一个字符串写入文件f3
	FILE *f3;
	if ((f3 = fopen(filename, "a")) == NULL)
	{
		printf("Cannot open this file.\n");
		exit(0);
	}
	char str2[10] = { 0 };
	printf("\n请输入一个字符串");
	gets_s(str2);
	fputs(str2, f3);
	fputc('\n', f3);
	fclose(f3);

	
	return 0;

}