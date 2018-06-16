#include<stdio.h>
#include<stdlib.h>

int main(void)
{
		char str[9] = {0};
		long x = 0;
		scanf("%s", str);
		x = strtol(str, NULL, 8);
		printf("%ld\n", x);
		return 0;
}
