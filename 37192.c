#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
		char name[20];
		char sex;
		int num;
		int age;
};
int change(const void*e1,const void*e2);
int main()
{
		int i=0,n;
		struct student p[101];
		while((fgets(p[i].name,18,stdin)!=NULL)&&(i<100))
		{
				scanf("%d,%c %d",&p[i].num,&p[i].sex,&p[i].age);
				i++;
				getchar();
		}
		n=i;
		qsort(p,n,sizeof(p[0]),change);
		for(i=0;i<n;i++)
		{
				printf("%s",p[i].name);
				printf("%08d,%c %d\n",p[i].num,p[i].sex,p[i].age);
		} 
		return 0;
}
int change(const void*e1,const void*e2)
{
		return strcasecmp(((struct student*)e1)->name,((struct student*)e2)->name);
}
