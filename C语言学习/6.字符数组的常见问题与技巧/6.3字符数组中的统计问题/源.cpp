#include<stdio.h>
#include<string.h>
int main()
{
	char str[100] = { 0 };
	//һ��ͳ�Ƶ��ʸ���
	int i, num = 0, word = 0;//word�ǿ��ر�����word==0��ʾ��ǰ���ǵ��ʣ�word==1��ʾ��ǰ�ǵ���
	gets_s(str);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			word = 0;
		else //str[i]���ǿո�
			if (word == 0)/*��ʱ��word��ǰһ���жϺ�ó��Ľ��������ʾǰһ���ַ��ǲ��ǿո�
						  ������ж���else�����ж϶����������ʾǰһ���ַ��ǿո񣬵�ǰ�ַ�����ĸ*/
			{
				word = 1;
				num++;
			}
	}
	printf("%d", num);
	//����ͳ�Ƹ������ַ��ĳ��ִ���
	char c[3][80];
	int i, j, k = 0, d = 0, x = 0, t = 0, s = 0;
	gets_s(c[0]);
	gets_s(c[1]);
	gets_s(c[2]);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; c[i][j] != '\0'; j++)//�ؼ�:c[i][j]!='\0',�ԡ�j<80����������
		{
			if (c[i][j] >= 'A' && c[i][j] <= 'Z')//ͳ�ƴ�д��ĸ
				d++;
			else if (c[i][j] >= 'a' && c[i][j] <= 'z')//ͳ��Сд��ĸ
				x++;
			else if (c[i][j] == ' ')//ͳ�ƿո�
				k++;
			else if (c[i][j] >= '0' && c[i][j] <= '9')//ͳ������
				s++;
			else if (c[i][j] != '\0')//ͳ�������ַ�
				t++;
		}
	}
	printf("upper case:%d\nlower case:%d\ndigit:%d\nspace:%d\nother:%d\n", d, x, s, k, t);
	return 0;
}