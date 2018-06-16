#include<stdio.h>
#include<stdlib.h>

typedef struct{
	   int rank;
	   int score;
	   int netwin;
	   int in;
	   int lose;
	   char win;
} team;

void ParseResult(team *A, team *B)
{
		int AScore = 0;
		int BScore = 0;
		scanf("%d:%d", &AScore, &BScore);
		if(AScore > BScore){
				A->score+=3;
		}
		if(AScore == BScore){
				A->score+=1;
				B->score+=1;
		}
		if(AScore < BScore){
				B->score+=3;
		}
		A->in += AScore;
		A->lose += BScore;
		B->in += BScore;
		B->lose += AScore;
}

int sort(const team *A,const team *B)
{
		if(A->score > B->score){
				return 1;
		}else if(A->score < B->score){
				return -1;
		}else if(A->netwin > B->netwin){
				return 1;
		}else if(A->netwin < B->netwin){
				return -1;
		}else if(A->in > B->in){
				return 1;
		}else if(A->in < B->in){
				return -1;
		}
}
void JudgeResult(team group[])
{
		int i = 0;
		for(i = 0; i < 4; i++){
				group[i].netwin = group[i].in - group[i].lose;
		}
		qsort(group, 4, sizeof(team), sort);
		for(i = 0; i < 4; i++){
				printf("")
		}
}

int main(void)
{
		team *group = calloc(4, sizeof(team));
		ParseResult(&group[0], &group[1]);
		ParseResult(&group[2], &group[3]);
		ParseResult(&group[0], &group[2]);
		ParseResult(&group[3], &group[1]);
		ParseResult(&group[1], &group[2]);
		ParseResult(&group[3], &group[0]);
		JudgeResult(group);
		return 0;
}

