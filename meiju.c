#include <stdio.h>

int main(void)
{
		int x1 = 0;
		int n = 0;
		scanf("%d", &n);
		if(n == 0){
				printf("0\n");
				return 0;
		}
		int sum3 = 3 * n - (3 * n) % 5;
		do{
				int x3 = n;
				if ((sum3 - x3) % 2 != 0) {
						x3--;	
				}
				int sum1 = sum3 - x3;
				do {
						sum1 = sum3 - x3;
						if (sum1 > 2 * n) {
								break;
						}
						for (x1 = sum1 - n > 0? sum1 - n: 1; x1 <= n; x1++) {
								if ((sum1 - x1 + x3) % 3 == 0){
										printf("%d\n",sum3);
										return 0;
								}
						}
				} while (x3-=2);
				if (sum1 > 2 * n) {
						continue;
				}
		}while(sum3 -= 5);
}
