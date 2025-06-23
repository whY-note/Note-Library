#include<stdio.h>
#include<math.h>
int main()
{
	//2.1求各位数字
	//取整法
	int num, a;
	int i, j;
	int each[10] = { 0 };//each数组用于存放各位数字
	scanf_s("%d", &num);
	a = num;
	for (i = 0; a != 0 && i < 10; i++)
	{
		each[i] = a % 10;//求出末位数字，并储存在each数组中。因此，a的每一个数字在each数组中是逆序存放的。
		a = (int)a / 10;//a变为去除末位数字之后的数
	}
	printf("each number is: ");
	for (j = i - 1; j >= 0; j--)//注意j是倒序的！！！
	{
		printf("%d ", each[j]);
	}
	printf("\n");

	//2.2判断回文数
	//需要在已经求出各位数字之后进行
	int inverse = each[0];
	int k;
	for (k = 1; k < i; k++)//注意k是正序的！！！
	{
		inverse = inverse * 10 + each[k];
	}
	printf("inverse=%d\n", inverse);//inverse即为反序的数
	if (inverse == num)//判断是不是回文数
		printf("Yes,%d is a palindromic number\n",num);
	else
		printf("No,%d is not a palindromic number\n", num);

	//2.3判断完全平方数
	//先开方，再取整，后平方
	int root = sqrt(num);//系统自动对sqrt(num)取整
	if (num == root * root)//判断是不是完全平方数
		printf("Yes,%d is a perfect squre number\n", num);
	else
		printf("No,%d is not a perfect squre number\n", num);

	//2.4求所有因子
	int divisor[20] = { 0 };//divisor数组用于存放因子
	j = 0;
	printf("The divisors of %d are:", num);
	for (i = 1; i < num; i++)
	{
		if (num % i == 0)
		{
			divisor[j] = i;
			printf("%d ", divisor[j]);//如果因子是临时使用的，不需要存放在数组中，则可以不用数组
			j++;
		}
	}
	return 0;
}