#include<stdio.h>
#include<string.h>
int main()
{
	struct Stu
	{
		char name[5];
	}s[2] = {0};
	int i;
	//scanf_s("%s", s[0].name,5);//���뷨һ��scanf %s�������ã�����
	for (i = 0; i < 2; i++)//���뷨����gets��//������ע�⣬���ڿո�Ҳ�ܱ����gets���棬��������ʱ�ַ����ĺ��������лس��������ַ�������Ķ���Ҳ�ᱻgets���գ����ܵ����ַ�������Խ��
	{
		gets_s(s[i].name);
	}
	for (i = 0; i < 2; i++)
	{
		printf("%s\n", s[i].name);
	}
	return 0;
}