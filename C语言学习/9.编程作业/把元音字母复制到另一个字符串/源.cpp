/*дһ���������书���ǣ���һ���ַ����е�Ԫ����ĸ���Ƶ���һ���ַ�����
���������������ַ����������Զ��庯����Ȼ����������������������ַ�����
*/
#include<stdio.h>
int main()
{
	void yuan(char x[], char y[]);
	char x[100] = { 0 }, y[100] = { 0 };
	gets_s(x);
	yuan(x, y);
	puts(y);
	return 0;
}
void yuan(char x[], char y[])
{
	int i, j=0;
	for (i = 0; x[i] != '\0'; i++)
	{
		if (x[i] == 'a' ||x[i] == 'A' || x[i] == 'e'|| x[i] == 'E' || x[i] == 'i' || x[i] == 'I' || x[i] == 'o' || x[i] == 'O' || x[i] == 'u' || x[i] == 'U' )
		{
			y[j] = x[i];
			j++;
		}
	}
}