/*�׶��ɳ�A��B��C�������Ҷӵ�X��Y��Z���˱���
A˵������X�ȣ�C˵������X��Z�ȡ�
���ж�3�Ա������ֵĹ�ϵ*/
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