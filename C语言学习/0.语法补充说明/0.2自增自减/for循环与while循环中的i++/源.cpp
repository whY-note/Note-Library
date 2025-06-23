#include<stdio.h>
int main()
{
	void for_while_do();
	int i=0,j;
	while (i< 10)
	{
		i++;//i在这行就+1
		printf("%d\n", i);
	}
	printf("while结束后，i=%d\n", i);
	printf("\n");

	for(j=0;j<10;j++)
		printf("%d\n", j);//j是在执行完1次循环语句之后再+1
	printf("for结束后，j=%d\n", j);
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
void for_while_do()//for,while,do-while三者的比较。注意：先加还是后加
{
	int a, b, c, d, i, j, k;
	a = 10;
	b = c = d = 5;
	i = j = k = 0;
	for (; a > b; ++b) i++;
	while (a > ++c) j++;
	do k++;
	while (a > d++);//do-while能超域运算一次
	printf("i=%d,j=%d,k=%d\n", i, j, k);
}