#include<stdio.h>

int main(void)
{
		long long a = 0;
		long long b = 0;
		scanf("%lld", &a);
		b = 2 * a + 1;
		while(--b){
				if((b * b + 1) % (b - a) == 0){
						printf("%lld\n", (b * b + 1) / (b - a));
						return 0;
				}
		}
		return 0;
}
