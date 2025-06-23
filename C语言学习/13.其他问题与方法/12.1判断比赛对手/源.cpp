/*甲队派出A、B、C三人与乙队的X、Y、Z三人比赛
A说他不和X比，C说他不和X、Z比。
请判断3对比赛对手的关系*/
#include<stdio.h>
int main()
{
	char a, b, c;
	for (a = 'x'; a <= 'z'; a++)
		for (b = 'x'; b <= 'z'; b++)
			if (a != b)
				for (c = 'x'; c <= 'z'; c++)
					if (a != c && b != c)
						if (a != 'x' && c != 'x' && c != 'z')
							printf("a--%c\nb--%c\nc--%c\n", a, b, c);
	return 0;
}