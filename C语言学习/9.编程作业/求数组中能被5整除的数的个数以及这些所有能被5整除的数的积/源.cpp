/*编写函数fun(int *p1,int *p2,int *p3)，
其功能是：求p1所指一维数组中的所有能被5整除的数的个数,以及这些所有能被5整除的数的积；
分别将所求得的个数以及积通过指针p2和p3返回主函数。
主函数中，由键盘输入3个整数存入一维数组, 调用函数fun后, 在主函数输出最后的结果。
例如: 
输入: 10 2 5
输出: 2  50
*/
#include<stdio.h>
int main()
{
	void fun(int* p1, int* p2, int* p3);
	int a[3] = { 0 };
	int i, n=0, mul=1;
	int* pn = &n, * pm = &mul;
	for (i = 0; i < 3; i++)
	{
		scanf_s("%d", &a[i]);
	}
	fun(a, pn, pm);
	printf("%d %d", *pn, *pm);
	return 0;
}
void fun(int* p1, int* p2, int* p3)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (p1[i] % 5 == 0)
		{
			(*p2)++;
			*p3 = (*p3) * p1[i];
		}
	}
}