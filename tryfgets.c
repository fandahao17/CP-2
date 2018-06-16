#include<stdio.h>

int main(void)
{
		char str[30];
		if(fgets(str, 20, stdin)){
				printf("%s",str);
		}
		return 0;
}
