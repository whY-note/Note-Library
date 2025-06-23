#include<stdio.h>
#include<string.h>
int main()
{
	int i;
	char x[6] = {"China"};//如果写“x[5]” 则系统显示错误，因为没有多一个位置让系统自动放入'\0'
	char y[5] = { 'C','h','i','n','a' };//没有多一个位置让系统自动放入'\0'
	char z[6]= { 'C','h','i','n','a' };//还有一个位，系统自动放入'\0'
	char w[6]= { 'C','h','i','n','a','\0'};//人工放入'\0'
	char v[] = { 'C','h','i','n','a' };//系统自动定义为v[5],与y[5]相同
	char u[] = { "China" };//与w[6]相同
	printf("%%sx=%s\n", x);//1.1
	printf("%%sy=%s\n", y);//2.1。在“China”之后，有乱码字符
	printf("%%sz=%s\n", z);//3.1
	printf("%%sw=%s\n", w);//4.1 。1.1、3.1、4.1等效，在“China”之后，无乱码字符
	printf("%%sv=%s\n", v);
	printf("%%su=%s\n", u);
	for (i = 0; i < 6; i++)
	{
		printf("%%cx=%c ", x[i]);//1.2
	}
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		printf("%%cy=%c ", y[i]);//2.2。最后无“%cy= ”
	}
	printf("\n");
	for (i = 0; i < 6; i++)
	{
		printf("%%cz=%c ", z[i]);//3.2
	}
	printf("\n");
	for (i = 0; i < 6; i++)
	{
		printf("%%cw=%c ", w[i]);//4.2。1.2、3.2、4.2等效，最后都有 “%cw= ”
	}
	printf("\n");
	for (i = 0; i < 6; i++)
	{
		printf("%%cv=%c ", v[i]);
	}
	printf("\n");
	for (i = 0; i < 6; i++)
	{
		printf("%%cu=%c ", u[i]);
	}
	printf("\n");
	return 0;
}