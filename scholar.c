#include<stdio.h>
#include<stdlib.h>
#define fan() 1
typedef struct{
		char name[25];
		int FinalScore;
		int ClassScore;
		char leader;
		char west;
		int paper;
		int scholar;
} Student;

void CountSch( Student *student)
{
		if(student->leader == 'Y')
				if(student->ClassScore > 80)
						student->scholar += 850;
		if(student->FinalScore > 80){
				if(student->paper > 0)
						student->scholar += 8000;
				if(student->FinalScore > 85){
						if(student->ClassScore > 80)
								student->scholar += 4000;
						if(student->west =='Y')
								student->scholar += 1000;
						if(student->FinalScore > 90)
								student->scholar +=2000;
				}
		}
}
int main(void)
{
		int count = 0;
		int count2 = 0;
		int max = 0;
		int total = 0;
		scanf("%d\n", &count);
		Student *student = calloc(count, sizeof(Student));
		for(int i = 0; i < count; i++){
				scanf("%s%d%d %c %c %d\n", student[i].name,
								&student[i].FinalScore,&student[i].ClassScore, &student[i].leader, &student[i].west, &student[i].paper);
				CountSch( &student[i]);
				if(i>0 &&student[i].scholar > student[max].scholar){
						max = i;
				}
				total += student[i].scholar;
		}
		printf("%s\n%d\n%d\n",student[max].name, student[max].scholar,
						total);
		return 0;
}
