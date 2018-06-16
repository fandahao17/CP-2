#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int max_square = 1;	
int max = 1;	


void calValue(int **matrix, int m, int n)
{
		int **col_value = calloc(n, sizeof(int *));
		int **line_value = calloc(n, sizeof(int *));

		int i = 0;	
		int count = 1;	
		int j = 0;	
		int least = 0;	
		for (i = 0; i < n; i++) {
				col_value[i] = calloc(m, sizeof(int));
				line_value[i] = calloc(m, sizeof(int));
				for (j = 0; j < m; j++) {
						col_value[i][j] = 1;
						line_value[i][j] = 1;
				}
		}
		
		for (j = 0; j < m; j++) {
				i = 0;	
				while (i < n-1) {
						if (matrix[i][j] != matrix[i+1][j]) {
								count++;
								if (i == n-2) {
										i++;
										for (int k = 1; k <= count; ++k) {
												col_value[i-k+1][j] = k;
										}
										count = 1;
								}
						}else{
										for (int k = 1; k <= count; ++k) {
												col_value[i-k+1][j] = k;
										}
								count = 1;
						}
						i++;
				}
		}
		for (i = 0; i < n; i++) {
				j = 0;
				while (j < m-1) {
						if (matrix[i][j] != matrix[i][j+1]) {
								count++;
								if (j == m-2) {
										j++;
								for (int k = 1; k <= count; ++k) {
										line_value[i][j-k+1] = k;
										least = col_value[i][j-k+1];
										for (int l = 0; l < k; ++l) {
												if (col_value[i][j-k+1+l]
																< least) {
														least = col_value[i][j-k+1+l];
												}
												if ((l+1) * least > max) {
														max = (l+1) * least;
												}
												if ((l+1) == least && 
														(l+1) > max_square) {
														max_square = l+1;
												}
										}
								}
								count = 1;
								}
						}else{
								for (int k = 1; k <= count; ++k) {
										least = col_value[i][j-k+1];
										if (k * least < max) {
												continue;
										}
										line_value[i][j-k+1] = k;
										for (int l = 0; l < k; ++l) {
												if (col_value[i][j-k+1+l]
																< least) {
														least = col_value[i][j-k+1+l];
												}
												if ((l+1) * least > max) {
														max = (l+1) * least;
												}
												if ((l+1) == least && 
														(l+1) > max_square) {
														max_square = (l+1);
												}
										}
								}
								count = 1;
						}
						j++;
				}
				if (col_value[i][m-1] > max) {
						max = col_value[i][m-1];
				}
		}
}

int main(void)
{
		int m = 0;	
		int n = 0;	
		scanf("%d%d", &n, &m);
		int **matrix = calloc(n, sizeof(int *));
		int i = 0;	
		int j = 0;	
		for (i = 0; i < n; i++) {
				matrix[i] = calloc(m, sizeof(int));
				for (j = 0; j < m; j++) {
						scanf("%d", &matrix[i][j]);
				}
		}
		calValue(matrix, m, n);
		printf("%d\n%d\n", max_square * max_square, max);
		return 0;
}
