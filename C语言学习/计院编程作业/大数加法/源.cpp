/*���������Ǹ�����a��b����������Ǹ������ĺ�(a+b)��
���ݹ�ģ:0<=a,b<=10��99�η�-1
*/

#include<stdio.h>
#include<string.h>


int main()
{
	//���ַ��������洢��������
	char num1[101] = { 0 }, num2[101] = { 0 };//���100λ����1λ������'\0'
	scanf_s("%s", num1, 100);
	scanf_s("%s", num2, 100);

	char result[102] = { '\0' };//Ϊ�˴洢���λ�Ľ�λ��num3Ҫ��1λ
	
	int len1 = strlen(num1);
	int len2 = strlen(num2);

	//i1,i2�ֱ�ָ��num1,num2������±�
	int i1 = len1 - 1;
	int i2 = len2 - 1;
	//i3ָ��result������±�-1,���1λ������'\0'
	int i3 = 101 - 1;
	//��λ���
	int jin = 0;

	/**************************************************************/
//��ʼ����
//ע�⣺����� ��λ ��ʼ�� ���λ ���㣬��Ӧ�������о��Ǵ� ����±� ��ʼ�� С���±� ����

	while (i1 >= 0 && i2 >= 0)//��2������δ����ʱ
	{
		int digit1 = num1[i1] - '0';
		int digit2 = num2[i2] - '0';
		int sum = digit1 + digit2 + jin;

		//�ж����޽�λ
		if (sum >= 10)
		{
			jin = 1;
			sum = sum - 10;
		}
		else
		{
			jin = 0;
		}
		result[i3] = sum + '0';

		//������1λ�������±�ǰ��1λ
		i3--;
		i2--;
		i1--;
	}

	//���num2�����ˣ���ֻ�ü���num1��ʣ��λ
	while (i1 >= 0)
	{
		int digit1 = num1[i1] - '0';
		int sum = digit1 + jin;

		//�ж����޽�λ
		if (sum >= 10)
		{
			jin = 1;
			sum = sum - 10;
		}
		else
		{
			jin = 0;
		}
		result[i3] = sum + '0';

		//������1λ�������±�ǰ��1λ
		i3--;
		i1--;
	}

	//���num1�����ˣ���ֻ�ü���num2��ʣ��λ
	while (i2 >= 0)
	{
		int digit2 = num2[i2] - '0';
		int sum = digit2 + jin;

		//�ж����޽�λ
		if (sum >= 10)
		{
			jin = 1;
			sum = sum - 10;
		}
		else
		{
			jin = 0;
		}
		result[i3] = sum + '0';

		//������1λ�������±�ǰ��1λ
		i3--;
		i2--;
	}

	//������1�ν�λ
	if (jin == 1)
	{
		result[i3] = 1 + '0';
	}

	//output
	for (int i=i3; i < 101; i++)
	{
		printf("%c", result[i]);
	}
	return 0;
}
