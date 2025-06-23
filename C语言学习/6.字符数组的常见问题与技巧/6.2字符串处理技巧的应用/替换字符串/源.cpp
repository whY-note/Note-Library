#include<stdio.h>
#include<string.h>
int main()
{
	void replace1(char* str, char* fstr, char* rstr);
	void replace2(char* str_main, char* str_find, char* str_replace);
	void replace3(char str_main[], char str_find[], char str_replace[]);

	char s [100]= {'\0'}, f[100]= { '\0' }, r[100]= { '\0' };
	char* st, * fs, * rs;
	scanf_s("%s%s%s", s,100,f,100,r,100);
	st = s; fs = f; rs = r;
	//replace1(st, fs, rs);
	replace2(st, fs, rs);
	//replace3(st, fs, rs);
	printf("%s\n",s);
	return 0;
}
//法一
void replace1(char* str, char* fstr, char* rstr)
{
	int i,j,k=0,len1,len2,len3,u,v;
	char* place = str;//指针变量place用来存放指针变量str目前所指向元素的地址，也就是存放str所指向的数组的首元素的地址，以便于后面操作后可以使str重新指向这一地址
	char t[100] = { '\0' };//字符数组t，用于临时存放
	len1= strlen(fstr);
	printf("fstr=%d\n", len1);
	len2 = strlen(rstr);
	printf("rstr=%d\n", len2);
	len3= strlen(str);
	printf("str=%d\n", len3);
	for (k = 0; *str != '\0'; k++, str++)//用for循环遍历str所指向字符串的所有元素
		{
			if (*str == *fstr)//如果str所指向字符串的某个字符与fstr所指向字符串的首字符相同，则比较与fstr所指向字符串相同长度的字符串
			{
				printf("%d\n", k);
				for (i = 0; i < len1; i++)
				{
					t[i] = *(str + i);//先:将str所指向字符串从该元素开始，与fstr所指向字符串长度相同的字符串复制到数组t
				}
				printf("%s\n", t);
				if (strcmp(t, fstr) == 0)//再比较数组t与fstr所指向字符串是否相同。如果相同，则进行下面的替换操作
				{
					for (j = len3 - 1; j >= k+len1; j--)
					{
						*(str - k + j + len2 - len1) = *(str - k + j);//将被替换字符串后面的字符往后移
					}
					*(str - k + len3 + len2 - len1) = '\0';
					for (u = k, v = 0; v < len2; u++, v++)
					{
						*(str - k + u) = *(rstr + v);//用rstr所指向的字符串替换
					}
					//printf("v=%d\n", v);
					//len3 = len3 + len2 - len1;
					//printf("len3=%d\n", len3);
					k = 0;//重新令k=0,表示进行了一次替换操作
					break;//由于第33~37行的操作使str所指向的字符数组的有效长度改变了。如果不用break，则最外层的for循环还会依照str所指向字符数组原来的有效长度进行，导致出错。因此必须使用break来跳出循环，然后用第48~51行的if语句判断是否需要再次替换。
				}
			}
		}
	str = place;//让str重新指向str所指向数组的首元素
	if (k == 0)//如果k=0，表示进行了替换，需要调用replace函数检测是否还需要再次替换；如果k!=0，表示已经替换完成。
	{
		replace1(str, fstr, rstr);
	}
}
//法二：使用flag。Best!!!
void replace2(char* str_main, char* str_find, char* str_replace)
{
	int i, j, k;
	int flag = 0;//找到str_find,则1；否则0

	int len_main = strlen(str_main);
	int len_find = strlen(str_find);
	int len_replace = strlen(str_replace);

	for (i = 0; str_main[i] != '\0'; i++)
	{
		//查找str_find
		for (j = i, k = 0; str_main[j] == str_find[k]; j++, k++)
		{
			if (str_find[k + 1] == '\0')
			{
				flag = 1;
			}
		}

		if (flag)//找到str_find,开始替换
		{
			if (len_find <= len_replace)
			{
				for (j = len_main - 1; j >= i + len_find; j--)//先把后面的元素 从右到左 后移
				{
					str_main[j + len_replace - len_find] = str_main[j];
				}
				str_main[len_main + len_replace - len_find] = '\0';//在末尾加上'\0'
				for (j = i, k = 0; str_replace[k] != '\0'; j++, k++)//再插入
				{
					str_main[j] = str_replace[k];
				}
			}
			else//len_find>len_replace
			{
				for (j = i + len_find; j < len_main; j++)//先把后面的元素 从左到右 前移
				{
					str_main[j + len_replace - len_find] = str_main[j];
				}
				str_main[len_main + len_replace - len_find] = '\0';//在末尾加上'\0'
				for (j = i, k = 0; str_replace[k] != '\0'; j++, k++)//再插入
				{
					str_main[j] = str_replace[k];
				}
			}
			len_main = strlen(str_main);//重新测长度。关键！
			flag = 0;//替换完毕，复位
		}
	}
}
//法三:不使用flag,但多一个循环
void replace3(char str_main[], char str_find[], char str_replace[])
{
	int i, j, k, p, q;
	char t;
	int len_main = strlen(str_main);
	int len_find = strlen(str_find);
	int len_replace = strlen(str_replace);
	for (i = 0; str_main[i] != '\0'; i++)
	{
		for (j = i, k = 0; str_main[j] == str_find[k]; j++, k++)
		{
			if (str_find[k + 1] == '\0')//当找到与str_find相同的子字符串，就进行替换成str_replace
			{
				if (len_find <= len_replace)//如果str_find比str_replace更短
				{
					for (p = len_main - 1; p >= i - 1 + len_find; p--)//为了避免覆盖，从右向左逐个右移
					{
						str_main[p - len_find + len_replace] = str_main[p];
					}
					str_main[len_main - len_find + len_replace] = '\0';//在最后加上空字符
					len_main = strlen(str_main);//更新len_main。否则，下一次执行到上面那一行，会在同一位置加上空字符。SUPER IMPORTANT!!!
				}
				else //如果str_find比str_replace更长
				{
					for (p = i - 1 + len_find; p <= len_main - 1; p++)//为了避免覆盖，从左向右逐个左移
					{
						str_main[p - len_find + len_replace] = str_main[p];
					}
					str_main[len_main - len_find + len_replace] = '\0';//在最后加上空字符
					len_main = strlen(str_main);//更新len_main。否则，下一次执行到上面那一行，会在同一位置加上空字符。SUPER IMPORTANT!!!
				}
				for (p = i, q = 0; str_replace[q] != '\0'; p++, q++)
				{
					str_main[p] = str_replace[q];
				}
				break;
			}
		}
	}
}