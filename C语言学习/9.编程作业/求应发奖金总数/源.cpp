/*企业发放的奖金根据利润提成。利润I低于或等于100000元的，奖金可提成10%；
利润 100000≤ I ≤200000时，低于100000元的部分按10%提成，高于100000的部分，可提成7.5%；
200000＜ I ≤400000时，低于200000元的部分仍按上述办法提成（下同）。高于200000元的部分按5%提成；
400000＜ I ≤600000时，高于400000元的部分按3%提成；
600000＜ I ≤1000000时，高于600000元的部分按1.5%提成；
I＞1000000时，超过1000000元的部分按1%提成。
从键盘输入当月利润I，求应发奖金总数，保留两位小数。
(1)用if语句编写程序。
(2)用switch语句编写程序。*/
#include<stdio.h>
int main()
{
	double l;
	double bonus1,bonus2;
	double b1 = 1e5 * 0.1, b2 = b1 + (2e5 - 1e5) * 0.075, b3 = b2 + (4e5 - 2e5) * 0.05, b4 = b3 + (6e5 - 4e6) * 0.03, b5 = b4 + (10e5 - 6e5) * 0.015;
	scanf_s("%lf", &l);
	//if语句
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
	//switch语句
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