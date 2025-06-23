#include<stdio.h>
#define M 4
#define N 3
int main()
{
	int a = 10;
	int b[M] = { 11,22,33,44};
	int c[N][M] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	
	int* p1;//指向一个元素的指针变量.等价于 int (* p)
	int(*p2)[M];//指向由M个元素组成的一维数组的指针变量
	int(*p3)[N][M];//指向由N*M个元素组成的二维数组的指针变量
	
	//p1指向一个变量
	p1 = &a;
	printf("p1指向一个变量a:*p1=%d\n", *p1);
	//p1指向一维数组
	p1 = b;
	printf("p1指向一维数组b:*p1=%d\n", *p1);
	printf("p1指向一维数组b: *(p1+3)=%d\n", *(p1+3));
	printf("p1指向一维数组b: p1[3]=%d\n", p1[3]);
	//p1指向二维数组中的一维数组
	p1 = c[0];
	printf("p1指向二维数组中的一维数组c[0]:*p1=%d\n", *p1);
	printf("p1指向二维数组中的一维数组c[0]: *(p1+3)=%d\n", *(p1 + 3));


	//p2指向一维数组
	p2 = &b;
	printf("p2指向一维数组b:(*p2)[0]=%d\n", (*p2)[0]);
	
	//p2指向二维数组中的一维数组
	p2 = c;//相当于p2 = &c[0]
	printf("p2指向二维数组c:*(*(p2+2)+3)[0]=%d\n", *(*(p2+2)+3));
	printf("%d\n", (*(p2+2))[3] );

	//p3指向二维数组
	p3 = &c;
	printf("p3指向二维数组c:(*p3)[2][3]=%d\n", (*p3)[2][3]);

	
	// 返回值为指针变量的函数
	printf("\n返回值为指针变量的函数\n");
	//f1是返回值为 指向一个元素的指针变量 的函数
	printf("f1是返回值为 指向一个元素的指针变量 的函数\n");
	int* f1(int x, int y);//返回值为 指向一个元素的指针变量 的函数
	p1= f1(10, 9);
	printf("%d\n", *p1);

	//f2是返回值为 指向由M个元素组成的一维数组的指针变量 的函数
	printf("f2是返回值为 指向由M个元素组成的一维数组的指针变量 的函数\n");
	int(*f2(int x, int y))[M + 100];//返回值为 指向由M个元素组成的一维数组的指针变量 的函数
	int(*p4)[M + 100];
	p4= f2(1, 2);
	for (int i = 0; i < M; i++)
	{
		printf("%d ", (*p4)[i]);
	}
	printf("\n");

	//f3是返回值为 指向由N*M个元素组成的二维数组的指针变量 的函数
	printf("f3是返回值为 指向由N*M个元素组成的二维数组的指针变量 的函数\n");
	int(*f3(int x))[N + 100][M + 100];//返回值为 指向由N*M个元素组成的二维数组的指针变量 的函数
	int(*p5)[N + 100][M + 100];
	p5 = f3(3);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ", (*p5)[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//p6是指向函数的指针变量
	printf("p6是指向函数的指针变量。现使其指向max函数\n");
	int max(int x, int y);
	int (*p6)(int, int);//指向函数的指针变量
	p6 = max;//注意：p6所指向的函数必须与p6有相同类型的返回值。这里的返回值都是int
	int big;
	big=(* p6)(2,3);
	printf("%d\n", big);

	//p7指针变量数组
	printf("\n指针变量数组\n");
	printf("p7指针变量数组\n");
	int* p7[4];
	int x0=0,x1 = 10, x2 = 20, x3 = 30;
	p7[0] = &x0;
	p7[1] = &x1;
	p7[2] = &x2;
	p7[3] = &x3;
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", *p7[i]);
	}
	printf("\n");

	printf("p8指针变量数组\n");
	int* p8[4];
	int arr0[3] = { 1,2,3 }, arr1[3] = { 1,4,9 }, arr2[3] = { 1,8,27 }, arr3[3] = { 1,16,81 };
	p8[0] = arr0;
	p8[1] = arr1;
	p8[2] = arr2;
	p8[3] = arr3;
	for (int i = 0; i < 4; i++)
	{
		for (int j=0;j<3;j++)
		{
			printf("%d ", *(p8[i] + j));
		}
		printf("\n");
	}
	printf("\n");

	//p9是指向指针变量 的指针变量
	printf("p9是指向指针变量 的指针变量。\n");
	int** p9;

	printf("1.现使其指向指针变量数组p7\n");
	p9 = p7;
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", *(*(p9+i)));
	}

	printf("\n2.现使其指向指针变量数组p8。此时，p9就相当于一个二维数组名\n");
	p9 = p8;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ",*(*(p9+i)+j));//*(*(p9+i)+j)可以换成p9[i][j]
		}
		printf("\n");
	}
	printf("3.现使其指向指针变量p1,而p1指向y=100。\n");
	int y = 100;
	p1 = &y;
	p9 = &p1;
	printf("%d\n", *(*p9));

	return 0;
}
int* f1(int x, int y)
{
	int* pt;
	pt = x > y ? &x : &y;
	return pt;
}
/*
对于f2,f3
函数内定义的局部数组 arr 是在栈上分配的，其生命周期与函数执行期相同。
当函数返回时，arr 的内存空间将被释放，返回的指针 pt 将指向一个不再有效的内存区域。
为解决此问题，最好的方法是用动态内存分配函数malloc,或calloc开辟一块动态存储空间
较快的方法是直接把数组 arr 的长度变得比非常大，比如+100
*/
int(* f2(int x, int y))[M+100] 
{
	int arr[M+100] = {0};
	int(* pt)[M+100]=&arr;

	(* pt)[0] = x;
	(* pt)[1] = y;
	(* pt)[2] = x+y;
	(* pt)[3] = x - y;
	return pt;
}
int(*f3(int x))[N+100][M+100]
{
	int arr[N+100][M+100] = {{1,2,3,4},{x,1,1,1},{5,6,7,8}};
	int(*pt)[N+100][M+100] = &arr;
	return pt;
}
int max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}