/*дһ��������ʹ�����һ���ַ����������ţ��������������������ַ���*/
#include<stdio.h>
#include<string.h>
int main()
{
	void inverse(char* p, int len);
	char s[100] = { 0 };
	char* p=s;
	int len;
	gets_s(s);
	len = strlen(s);
	inverse(p, len);
	printf("%s", s);
	return 0;
}
void inverse(char* p, int len)
{
	char* i, * j,t;//ע�⣺�����t����ͨ���������ǵ�ַ����������
	for (i = p, j = p + len - 1; i <= p + (len - 1) / 2; i++, j--)
	{
		t = *i;
		*i = *j;
		*j = t;
	}
}