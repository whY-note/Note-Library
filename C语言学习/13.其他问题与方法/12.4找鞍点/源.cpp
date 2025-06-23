#include<stdio.h>
#define N 4
#define M 5
int main()
{
	int a[N][M] = { {41,2,18,40,23},{19,21,22,39,33},{15,11,9,41,3},{31,35,40,51,10} };
	int i, j, k;
	int max, an_place[2];
	for (i = 0; i < N; i++)
	{
		max = a[i][0];
		an_place[0] = i;
		an_place[1] = 0;
		for (j = 1; j < M; j++)
		{
			(a[i][j] > max) ? (max = a[i][j], an_place[1] = j) : (max = max);
		}
		int flag = 1;
		for (k = 1; k < N; k++)
		{
			if (a[k][an_place[1]] < a[an_place[0]][an_place[1]])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			printf("°°µã×ø±ê(%d,%d)", an_place[0] + 1, an_place[1] + 1);
		}
	}
	return 0;
}

