#include<stdio.h>
#include<string.h>
int main()
{
	int alphabetic(char c);
	int longest(char string[]);
	int i;
	char line[100];
	gets_s(line);
	for (i = longest(line); alphabetic(line[i]); i++)//������ʵ���ʼλ�ÿ�ʼ�����ֱ���ַ�������ĸ
		printf("%c", line[i]);
	return 0;
}
int alphabetic(char c)//�жϵ�ǰ�ַ��Ƿ�Ϊ��ĸ
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return(0);
}
int longest(char string[])//�������
{
	int len = 0;//len����ǰ�����Ѿ��ۼƵ���ĸ����
	int i;
	int lengh = 0;//lengh��ʾ֮ǰ�ĵ�������ĵ���
	int flag = 1;//flagΪ���ر�����flag=1��ʾ���ʿ�ʼ��flag=0��ʾ����δ��ʼ
	int place = 0;//place��ʾ����ʵ���ʼλ��
	int point;//point��ʾ��ǰ���ʵ���ʼλ��
	for (i = 0; i <=strlen(string); i++)// i <=strlen(string) �������Ҫȡ�Ⱥţ�����Ҫ���������������ĩβ�����!!!
	{
		if (alphabetic(string[i]))//������ĸ
		{
			if (flag)//���flag=1�����ʿ�ʼ
			{
				point = i;//���µ�������ĸ��λ��
				flag = 0;//��flag=0,��ʾ�µĵ���δ��ʼ�����ǵ�ǰ�ĵ���
			}
			else//���flag=0,���ǵ�ǰ�ĵ���
				len++;//��len+1���Ӷ����µ��ʵĳ���
		}
		else//���������ĸ������ǰһ�����ʽ�������Ƚϵ�ǰ����������ʵĳ���
		{
			flag = 1;
			if (len >= lengh)//�����ǰ�ĵ��ʱ�֮ǰ��ĵ��ʸ���
			{
				place = point;//����µ�ǰ���ʵ���ʼλ��
				lengh = len;//���µ�ǰ���ʵĳ���
				len = 0;//��len=0��Ȼ�����¼�¼�µ��ʵĳ���!!!
			}
		}
	}
	return (place);//return����ʵ���ʼλ��
}