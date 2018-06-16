#include <stdio.h>
#include <string.h>

#define LENGTH 110
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
void LaunchAdd(char *first, char *second)
{
		int FirstResult[LENGTH] = {0};
		int SecondResult[LENGTH] = {0};
		int FirstLength = ParseInput(first, FirstResult);	
		int SecondLength =ParseInput(second, SecondResult);
		int FinalLength = FirstLength + SecondLength;
		int FinaleResult[2 * LENGTH] = {0};
		int temp = 0;	
		for (int i = 0; i < FirstLength;++i) {
				for (int j = 0; j < SecondLength;++j) {
						temp = FirstResult[FirstLength - i - 1] *
							   	SecondResult[SecondLength - j - 1];
						if (temp >= 10) {
								FinaleResult[FinalLength - i - j - 2] += 
										(temp / 10);
								temp %= 10;
						}
						FinaleResult[FinalLength - i - j - 1] += temp;
								if (FinaleResult[FinalLength - i - j - 1
												]>= 10) {
										FinaleResult[FinalLength - i - j - 2] += 
										(FinaleResult[FinalLength - i - j - 1 ] / 10);
								FinaleResult[FinalLength - i - j - 1] %= 10;
								}
				}
		}
		PrintResult(FinaleResult, FinalLength);
}
int main(void)
{
		char first[LENGTH] = {0};	
		char second[LENGTH] = {0};	
		fgets(first, LENGTH, stdin);
		fgets(second, LENGTH, stdin);
		LaunchAdd(first, second);
		
		return 0;
}
