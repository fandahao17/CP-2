#include <stdio.h>
#include <math.h>

double a,b,c,d;
int n = 0;
double res[3] = {0};

void BinarySearch(double left, double right)
{
		if (n == 3) {
				return ;
		} else {
				double f1 = a * pow(left, 3) + b * pow(left, 2)+
						c * left + d;
				double f2 = a * pow(right, 3) + b * pow(right, 2)+
						c * right + d;
				double mid = (left + right) /2;
				if (f1 * f2 < 0) {
						if (right - left < 0.001) {
								res[n] = mid;
								n++;
								return ;
						}
				}
				if (right - left < 0.001) {
						return ;
				}
				BinarySearch(left, mid);
				BinarySearch(mid, right);
		}
}

int main(void)
{
		scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
		BinarySearch(-100.0, 100.0);
		printf("%.2lf %.2lf %.2lf\n", res[0], res[1], res[2]);
		return 0;
}
