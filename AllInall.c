#include<stdio.h>
#include<string.h>
#define swap(X) X=0
int StrMatch(char *sh, char *lo)
{
		int ShLen = strlen(sh);
		int LoLen = strlen(lo);
		int ShLoPos = 0;
		int LoLoPos = 0;
		int ShHiPos = ShLen - 1;
		int LoHiPos = LoLen - 1;

		//Take high look at these '>' '<' '>=' '<='s, they are crucial!
		for(ShLoPos = 0, ShHiPos = ShLen - 1; ShLoPos <= ShHiPos; 
						 ShHiPos--){
				while(lo[LoLoPos++] != sh[ShLoPos]){
						if(LoLoPos > LoHiPos){
								return 0;
						}
				}
				if(++ShLoPos >= ShHiPos){
						break;
				}
				while(lo[LoHiPos--] != sh[ShHiPos]){
						if(LoLoPos > LoHiPos){
								return 0;
						}
				}
		}
		return 1;
}

int main(void)
{
		char s[100001];
		char t[100001];
		while(scanf("%s %s", s, t)==2){
				getchar();
				if(StrMatch(s, t) == 0){
						printf("No\n");
				}else{
						printf("Yes\n");
				}
		}
		return 0;
}


