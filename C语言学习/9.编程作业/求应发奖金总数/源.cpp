/*��ҵ���ŵĽ������������ɡ�����I���ڻ����100000Ԫ�ģ���������10%��
���� 100000�� I ��200000ʱ������100000Ԫ�Ĳ��ְ�10%��ɣ�����100000�Ĳ��֣������7.5%��
200000�� I ��400000ʱ������200000Ԫ�Ĳ����԰������취��ɣ���ͬ��������200000Ԫ�Ĳ��ְ�5%��ɣ�
400000�� I ��600000ʱ������400000Ԫ�Ĳ��ְ�3%��ɣ�
600000�� I ��1000000ʱ������600000Ԫ�Ĳ��ְ�1.5%��ɣ�
I��1000000ʱ������1000000Ԫ�Ĳ��ְ�1%��ɡ�
�Ӽ������뵱������I����Ӧ������������������λС����
(1)��if����д����
(2)��switch����д����*/
#include<stdio.h>
int main()
{
	double l;
	double bonus1,bonus2;
	double b1 = 1e5 * 0.1, b2 = b1 + (2e5 - 1e5) * 0.075, b3 = b2 + (4e5 - 2e5) * 0.05, b4 = b3 + (6e5 - 4e6) * 0.03, b5 = b4 + (10e5 - 6e5) * 0.015;
	scanf_s("%lf", &l);
	//if���
	if (l <= 1e5)
		bonus1 = l * 0.1;
	else if (l <= 2e5)
		bonus1 = b1 + (l - 1e5) * 0.075;
	else if (l <= 4e5)
		bonus1 = b2 + (l - 2e5) * 0.05;
	else if (l <= 6e5)
		bonus1 = b3 + (l - 4e5) * 0.03;
	else if (l <= 10e5)
		bonus1 = b4 + (l - 6e5) * 0.015;
	else
		bonus1 = b5 + (l - 10e5) * 0.01;
	printf("%.2lf", bonus1);
	//switch���
	int level = l / 1e5;
	switch (level)
	{
	case 0:bonus2 = l * 0.1; break;
	case 1:bonus2 = b1 + (l - 1e5) * 0.075; break;
	case 2:
	case 3:bonus2 = b2 + (l - 2e5) * 0.05; break;
	case 4:
	case 5:bonus2 = b3 + (l - 4e5) * 0.03; break;
	case 6:
	case 7:
	case 8:
	case 9:bonus2 = b4 + (l - 6e5) * 0.015; break;
	default:bonus2 = b5 + (l - 10e5) * 0.01;
	}
	printf("%.2lf", bonus2);
	return 0;
}