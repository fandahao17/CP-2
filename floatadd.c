#include<stdio.h>
#include<string.h>
#include<ctype.h>
void LaunchAdd(char *first, char *second)
{
		int i = 0;
		char FinalNum[110] = {0};
		for(i = 0; i < 110; i++){
				FinalNum[i] = '0';
		}

		char plus = 0;
		i = 109;
		while(first[i] == '0' && second[i] == '0'){
				i--;
		}
		int last = i;
		while(first[i] != '.'){
				FinalNum[i] = (first[i] - '0') +(second[i] - '0') +plus;
				if(FinalNum[i] >= 10){
						plus = 1;
						FinalNum[i] %= 10;
				}else{
						plus = 0;
				}
				FinalNum[i] += '0';
				i--;
		}
		FinalNum[i] = '.';
		i--;
		while(i >= 0){
				FinalNum[i] = (first[i] - '0') +(second[i] - '0') +plus;
				if(FinalNum[i] >= 10){
						plus = 1;
						FinalNum[i] %= 10;
				}else{
						plus = 0;
				}
				FinalNum[i] += '0';
				i--;
		}
		i++;
		while(FinalNum[i] == '0'){
				if(FinalNum[i + 1] == '.'){
						putchar(FinalNum[i]);
				}
				i++;
		}
		while(FinalNum[last] == '0'){
				last--;
		}
		while(i <= last){
				putchar(FinalNum[i]);
				i++;
		}
		putchar('\n');
}
void ParseInput(char *first, char *second)
{
		int i = 0;
		int FirstDot = 0;
		int SecondDot = 0;
		int FinalDot = 0;
		fgets(first, 110, stdin);	
		fgets(second, 110, stdin);	
		int LenFirst = strlen(first) - 1;
		int LenSecond = strlen(second) - 1;
		for(i = 0; i < LenFirst; i++){
				if(!isdigit(first[i])){
						FirstDot = i;
						break;
				}
		}
		for(i = 0; i < LenSecond; i++){
				if(!isdigit(second[i])){
						SecondDot = i;
						break;
				}
		}
		char FirstNew[110] = {'0'};
		for(i = 0; i < 110; i++){
				FirstNew[i] = '0';
		}
		char SecondNew[110]= {'0'};
		for(i = 0; i < 110; i++){
				SecondNew[i] = '0';
		}
		if(FirstDot >= SecondDot){
				FinalDot = FirstDot + 1;
		}else{
				FinalDot = SecondDot + 1;
		}
		int j = 0;
		for( i = FinalDot - FirstDot, j = 0; j < LenFirst; i++, j++){
				FirstNew[i] = first[j];
		}
		for( i = FinalDot - SecondDot, j = 0; j < LenSecond; i++, j++){
				SecondNew[i] = second[j];
		}
		LaunchAdd(FirstNew, SecondNew);
}

int main(void)
{
		char first[110] = {0};
		char second[110] = {0};

		ParseInput(first, second);
		return 0;
}
