#include <stdio.h>
#include <stdbool.h>

typedef struct {
		int board[9];
}Status;
int total_count = 0;
int step = 0;
bool has[450000000] = {0};
Status nstatus[1000000]; 

int trans(int *board)
{
		return board[0] * 9 + board[1] * 81 + board[2] * 729 +
				board[3] * 6561 + board[4] * 59049 + board[5] * 531441+
				board[6] * 4782969 + board[7] * 43046721 + board[8] * 
				1;
}
int success(int *board)
{
		if (board[8] == 0 && board[0] == 8 &&board[1] == 7 
		    && board[2] == 6 && board[3] == 5 &&board[4] == 4 
			&& board[5] == 3 && board[6] == 2 &&board[7] == 1) {
				return 1;
		}
		return 0;
}

void createSingleNew(Status *cur_status,int zeroPos, int dir)
{
		int temp = cur_status->board[zeroPos + dir];
		cur_status->board[zeroPos+dir] = 
				cur_status->board[zeroPos];
		cur_status->board[zeroPos] = temp;
		if (has[trans(cur_status->board)]) {
				temp = cur_status->board[zeroPos + dir];
				cur_status->board[zeroPos+dir] = 
						cur_status->board[zeroPos];
				cur_status->board[zeroPos] = temp;
				return ;
		}
		has[trans(cur_status->board)] = 1;
		total_count++;
		int i = 0;	
		for (i = 0; i < 9; i++) {
				nstatus[total_count].board[i] = cur_status->board[i];
		}
		temp = cur_status->board[zeroPos + dir];
		cur_status->board[zeroPos+dir] = 
				cur_status->board[zeroPos];
		cur_status->board[zeroPos] = temp;
}

void createNew(Status *cur_status)
{
		int i = 0;	
		while (cur_status->board[i++] != 0) {
				continue;
		}
		i--;
		if (i < 3) {
				createSingleNew(cur_status, i, 3);
		} else if(i >= 6){
				createSingleNew(cur_status, i, -3);
		}else{
				createSingleNew(cur_status, i, -3);
				createSingleNew(cur_status, i, 3);
		}
		if (i % 3 == 0) {
				createSingleNew(cur_status, i, 1);
		} else if(i % 3 == 2){
				createSingleNew(cur_status, i, -1);
		}else{
				createSingleNew(cur_status, i, -1);
				createSingleNew(cur_status, i, 1);
		}
}

void bfs(int start, int end)
{
		int i = start;
		for (i = start; i <= end; i++) {
				if (success(nstatus[i].board)) {
						printf("%d\n", step);
						return ;
				}else{
						createNew(&nstatus[i]);
				}
		}
		step++;
		bfs(end + 1, total_count);
}

int main(void)
{
		int i = 0;	
		for (i = 0; i < 9; i++) {
				scanf("%d", &nstatus[0].board[i]);
		}
		has[trans(nstatus[0].board)] = 1;
		bfs(0, 0);
		return 0;
}
