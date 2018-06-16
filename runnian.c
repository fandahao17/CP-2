#include<stdio.h>

int main(void)
{
		int year = 0;
		scanf("%d", &year);
		if( year % 4 != 0){
				printf("NO\n");
		}else if(year % 100 == 0){
				if(year % 400 ==0){
						printf("YES\n");
				}else {
						printf("NO\n");
		}
		}else{
				printf("YES\n");
		}
		return 0;
}
