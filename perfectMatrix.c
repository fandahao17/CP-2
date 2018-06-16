#include <stdio.h>

int isPerfect(int **matrix, int n, int m)
{
		int i = 0;	
		int j = 0;	
		for (i = 0; i < n-1; i++) {
				for (j = 0; j < m-1; j++) {
						if (matrix[i][j] == matrix[i][j+1] ||
										matrix[i][j] == matrix[i+1][j]) {
								return 0;
						}
				}
		}
		for (i = 0; i < n-1; i++) {
				if (matrix[i][m-1] == matrix[i+1][m-1]) {
						return 0;
				}
		}
		for (i = 0; i < m-1; i++) {
				if (matrix[n-1][i] == matrix[n-1][i+1]) {
						return 0;
				}
		}
		return 1;
}
