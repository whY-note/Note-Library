#include<stdio.h>
#define M 5
#define N 4
int main()
{
	void multiple(int x[N][M]);
	void transpose(int x[N][M],int T[M][N]);
	int matrix[N][M], matrix_T[M][N];
	multiple(matrix);
	transpose(matrix, matrix_T);
	return 0;
}
//4.1行与列的运算
void multiple(int x[N][M])
{
	int i, j;
	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++)
		{
			printf("%d\t", x[i-1][j-1]=i * j);
			if (j== M)
				printf("\n");
		}
	printf("\n");
}
//4.2矩阵的转置
void transpose(int x[N][M], int T[M][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			T[j][i] = x[i][j];//两个数组的i、j交换
			
		}
	}
	for (j = 0; j < M; j++)
		for (i = 0; i < N; i++)
		{
			printf("%d\t", T[j][i] );
			if (i == N-1)//由于每行数组是从T[j][0]开始，所以第N个数就是T[j][N-1]
				printf("\n");
		}
	printf("\n");
}