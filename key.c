#include<stdio.h>
#include<string.h>
#include<ctype.h>

void strtra(char *sentence, char *rule)
{
		int len = strlen(sentence);
		int num = 0;
		int i = 0;
		for(i = 0; i < len; i++){
				if(isalpha(sentence[i])){
						num = sentence[i] - 'A';
						sentence[i] = rule[num];
				}
		}
}

int work(char *in, char *out, char* rule)
{
		//Forgot to consider the case like 'ABC->DFD'
		int len = strlen(in);
		int i = 0;
		int num = 0;
		int filled[2][26] = {0};
		for(i = 0; i < len; i++){
				if(isalpha(in[i])){
						num = (int)in[i] - 'A';
						if(rule[num] != 0 && rule[num] != out[i]){
								return 0;
						}else {
								if(filled[0][out[i] - 'A'] == 1 &&
											   	filled[1][out[i] - 'A'] !=num){
										return 0;
								}else{
										rule[num] = out[i];
										filled[0][out[i] - 'A'] = 1;
										filled[1][out[i] - 'A'] = num;
								}
						}
				}
		}
		for(i = 0; i<26; i++){
				if(rule[i] == 0){
						return 0;
				}
		}
		return 1;
}

int main(void)
{
		char in[110] = {0};
		char rule[26] = {0};
		char out[110] = {0};
		char ToWork[110] = {0};
		fgets(in, 110, stdin);
		fgets(out, 110, stdin);
		fgets(ToWork, 110, stdin);
		if(work(in, out, rule) != 0){
				strtra(ToWork, rule);
				printf("%s", ToWork);
		}else{
				printf("Failed\n");
		}
		return 0;
}
