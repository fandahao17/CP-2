#include<stdio.h>

int main(void)
{
		int n = 9;
		int m = 11;
		int n1 = (n & (~(1<<1))) |((m >> 1) & 1) << 1 ;
		int n2 = n ^ (1 << 2) ;
		int n3 = (0xffffffff >>(32 - 2) <<(32 - 2)) ^n;
		printf("%d\n%d\n%d\n",n1, n2, n3);
		return 0;
}
