#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 9
char map[] = "2223334445556667777888999";
char telNum[100000][LENGTH];

int cmp(const void *str1, const void *str2)
{
	 return strcmp((char *)str1, (char *)str2);
}

void stdNum(char *src, int n)
{
	 int len = strlen(src);
	 int i = 0;	
	 int count = 0;	
	 for (i = 0; i < len; i++) {
		  if (count == 3) {
			   telNum[n][count++] = '-';
		  }
		  if (src[i] == '-') {
			   continue;
		  }else if (src[i] >= '0' && src[i] <= '9') {
			   telNum[n][count++] = src[i];
		  }else {
			   telNum[n][count++] = map[src[i] - 'A'];
		  }
	 }
	 telNum[n][count] = 0;
}

int main(void)
{
	 int i = 0;	
	 int n = 0;	
	 char src[100] = {0};
	 scanf("%d", &n);
	 for (i = 0; i < n; i++) {
	 	 scanf("\n%s", src);
		 stdNum(src, i);
	 }
	 qsort(telNum, n, LENGTH, cmp);
	 int count = 1;	
	 int flag = 0;	
	 for (i = 1; i < n; i++) {
		  if (strcmp(telNum[i], telNum[i-1]) != 0) {
			   if (count > 1) {
					flag = 1;
					printf("%s %d\n", telNum[i-1], count);
					count = 1;
			   }
		  }else{
			   count++;
		  }
	 }
	 if (count > 1) {
		  printf("%s %d\n", telNum[i-1], count);
		  return 0;
	 }
	 if (!flag) {
	 	 printf("No duplicates.\n");
	 }
	 return 0;
}
