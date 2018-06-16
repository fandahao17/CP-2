#include<stdio.h>
#include<stdlib.h>

typedef struct{
		int x;
		int y;
		int num;
} Node;

int TimePermit(Node now, Node next, int *time)
{
		int xtime = 0;
		if(next.x - now.x >= 0){
				xtime = next.x - now.x;
		}else{
				xtime = -next.x + now.x;
		}
		int ytime = 0;
		if(next.y - now.y >= 0){
				ytime = next.y - now.y;
		}else{
				ytime = -next.y + now.y;
		}
		if(*time - (xtime + ytime + 1 + next.y) >= 0){
				*time -= (xtime + ytime + 1);
				return 1;
		}
		else{
				return -1;
		}
}

int cmp(const void *A, const void *B)
{
		return -(((const Node*)A)->num - ((const Node*)B)->num);
}
int main(void)
{
		int m = 0;
		int n = 0;
		int time = 0;
		int i = 0;
		int j = 0;
		int count = 0;
		scanf("%d%d%d", &m, &n, &time);

		Node *nodenet = calloc(m * n, sizeof(Node));
		for(i = 0; i < m; i++){
				for(j = 0; j < n; j++){
						nodenet[i*n + j].x = j + 1;
						nodenet[i*n + j].y = i + 1;
						scanf("%d", &nodenet[i*n + j].num);
				}
		}
		qsort(nodenet, m * n, sizeof(Node), cmp);
		if((time - (2 * nodenet[0].y + 1)) >= 0){
				time -= (nodenet[0].y+ 1);
				count += nodenet[0].num;
				for(i = 1;i < m * n &&nodenet[i].num != 0; i++){
						if(TimePermit(nodenet[i - 1], nodenet[i], &time) > 0){
								count += nodenet[i].num;
						}else break;
				}
		}
		free(nodenet);
		printf("%d\n", count);
		return 0;
}
		

