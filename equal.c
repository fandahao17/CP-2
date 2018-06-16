#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
		char ina[1024] = {0};
		char inb[1024] = {0};
		char aAfter[1024] = {0};
		char bAfter[1024] = {0};
		fgets(ina, 1024, stdin);
		fgets(inb, 1024, stdin);
		int len = strlen(ina);
		int i = 0;
		int j = 0;
		for(i = 0; i < len; i++){
				if(isalpha(ina[i])){
						aAfter[j++] = ina[i];
				}
		}
		len = strlen(inb);
		j = 0;
		for(i = 0; i < len; i++){
				if(isalpha(inb[i])){
						bAfter[j++] = inb[i];
				}
		}
		if(!strcasecmp(aAfter, bAfter)){
				printf("YES\n");
		} else {
				printf("NO\n");
		}
		return 0;
}
