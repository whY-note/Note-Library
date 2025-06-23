#include<stdio.h>
#include<stdlib.h>
#define M 2
#define N 3
#define P 4


void matrix_multiple1(int(*p1)[N], int(*p2)[P], int(*p3)[P]);//��3���βΣ�����һ���洢����ֵ
int** matrix_multiple2(int(*p1)[M][N], int(*p2)[N][P]);//��2���β�,����ָ���ָ��
int(*matrix_multiple3(int(*p1)[100][100], int(*p2)[100][100]))[100][100];//��2���βΣ�����ָ��2ά�����ָ��
int** matrix_multiple4(int** A, int** B);

int main()
{
	int i, j;
	int a[M][N] = { {1,2,3},{2,3,4} };
	int b[N][P] = { {1,2,3,4},{2,3,4,5},{3,4,5,6} };
	int c[M][P] = { 0};

	printf("��һ:\n");
	matrix_multiple1(a, b, c);
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < P; j++)
		{
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}

	printf("����:\n�ȿ���һ�鶯̬�洢�ռ䣬���ǲ�֪Ϊʲô����������룿\n");
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

	printf("����:\n");
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

	//���ģ�ָ���ָ��
	printf("���ģ�ָ���ָ��\n");
	int* pa_hang[M];//ָ�����a��ÿһ��
	for (int i = 0; i < M; i++)
	{
		pa_hang[i] = a[i];
	}
	int** pa = pa_hang;//ָ�����a

	int* pb_hang[N];//ָ�����b��ÿһ��
	for (int i = 0; i < N; i++)
	{
		pb_hang[i] = b[i];
	}
	int** pb = pb_hang;//ָ�����b


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
//��һ
void matrix_multiple1(int(*p1)[N], int(*p2)[P], int(*p3)[P])//��3���βΣ�����һ���洢����ֵ
{
	/*
	* ����˵����
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

//����
int** matrix_multiple2(int(*p1)[M][N], int(*p2)[N][P])//��2���β�,����ָ���ָ��
{
	int i, j, k;
	//�ȿ���һ�鶯̬�洢�ռ䣬���ǲ�֪Ϊʲô����������룿
	int** p = (int**)calloc(N ,sizeof(int*));
	
	for (int i = 0; i < N; i++)
	{
		p[i] = (int*)calloc(M , sizeof(int));//p[i]���Ի���*(p+i)
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
//����
int(* matrix_multiple3(int(*p1)[100][100], int(*p2)[100][100]))[100][100] //��2���βΣ�����ָ��2ά�����ָ��
{
	int mt[100][100] = {};

	int(*p0)[100][100] = &mt;
	for (int i = 0; i < M; i++)
		for (int k = 0; k < P; k++)
			for (int j = 0; j < N; j++)
				(*p0)[i][k] += (*p1)[i][j] * (*p2)[j][k];
	return p0;
}

//���ģ�ָ���ָ��
int** matrix_multiple4(int** A, int** B)
{
	int** C = (int**)malloc(M * sizeof(int*));
	for (int i = 0; i < M; i++)
	{
		C[i] = (int*)malloc(P * sizeof(int));

		for (int k = 0; k < P; k++)
		{
			*(*(C + i) + k) = 0;  //��ʼ��Ϊ0��һ��Ҫ�У���������
			for (int j = 0; j < N; j++)
			{
				*(*(C + i) + k) = *(*(C + i) + k) + *(*(A + i) + j) * (*(*(B + j) + k));
				//C[i][k] = C[i][k] + A[i][j] * B[j][k];//��������
			}
		}
	}
	return C;
}