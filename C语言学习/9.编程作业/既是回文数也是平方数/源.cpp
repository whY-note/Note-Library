/*找出所有满足以下特性的6位整数：它是一个完全平方数（完全平方数是指该数是某个整数的平方），
该数同时也是回文数（回文数是指该数等于它的反序数）。
例如，698896是836的平方并且698896是回文数，因此698896是满足所给条件的6位整数。
输出所有满足上述条件的6位整数。*/
#include<stdio.h>
#include<math.h>
int main()
{
	int num, i, j, t, n;
	int a[6] = { 0 };
	int r;
	for (num = 100000; num < 1000000; num++)
	{
		t = num;
		for (i = 0; t!=0&&i < 6; i++)
		{
			a[i] = t % 10;
			t = (int)t / 10;
		}
		n = a[0];
		for (j = 1; j < i; j++)
		{
			n = 10 * n + a[j];
		}
		r = sqrt(num);
		if (num == n && num == r * r)
			printf("%d ", num);
	}
	return 0;
}