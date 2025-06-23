/*企业发放的奖金根据利润提成。利润l低于或等于100000元的，奖金可提成10% ；
利润为100000≤ l ≤200000时，低于100000元的部分按10% 提成，高于100000的部分，可提成7.5 % ；
200000＜ l ≤400000时，低于200000元的部分仍按上述办法提成，高于200000元的部分按5 % 提成；
400000＜ l ≤600000元时，高于400000元的部分按3 % 提成；
600000＜ l ≤1000000时，高于600000元的部分按1.5 % 提成；
l＞1000000时，超过1000000元的部分按1 % 提成。

从键盘输入当月利润l，求应发奖金总数，保留两位小数。
*/

#include<stdio.h>
int main()
{
	double l,bonus1,bonus2;
	double bon1 = 1e5 * 10.0 / 100, bon2 = bon1 + (2e5 - 1e5) * 7.5 / 100, bon3 = bon2 + (4e5 - 2e5) * 5.0 / 100, bon4 = bon3 + (6e5 - 4e5) * 3.0 / 100, bon5 = bon4 + (10e5 - 6e5) * 1.5 / 100;
	scanf_s("%lf", &l);
	//法一：if else语句
	if (l <= 1e5)
		bonus1 = l * 10.0 / 100;//注意：一定不能写成“10/100”，因为系统会默认以整数存储，也就是0！！！要写成“10.0/100”或“10/100.0”或“10.0/100.0”皆可
	else if (l <= 2e5)
		bonus1= bon1 + (l - 1e5) * 7.5 / 100;
	else if (l <= 4e5)
		bonus1 = bon2 + (l - 2e5) * 5.0 / 100;
	else if (l <= 6e5)
		bonus1 = bon3 + (l - 4e5) * 3.0 / 100;
	else if (l <= 10e5)
		bonus1 = bon4 + (l - 6e5) * 1.5 / 100;
	else
		bonus1= bon5 + (l - 10e5) * 1.0 / 100;
	printf("bonus1=%.2lf\n", bonus1);
	//法二：switch语句
	int level = (int)l / 1e5;//处理原始数据，变成等级
	switch (level)//switch后的括号内必须是整型数据，因此必须先处理原始数据，变成等级
	{
	case 0:bonus2 = l * 10.0 / 100; break;
	case 1:bonus2 = bon1 + (l - 1e5) * 7.5 / 100; break;
	case 2:
	case 3:bonus2 = bon2 + (l - 2e5) * 5.0 / 100; break;
	case 4:
	case 5:bonus2 = bon3 + (l - 4e5) * 3.0 / 100; break;
	case 6:
	case 7:
	case 8:
	case 9:bonus2 = bon4 + (l - 6e5) * 1.5 / 100; break;
	default:bonus2 = bon5 + (l - 10e5) * 1.0 / 100; break;
	}
	printf("bonus2=%.2lf\n", bonus2);
	return 0;

}
