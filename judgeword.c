#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(void)
{
		char sentence[100] = {0};
		char *word[100] = {0};
		fgets(sentence, 100, stdin);
		int i = 0;
		int j = 0;
		char *now = sentence;
		int len = strlen(sentence);

		for(i = 0; i < len - 1; i++){
				if(!isalpha(sentence[i])){
					sentence[i] = '\0';	
					word[j++] = now;
					now = &sentence[i + 1];
				}
		}

		word[j++] = now;
		for(int k = 0; k < j; k++){
				printf("Word %d: %s\n", k, word[k]);
		}
		return 0;
}
