/*����ķ˹����������Armstrong number����Ҳ��Ϊ������������
һ��nλ���ǰ�ķ˹��������������������λ���ֵ�n�η��͡�
���磬153��һ��3λ�İ�ķ˹��������
���дһ�������ҳ� [0,999] ��Χ�����еİ�ķ˹������������ӡ���ǡ�*/

#include<stdio.h>
#include<math.h>

bool isArmstrong(int n);

int main()
{
	for (int i = 0; i < 1000; i++)
	{
		if (isArmstrong(i))
		{
			printf("%d ", i);
		}
	}
	return 0;
}

bool isArmstrong(int n)
{
	int wei = 0;
	if (n < 10) wei = 1;
	else if (n < 100) wei = 2;
	else if (n < 1000) wei = 3;

	int nn = n;
	int n_new = 0;
	while (nn != 0)
	{
		n_new += (int)pow((nn % 10),wei);
		nn /= 10;
	}
	if (n_new == n) return 1;
	else return 0;


}