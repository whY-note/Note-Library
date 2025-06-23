#include<stdio.h>
#include<stdlib.h>

/*求出两个矩阵的异或*/
int** XOR(int** mat1, int** mat2, int m, int n, int p);

int main()
{
	int m = 2, n = 2, p = 2;
	int** matrix1 = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++)
	{
		matrix1[i] = (int*)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++)
		{
			if (i == j) matrix1[i][j] = 1;
			else matrix1[i][j] = 0;
		}
	}
	int** matrix2 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		matrix2[i] = (int*)malloc(p * sizeof(int));
		for (int j = 0; j < p; j++)
		{
			if (i == j) matrix2[i][j] = 1;
			else matrix2[i][j] = 1;
		}
	}


	int** res = XOR(matrix1, matrix2, 2, 2, 2);
	for (int i = 0; i < m; i++)
	{

		for (int j = 0; j < p; j++)
		{
			printf("%d ", res[i][j]);
		}
		putchar('\n');
	}
	return 0;
}

int** XOR(int** mat1, int** mat2, int m, int n, int p)
{
	int** result = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++)
	{
		result[i] = (int*)malloc(p * sizeof(int));
		for (int j = 0; j < p; j++)
		{
			result[i][j] = mat1[i][j] ^ mat2[i][j];
		}
	}
	return result;
}