#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	//��һ���ļ������ж�ȡһ��
	FILE* f1; //�����ļ�ָ��
	char ch1;
	if ((f1 = fopen("E:/exampledata/exampleText2.txt", "r")) == NULL) //��r����ֻ��ģʽ
	{
		printf("Cannot open this file.\n");
		exit(0);
	}
	while ((ch1 = fgetc(f1))!='\n')//���ļ�f1����һ���ַ�ch1
	{
		printf("%c:", ch1);
		printf("feof(f1):%d\n",feof(f1));
	}
	
	printf("\n");
	
	//���ļ�f1����һ���ַ���
	char str1[10];
	fgets(str1, 10, f1); //���ļ�f1�ж���һ������Ϊ��10-1�����ַ���������str��ϵͳ�Զ�������str�����һλ����'\0'
	printf("%s\n", str1);
	

	fclose(f1);  //�ر��ļ�

	//��һ���ļ���д��һ���ַ���
	FILE* f2;
	char ch, filename[50];
	printf("\n�������ļ���\n");
	scanf_s("%s", filename,50);
	getchar();//�����������Ļس���
	if ((f2 = fopen(filename, "w")) == NULL)
	{
		printf("Cannot open this file.\n");
		exit(0);
	}
	printf("������һ���ַ�������#����β\n");
	ch = getchar();
	while (ch != '#')
	{
		fputc(ch, f2);  //��һ���ַ�chд���ļ�f2
		putchar(ch);
		ch = getchar();
	}
	fclose(f2);  //�ر��ļ�

	//��һ���ַ���д���ļ�f3
	FILE *f3;
	if ((f3 = fopen(filename, "a")) == NULL)
	{
		printf("Cannot open this file.\n");
		exit(0);
	}
	char str2[10] = { 0 };
	printf("\n������һ���ַ���");
	gets_s(str2);
	fputs(str2, f3);
	fputc('\n', f3);
	fclose(f3);

	
	return 0;

}