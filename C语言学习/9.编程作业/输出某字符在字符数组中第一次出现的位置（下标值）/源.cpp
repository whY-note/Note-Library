/*��main�����У�ͨ�����̷ֱ�����ַ�������󳤶Ȳ���3 0������ĸ������)��һ���ַ���
�����Զ��庯�� findlet���ַ������д���
Ȼ����main��������� �����ַ����ַ������е�һ�γ��ֵ�λ�ã��±�ֵ������û�и��ַ��������-1����
���� void findlet(char *str, char * let, int *order) �Ĺ��ܣ�
���ָ��strָ����ַ����飬�ҵ�ָ��let��ָ����ַ��ڸ��ַ������е�һ�γ��ֵ�λ�ã��±�ֵ��
����û�и��ַ��������-1�������Ѹ��±�ֵ�洢��ָ��order��ָ��ı�����

���ַ��� ��12a89aaRry6ru���У���ĸa��һ�γ��ֵ��±�ֵΪ2������ĸbû�г��֣��±�ֵΪ-1��
��Ҫ����������ע�͡�
ʾ����
���룺
12a89aaRry6ru
a
�����
2
*/
#include<stdio.h>
int main()
{
	void findlet(char* str, char* let, int* order);
	int order=-1,* p=&order;
	char c, * pc = &c;
	char s[100] = { 0 };
	gets_s(s);
	scanf_s("%c", pc);
	findlet(s, pc, p);
	printf("%d", *p);
	return 0;
}
void findlet(char* str, char* let, int* order)
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == *let)
		{
			*order = i;
		}
	}
}