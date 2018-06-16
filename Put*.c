#include<stdio.h>

int main(void)
{
		int count = 0;
		scanf("%d", &count);
		while(count-- > 0){
				putchar('*');
		}
		putchar('\n');
		return 0;
}
