#include<stdio.h>
#include<stdlib.h>
#define M 2
#define N 3
#define P 4


void matrix_multiple1(int(*p1)[N], int(*p2)[P], int(*p3)[P]);//用3个形参，其中一个存储返回值
int** matrix_multiple2(int(*p1)[M][N], int(*p2)[N][P]);//用2个形参,返回指针的指针
int(*matrix_multiple3(int(*p1)[100][100], int(*p2)[100][100]))[100][100];//用2个形参，返回指向2维数组的指针
int** matrix_multiple4(int** A, int** B);

int main()
{
	int i, j;
	int a[M][N] = { {1,2,3},{2,3,4} };
	int b[N][P] = { {1,2,3,4},{2,3,4,5},{3,4,5,6} };
	int c[M][P] = { 0};

	printf("法一:\n");
	matrix_multiple1(a, b, c);
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < P; j++)
		{
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}

	printf("法二:\n先开辟一块动态存储空间，但是不知为什么输出会有乱码？\n");
	int** pm2;
	pm2=matrix_multiple2(&a, &b);
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < P; j++)
		{
			printf("%d ",pm2[i][j]);
		}
		printf("\n");
	}

	printf("法三:\n");
	int(*pm3)[100][100];
	int mt1[100][100] = { {1,2,3},{2,3,4} }, mt2[100][100] = { {1,2,3,4},{2,3,4,5},{3,4,5,6} };
	pm3 = matrix_multiple3(&mt1, &mt2);
	
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < P; j++)
		{
			printf("%d ", (*pm3)[i][j]);
		}
		printf("\n");
	}

	//法四：指针的指针
	printf("法四：指针的指针\n");
	int* pa_hang[M];//指向矩阵a的每一行
	for (int i = 0; i < M; i++)
	{
		pa_hang[i] = a[i];
	}
	int** pa = pa_hang;//指向矩阵a

	int* pb_hang[N];//指向矩阵b的每一行
	for (int i = 0; i < N; i++)
	{
		pb_hang[i] = b[i];
	}
	int** pb = pb_hang;//指向矩阵b


	int** pc = matrix_multiple4(pa, pb);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < P; j++)
		{
			printf("%d ", pc[i][j]);
		}
		printf("\n");
	}

	return 0;
}
//法一
void matrix_multiple1(int(*p1)[N], int(*p2)[P], int(*p3)[P])//用3个形参，其中一个存储返回值
{
	/*
	* 参数说明：
	* int(*p1)[N]: M x N matrix
	* int(*p2)[P]: N x P matrix
	* int(*p3)[P]: M x P matrix
	*/
	
	int i, j, k;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < P; j++)
		{
			for (k = 0; k < N; k++)
			{
				*(*(p3 + i) + j) = *(*(p3 + i) + j) + *(*(p1 + i) + k) * (*(*(p2 + k) + j));
			}
		}
	}
}

//法二
int** matrix_multiple2(int(*p1)[M][N], int(*p2)[N][P])//用2个形参,返回指针的指针
{
	int i, j, k;
	//先开辟一块动态存储空间，但是不知为什么输出会有乱码？
	int** p = (int**)calloc(N ,sizeof(int*));
	
	for (int i = 0; i < N; i++)
	{
		p[i] = (int*)calloc(M , sizeof(int));//p[i]可以换成*(p+i)
	}
	
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < P; j++)
		{
			for (k = 0; k < N; k++)
			{
				p[i][j] = p[i][j] + (*p1)[i][k] * (*p2)[k][j];
			}
		}
	}
	return p;
}
//法三
int(* matrix_multiple3(int(*p1)[100][100], int(*p2)[100][100]))[100][100] //用2个形参，返回指向2维数组的指针
{
	int mt[100][100] = {};

	int(*p0)[100][100] = &mt;
	for (int i = 0; i < M; i++)
		for (int k = 0; k < P; k++)
			for (int j = 0; j < N; j++)
				(*p0)[i][k] += (*p1)[i][j] * (*p2)[j][k];
	return p0;
}

//法四：指针的指针
int** matrix_multiple4(int** A, int** B)
{
	int** C = (int**)malloc(M * sizeof(int*));
	for (int i = 0; i < M; i++)
	{
		C[i] = (int*)malloc(P * sizeof(int));

		for (int k = 0; k < P; k++)
		{
			*(*(C + i) + k) = 0;  //初始化为0，一定要有，否则乱码
			for (int j = 0; j < N; j++)
			{
				*(*(C + i) + k) = *(*(C + i) + k) + *(*(A + i) + j) * (*(*(B + j) + k));
				//C[i][k] = C[i][k] + A[i][j] * B[j][k];//或者这行
			}
		}
	}
	return C;
}