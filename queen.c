#include <stdio.h>
#include <stdlib.h>

long long count = 0;

void putQueen(int *ans, int num, int row)
{
		if (num == row) {
				count++;
				return ;
		}else{
				int col = 0;
				int curRow = 0;
				for (col = 0; col < num; col++) {
						for (curRow = 0; curRow < row; curRow++) {
								if ((ans[curRow] == col)||
										(curRow - row) == (ans[curRow] - col)||
										(curRow - row) == (-ans[curRow] + col)) {
										break;
								}
						}
						if (curRow == row) {
								ans[row] = col;
								putQueen(ans, num, row + 1);
						}
						
				}
		}
}

int main(void)
{
		int num = 0;
		while (scanf("%d", &num) != EOF) {
				int *ans = calloc( num, sizeof(int));
				putQueen(ans, num, 0);
				printf("%lld\n", count);
				count = 0;
		}
		return 0;
}
