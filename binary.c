#include<stdio.h>
#define MAX 32768

int isequal(int a, int b)
{
		int time = 0;
		while(time++ < 16){
				if(a /MAX > 0){
						a = a << 1;
						a %= 65536;
						a += 1;
				}else {
						a = a << 1;
				}
				if ( a == b){
						return 1;
				}
		}
		return 0;
}

int main(void)
{
		int chances = 0;
		int a = 0;
		int b = 0;
		scanf("%d", &chances);
		while(chances--){
				scanf("%d%d", &a, &b);
				if(isequal(a, b)){
						printf("YES\n");
						continue;
				}
				printf("NO\n");
		}
		return 0;
}
