//�����ļ�
//˼·���������ļ������ļ�infile������д���ļ�outfile
#define _CRT_SECURE_NO_WARNINGS //fopen������unsafe�����Լ��ϴ˾�
#include<stdio.h>
#include<stdlib.h>  //exit()���������ͷ�ļ���
int main()
{
	FILE* infile, * outfile;
	char ch, infile_name[50], outfile_name[50];
	printf("���뱻�����ļ����ļ���:");
	scanf_s("%s", infile_name, 50);
	if ((infile = fopen(infile_name, "r")) == NULL)
	{
		printf("�޷��򿪴��ļ�\n");
		exit(0);
	}
	printf("���븴�Ƶ����ļ����ļ���:");
	scanf_s("%s", outfile_name, 50);
	if ((outfile = fopen(outfile_name, "w")) == NULL)
	{
		printf("�޷��򿪴��ļ�\n");
		exit(0);
	}
	while (!feof(infile))  //feof(infile)��ʾ�ļ����� 
	{
		ch = fgetc(infile);
		fputc(ch, outfile);
		putchar(ch);
	}
	fclose(infile);
	fclose(outfile);
	return 0;
}
