#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 110
int IsLarger(char *first, char *second)
{
		int Length = strlen(first) - 1;
		int i = 0;		
		while (first[i] == '0') {
				if (second[i] > '0') {
						return -1;
				}
				i++;
		}	
		while(i < Length){
				if (first[i] > second[i]) {
						return 1;
				}else if(first[i] < second[i]){
						return -1;
				}
				i++;
		}
		return 0;
}
void DeleteIt(char *str, char *str2)
{
		int length = strlen(str) - 1;
		int i = 0;	
		int temp = 0;	
		int pos = 0;	
		for (i = 0; i < length; i++) {
				pos = length - i - 1;
				temp = str[pos] -'0' - (str2[pos] -'0');
				if (temp < 0) {
						str[pos - 1] -= 1;
						temp += 10;
				}
				str[pos] = (temp % 10) + '0';
		}
}
int WorkByDigit(char *first, char *temp)
{
		int i = 0;
		while (IsLarger(first, temp) >= 0) {
				i++;
				DeleteIt(first, temp);
		}
		return i;
}
char* shift(char *str, int step)
{
		int length = strlen(str);
		char *new = calloc(LENGTH, sizeof(char));
		int i = 0;
		int j = 0;
		for (i = 0; i < step; i++) {
				new[i] = '0';
		}
		while (i < length) {
				new[i] = str[j];
				i++;
				j++;
		}
		return new;	
}
void PrintResult(int *result, int length)
{
		for (int i = 0; i < length; i++) {
				if (i == 0 && result[i] == 0) continue;
				printf("%d",result[i]);	
		}
		printf("\n");
}
int ParseInput(char *string, int *result)
{
		int i = 0;	
		int count = strlen(string) - 1;
		for (i = 0; i < count; i++) {
				result[i] = string[i] - '0';	
		}
		return count;
}
void LaunchDelete(char *first, char *second)
{
		int remainder[LENGTH] = {0};
		int FirstLength = strlen(first) - 1;
		int SecondLength = strlen(second) - 1;
		if (FirstLength < SecondLength) {
				printf("0\n%s", first);
				return ;
		}
		int FinalLength = FirstLength - SecondLength;
		char str[FinalLength];	
		int i = 0;
		for (i = 0; i < FinalLength; i++) {
				str[i] = '0';
		}
		str[FinalLength] = 0;
		second[SecondLength] = 0;
		second = strcat(second,str); 
		char *temp = strdup(second);
		second = shift(second, FinalLength);
		i = 0;
		while (IsLarger(first, second) >= 0) {
				remainder[i] = WorkByDigit(first, temp); 		
				temp = shift(temp, 1);
				i++;
		}
		i = 0;
		while (first[i] == '0' && i < FirstLength - 1) {
				i++;
		}
		PrintResult(remainder, FinalLength + 1);
		printf("%s",first + i);
}
int main(void)
{
		char first[LENGTH] = {0};	
		char second[LENGTH] = {0};	
		fgets(first, LENGTH, stdin);
		fgets(second, LENGTH, stdin);
		LaunchDelete(first, second);
		
		return 0;
}
