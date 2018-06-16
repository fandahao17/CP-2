#include<stdio.h>
#include<string.h>
#include<ctype.h>

int IsPrime(int n)
{
		//'n%i == 0' isn't same as '!n%i'
		int i = 2;
		if(n == 0 || n == 1){
				return 0;
		} else if(n==2){
				return 1;
		}else {
				for(i = 2; i * i <= n; i++){
						if(n%i == 0)	return 0;
				}
				return 1;
		}
}

int main(void)
{
		int count[26] = {0};
		int i = 0;
		char word[110] = {0};
		fgets(word, 105, stdin);
		for(i = 0; i < strlen(word); i++){
				if(	isalpha(word[i])){
						count[word[i] - 'a']++;
				}
		}
		i = 0;
		while(count[i]==0){
				i++;
		}
		int maxn = count[i];
		int minn = count[i];
		for(i = 0; i< 26; i++){
				if(count[i] > maxn){
						maxn = count[i];
				}
				if(count[i] > 0 && count[i] < minn){
						minn = count[i];
				}
		}
		int yes = IsPrime(maxn - minn);
		if(yes){
				printf("Lucky Word\n%d\n", maxn - minn);
		} else{
				printf("No Answer\n0\n");
		}
		return 0;
}
