#include<stdio.h>
int main()
{
	void for_while_do();
	int i=0,j;
	while (i< 10)
	{
		i++;//i�����о�+1
		printf("%d\n", i);
	}
	printf("while������i=%d\n", i);
	printf("\n");

	for(j=0;j<10;j++)
		printf("%d\n", j);//j����ִ����1��ѭ�����֮����+1
	printf("for������j=%d\n", j);
	printf("\n");
	
	for (j = 0; j < 10; j++)
	{
		if (j == 9)
		{
			printf("%d\n", j);
			break;
		}
	}
	printf("%d\n", j);
	for_while_do();
	return 0;
}
void for_while_do()//for,while,do-while���ߵıȽϡ�ע�⣺�ȼӻ��Ǻ��
{
	int a, b, c, d, i, j, k;
	a = 10;
	b = c = d = 5;
	i = j = k = 0;
	for (; a > b; ++b) i++;
	while (a > ++c) j++;
	do k++;
	while (a > d++);//do-while�ܳ�������һ��
	printf("i=%d,j=%d,k=%d\n", i, j, k);
}