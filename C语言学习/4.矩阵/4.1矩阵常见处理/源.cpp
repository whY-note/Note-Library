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
//4.1�����е�����
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
//4.2�����ת��
void transpose(int x[N][M], int T[M][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			T[j][i] = x[i][j];//���������i��j����
			
		}
	}
	for (j = 0; j < M; j++)
		for (i = 0; i < N; i++)
		{
			printf("%d\t", T[j][i] );
			if (i == N-1)//����ÿ�������Ǵ�T[j][0]��ʼ�����Ե�N��������T[j][N-1]
				printf("\n");
		}
	printf("\n");
}