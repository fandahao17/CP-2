#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct{
		char name[20];
		int id;
		char gender;
		int age;
} student;

int cmp(const void *a, const void *b)
{
		return -strcasecmp((char *)a, (char *)b);
}

int GetName(char *name)
{
		char temp[20];
		if( fgets(temp, 20, stdin) == NULL){
				return 0;
		} else if(!isalpha(temp[0])){
				return 0;
		} else {
				strcpy(name, temp);
				return 1;
		}
}
int main(void)
{
		student *list = calloc(100, sizeof(student));
		int count = 0;

		while(GetName(list[count].name)){
				scanf("%d,%c%d",&list[count].id,&list[count].gender,
								&list[count].age);
				getchar();
				count++;
		}

		qsort(list, count, sizeof(student), cmp);
		while(count--){
				printf("%s%08d,%c %d\n",list[count].name,list[count].id,
								list[count].gender,list[count].age);
		}
		free(list);
		return 0;
}
