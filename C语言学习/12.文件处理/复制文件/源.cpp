//复制文件
//思路：打开两个文件，把文件infile的内容写入文件outfile
#define _CRT_SECURE_NO_WARNINGS //fopen会引发unsafe，所以加上此句
#include<stdio.h>
#include<stdlib.h>  //exit()函数在这个头文件里
int main()
{
	FILE* infile, * outfile;
	char ch, infile_name[50], outfile_name[50];
	printf("输入被复制文件的文件名:");
	scanf_s("%s", infile_name, 50);
	if ((infile = fopen(infile_name, "r")) == NULL)
	{
		printf("无法打开此文件\n");
		exit(0);
	}
	printf("输入复制到的文件的文件名:");
	scanf_s("%s", outfile_name, 50);
	if ((outfile = fopen(outfile_name, "w")) == NULL)
	{
		printf("无法打开此文件\n");
		exit(0);
	}
	while (!feof(infile))  //feof(infile)表示文件结束 
	{
		ch = fgetc(infile);
		fputc(ch, outfile);
		putchar(ch);
	}
	fclose(infile);
	fclose(outfile);
	return 0;
}
