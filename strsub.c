#define _GNU_SOURCE
#include<stdio.h>
#include<string.h>
#define MAX_LINE 1024

int main(void)
{
		char src[100] = {0};
		char dest[100] = {0};
		char *new = NULL;
		char *last = NULL;

		scanf("%s", src);
		getchar();
		scanf("%s", dest);

		size_t len = strlen(src);
		char line[MAX_LINE] = {0};
		FILE *InFile = fopen("sort.c", "r");
		FILE *OutFile = fopen("newsort.c", "w");

		while(fgets(line, MAX_LINE, InFile) != NULL){
				if((new = strcasestr(line, src)) == NULL){
						fputs( line, OutFile);
				}else{
						last = line;
						while((new = strcasestr(last, src)) != NULL){
								*new = '\0';
								fputs( last, OutFile);
								fputs(dest, OutFile);
								last = new + len;
						}
								fputs( last, OutFile);
				}
		}
		fclose(InFile);
		fclose(OutFile);
}
