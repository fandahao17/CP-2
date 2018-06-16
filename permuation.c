#include <stdio.h>
#include <string.h>

char src[7] = {0};
char result[7] = {0};
int used[6] = {0};
int len = 0;

void permuation(int n)
{
	 if (n == len) {
		  result[n] = 0;
		  printf("%s\n", result);
		  return ;
	 }
	 int i = 0;	
	 for (i = 0; i < len; i++) {
	 	 if (!used[i]) {
	 	 	 result[n] = src[i];
			 used[i] = 1;
			 permuation(n + 1);
			 used[i] = 0;
	 	 }
	 }
}

int main(void)
{
	 fgets(src, 10, stdin);
	 len = strlen(src) - 1;
	 permuation(0);
	 return 0;
}
