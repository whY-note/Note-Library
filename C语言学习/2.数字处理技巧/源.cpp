#include<stdio.h>
#include<math.h>
int main()
{
	//2.1���λ����
	//ȡ����
	int num, a;
	int i, j;
	int each[10] = { 0 };//each�������ڴ�Ÿ�λ����
	scanf_s("%d", &num);
	a = num;
	for (i = 0; a != 0 && i < 10; i++)
	{
		each[i] = a % 10;//���ĩλ���֣���������each�����С���ˣ�a��ÿһ��������each�������������ŵġ�
		a = (int)a / 10;//a��Ϊȥ��ĩλ����֮�����
	}
	printf("each number is: ");
	for (j = i - 1; j >= 0; j--)//ע��j�ǵ���ģ�����
	{
		printf("%d ", each[j]);
	}
	printf("\n");

	//2.2�жϻ�����
	//��Ҫ���Ѿ������λ����֮�����
	int inverse = each[0];
	int k;
	for (k = 1; k < i; k++)//ע��k������ģ�����
	{
		inverse = inverse * 10 + each[k];
	}
	printf("inverse=%d\n", inverse);//inverse��Ϊ�������
	if (inverse == num)//�ж��ǲ��ǻ�����
		printf("Yes,%d is a palindromic number\n",num);
	else
		printf("No,%d is not a palindromic number\n", num);

	//2.3�ж���ȫƽ����
	//�ȿ�������ȡ������ƽ��
	int root = sqrt(num);//ϵͳ�Զ���sqrt(num)ȡ��
	if (num == root * root)//�ж��ǲ�����ȫƽ����
		printf("Yes,%d is a perfect squre number\n", num);
	else
		printf("No,%d is not a perfect squre number\n", num);

	//2.4����������
	int divisor[20] = { 0 };//divisor�������ڴ������
	j = 0;
	printf("The divisors of %d are:", num);
	for (i = 1; i < num; i++)
	{
		if (num % i == 0)
		{
			divisor[j] = i;
			printf("%d ", divisor[j]);//�����������ʱʹ�õģ�����Ҫ����������У�����Բ�������
			j++;
		}
	}
	return 0;
}