#include <stdio.h>
#include <math.h>

double a = 0;
double b = 0;
double c = 0;
double d = 0;
double f(double x)
{
		return a * pow(x, 3) + b* pow(x, 2) + c * x + d;	
}
double Accurate(double bottom)
{
		double step = 0.1;
		while (fabs(f(bottom)/(a*pow(bottom, 3)))>10e-3) {
				bottom -= step;
		}
		step = 0.01;
		while (fabs(f(bottom)/(a*pow(bottom, 3)))>10e-4) {
				bottom += step;
		}
		step = 0.001;
		while (fabs(f(bottom)/(a*pow(bottom, 3)))>10e-4) {
				bottom -= step;
		}
		return bottom;
}
int main(void)
{
		scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
		double LeftBound = 0;
		double res[4] = {-100,0,0, 0};
		int i = 0;
		for (i = 0; i < 3; i++) {
				LeftBound = f(res[i]);
				while (f(res[i]) * LeftBound > 0) {
						res[i]++;
				}
				res[i] = Accurate(res[i]);
				res[i + 1] = res[i] + 0.9;
		}
		printf("%.2f %.2f %.2f\n", res[0], res[1], res[2]);

		return 0;
}
