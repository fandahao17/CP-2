#include<stdio.h>

int calculate(int *num, int result, int count, int right)
{
		if(result ==right ||result + num[count] == right){
				printf("YES!\n");
				return 1;
		} else{
				if(count == 4)	return 0;
				if(calculate(num, result, count + 1, right)){
						return 1;
				}
				else if(calculate(num, result + num[count], count + 1, right)){
						return 1;
				} else return 0;
		}
}

int main(void)
{
		int K = 0;
		int a[5] = {0};
		scanf("%d", &K);
		scanf("%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4]);
		if(!calculate(a, 0, 0, K)){
				printf("NO!\n");
		}
		return 0;
}
