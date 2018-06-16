#include <stdio.h>
#include <string.h>

char result[1024] = {0};
int curPos = 0;
void print(char *string)
{
		int length = strlen(string);
		int i = 0;	
		for (i = 0; i < length; i++) {
				result[curPos + i] = string[i];	
		}
		curPos += length;	
}
void expression()
{
		char a[10] = {0};
		scanf("%s", a);
		switch (a[0]) {
				case '+':
						print("(");
						expression();
						print("+");
						expression();
						print(")");
						break;
				case '-':
						print("(");
						expression();
						print("-");
						expression();
						print(")");
						break;
				case '*':
						print("(");
						expression();
						print("*");
						expression();
						print(")");
						break;
				case '/':
						print("(");
						expression();
						print("/");
						expression();
						print(")");
						break;
				default: 
						print(a);
		}
}
int main(void)
{
		expression();
		printf("%s\n", result);
		return 0;
}
