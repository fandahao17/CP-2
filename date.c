#include<stdio.h>

int main(void)
{
		int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 
				30, 31};
		int FirstDate[2] = {0};
		int SecondDate[2] = {0};
		int distance = 0;
		scanf("%d%d", &FirstDate[0], &FirstDate[1]);
		scanf("%d%d", &SecondDate[0], &SecondDate[1]);
		distance += SecondDate[1] - FirstDate[1];
		while((--SecondDate[0]) >= FirstDate[0]){
				distance += month[SecondDate[0]];
		}
		printf("%d\n", distance);
		return 0;
}
