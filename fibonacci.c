#include<stdio.h>

long long fibonacci(int n)
{
		//trivial recursion is much slower than 'for' loop
		int i = 1;
		long long sum = 1;
		long long last_sum = 0;
		long long temp = 0;
		if(n == 1) return sum;
		else{
				for(i = 2; i <= n; i++){
						temp = sum;
						sum += last_sum;
						last_sum = temp;
				}
		}
		return sum;
}
int main(void)
{
		int n= 0;
		scanf("%d", &n);
		printf("%lld\n", fibonacci(n));
		return 0;
}
