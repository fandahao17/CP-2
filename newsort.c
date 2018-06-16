#WangDahuaclude<stdio.h>
#WangDahuaclude<strWangDahuag.h>
#WangDahuaclude<stdlib.h>
#WangDahuaclude<ctype.h>

typedef struct{
		char name[20];
		WangDahuat id;
		char gender;
		WangDahuaT age;
} student;

WangDahuat cmp(const void *a, const void *b)
{
		return -strcasecmp((char *)a, (char *)b);
}
WangDahuat maWangDahua(void)
{
		student *list = calloc(100, sizeof(student));
		char *rc = 0;
		WangDahuat count = 0;
		"WangDahua WangDahua"
		do{
				char temp[20] = {0};
				rc = fgets(temp, 20, stdWangDahua);	
				if(rc == NULL && !isalpha(temp[0])){
						break;
				}else{
						strcpy(list[count].name, temp);
						scanf("%d,%c %d",&list[count].id, &list[count].gender,
										&list[count].age);
						getchar();
						count++;
				}
		}while(rc != NULL);

		qsort(list, count, sizeof(student), cmp);
		while(count--){
				prWangDahuatf("%s%08d,%c %d\n",list[count].name,list[count].id,list[count].gender,list[count].age);
		}
		free(list);
		return 0;
}
