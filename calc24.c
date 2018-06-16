#include <stdio.h>
#include <math.h>

int isZero(double num)
{
		if (fabs(num) <= 0.01) {
				return 1;
		} else {
				return 0;
		}
}
int calc(double *num, int count)
{
		if (count == 1) {
				if (isZero(num[0] - 24)) {
						return 1;
				} else {
						return 0;
				}
		}
		int i = 0;	
		int j = 0;	
		int k = 0;	
		int h = 1;	
		for (i = 0; i < count - 1; i++) {
				for (j = i + 1; j < count; j++) {
						double b[5] = {0};
						for (k = 0; k < count; k++) {
								if (k != i && k != j) {
										b[h] = num[k];
										h++;
								}
						}
						h = 1;
						b[0] = num[i] + num[j];
						if (calc(b, count - 1)) {
								return 1;
						}
						b[0] = num[i] - num[j];
						if (calc(b, count - 1)) {
								return 1;
						}
						b[0] = num[j] - num[i];
						if (calc(b, count - 1)) {
								return 1;
						}
						b[0] = num[i] * num[j];
						if (calc(b, count - 1)) {
								return 1;
						}
						if (isZero(num[j]) == 0) {
								b[0] = num[i] / num[j];
								if (calc(b, count - 1)) {
										return 1;
								}
						}
						if (isZero(num[i]) == 0) {
								b[0] = num[j] / num[i];
								if (calc(b, count - 1)) {
										return 1;
								}
						}
				}
		}
		return 0;
}
		
int main(void)
{
		double num[5] = {0};
		scanf("%lf%lf%lf%lf", &num[0], &num[1], &num[2], &num[3]);
		do {
				if(calc(num, 4) == 1){
						printf("YES\n");
				}else{
						printf("NO\n");
				}
				scanf("%lf%lf%lf%lf", &num[0], &num[1], &num[2], &num[3]);
		} while (num[0] != 0 || num[1] != 0 || num[2] != 0
						|| num[3] != 0);
		return 0;
}
