#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int islands = 0;	

void findIsland(char **map, int x, int y)
{
		if(map[x][y] == '*'){
				map[x][y] = '.';
				findIsland(map, x, y+1);
				findIsland(map, x, y-1);
				findIsland(map, x+1, y);
				findIsland(map, x-1, y);
		}else{
				return ;
		}
}

int main(void)
{
		int n = 0;
		char str[1024] = {0};
		fgets(str, 1024, stdin);
		n = strlen(str) - 1;
		char **map = calloc(n + 2, sizeof(char*));
		int i = 0;	
		for (i = 0; i < n + 2; i++) {
				map[i] = calloc(n + 2, sizeof(char*));
		}
		for (i = 1; i < n + 1; i++) {
				map[1][i] = str[i -1];
		}
		for (i = 2; i < n + 1; i++) {
				fgets( &map[i][1], 1024, stdin);
		}
		for (i = 1; i < n + 1; i++) {
				int j = 0;
				for (j = 1; j < n + 1; j++) {
						if (map[i][j] == '*') {
								islands++;
								findIsland(map, i, j);
						}
				}
		}
		printf("%d\n", islands);
		return 0;
}
