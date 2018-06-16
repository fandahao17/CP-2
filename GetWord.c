#include<stdio.h>
#include<ctype.h>
 
int GetWord(char *word)
{
		char temp = 0;
		int i = 0;
		do{
				temp = getchar();
				if(temp ==EOF){
						return 1;
				}
		}while(isalpha(temp) == 0);
		do{
				word[i++] = temp;
				temp = getchar();
		}while(isalpha(temp) != 0);
		return 0;
}

int StoreWords(char array[][20])
{
		int count = 0;
		while(GetWord(array[count]) == 0){
				count++;
		}
		//return the number of words.
		return count;
}

int main(void)
{
		//test StoreWords
		char words[100][20] = {};
		int i = 0;
		int count = StoreWords(words);
		for(i = 0; i < count; i++){
				printf("Word %d: %s\n", i, words[i]);
		}
		return 0;
}
