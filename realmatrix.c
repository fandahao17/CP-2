#include <stdio.h>
#include <stdlib.h>
#define small(A, B) A>B? B:A

struct Node;
typedef struct Node {
	 int index;
	 struct Node *prev; 
} Node;
typedef struct {
	 int bottom;
	 Node *first;
	 Node *last; 
	 int top;
} Stack;

int n = 0;	
int m = 0;	
int max = 1;	
int max_square = 1;	

void push(Stack *stack, int index, int value)
{
	 printf("Pushed: %d\n", index);
	 Node *node = calloc(1, sizeof(Node));
	 node->index = index;
	 stack->top = value;
	 if (stack->last == NULL) {
		  printf("Bottom: %d\n", index - 1);
		  stack->bottom = index - 1;
	 }else{
		  node->prev = stack->last;
	 }
	 stack->last = node;
}
int pop(Stack *stack)
{
	 if (stack->last == NULL) {
		  return -1;
	 }
	 int index = stack->last->index;
	 Node *ptr = stack->last;
	 if(stack->last->prev == NULL){
		  printf("Empty\n");
		  stack->top = -1;
		  stack->last = NULL;
	 }else{
		  stack->last = stack->last->prev;
	 }
	 free(ptr);
	 return index;
}

int stack[2001] = {0};
void find_largest(int **matrix, int **value)
{
	 for (int j = 0; j < m; ++j) {
		  stack[0] = 0;
		  if (matrix[0][j] == matrix[1][j]) {
			   if (value[0][j] >max) {
					max = value[0][j];
			   }
			   value[0][j] = 0;
		  }
		  int top = 0;
		  int count = 1;
		  for (int i = 1; i < n; ++i) {
			   //printf("top = %d\n", top);
			   if ((matrix[i][j] == matrix[i-1][j] && value[i-1][j] != 0)) {
					//printf("one\n");
					while (top) {
						 top--;
						 count = i - stack[top] - 1;
						 if (count * value[stack[top+1]][j] > max) {
						 	 max = count * value[stack[top+1]][j];
							 //printf("max= %d, i = %d, j = %d\n",max, i, j);
						 }
						 int Small = small(count,value[stack[top+1]][j]);
						 if (Small > max_square) {
							  max_square = Small;
							  //printf("maxs= %d, i = %d, j = %d\n",max_square, i, j);
						 }
					}
					if (matrix[stack[0]][j] != matrix[stack[0]+1][j]) {
						 count = i - stack[0];
						 if (count * value[stack[0]][j] > max) {
						 	 max = count * value[0][j];
							 //printf("max= %d, i = %d, j = %d\n",max, i, j);
						 }
						 int Small = small(count,value[0][j]);
						 if (Small > max_square) {
							  max_square = Small;
							  //printf("maxs= %d, i = %d, j = %d\n",max_square, i, j);
						 }

					}
					stack[0] = i;
					if (i != n-1 &&matrix[i][j] == matrix[i+1][j]) {
						 if (value[i][j] >max) {
							  max = value[i][j];
						 }
						 value[i][j] = 0;
					}
					top = 0;
			   }else if(value[i][j] >= value[stack[top]][j]){
					//printf("two\n");
					stack[++top] = i;
					//printf("%d %d", i, j);
			   }else{
					//printf("three\n");
					while (top >= 0&&value[i][j] < value[stack[top]][j]) {
						 printf("top = %d\n", top);
						 top--;
						 //printf("stack[top] = %d\n", stack[top]);
						 count = i - stack[top] - 1;
						 if (count * value[stack[top+1]][j] > max) {
						 	 max = count * value[stack[top+1]][j];
							 //printf("max= %d, i = %d, j = %d\n",max, i, j);
						 }
						 int Small = small(count,value[stack[top+1]][j]);
						 if (Small > max_square) {
							  max_square = Small;
							  //printf("maxs= %d, i = %d, j = %d\n",max_square, i, j);
						 }
					}
					stack[++top] = i;
			   }
		  }
		  while (top) {
			   top--;
			   //printf("stack[top] = %d\n", stack[top]);
			   count = n - stack[top] - 1;
			   if (count * value[stack[top+1]][j] > max) {
					max = count * value[stack[top+1]][j];
					//printf("max= %d, i = %d, j = %d\n",max, n, j);
			   }
			   int Small = small(count,value[stack[top+1]][j]);
			   if (Small > max_square) {
					max_square = Small;
					//printf("maxs= %d, i = %d, j = %d\n",max_square, n, j);
			   }
		  }
		  if (stack[0] != n-1 &&matrix[stack[0]][j] != matrix[stack[0]+1][j]) {
			   count = n - stack[0];
			   if (count * value[stack[0]][j] > max) {
					max = count * value[0][j];
					//printf("max= %d, i = %d, j = %d\n",max, n, j);
			   }
			   int Small = small(count,value[0][j]);
			   if (Small > max_square) {
					max_square = Small;
					//printf("maxs= %d, i = %d, j = %d\n",max_square, n, j);
			   }

		  }
	 }
}
int main(void)
{
	 scanf("%d%d", &n, &m);
	 int **matrix = calloc(n, sizeof(int*));
	 int **value = calloc(n, sizeof(int*));
	 int i = 0;	
	 int j = 0;	
	 int count = 1;	
	 for (i = 0; i < n; i++) {
		  matrix[i] = calloc(m, sizeof(int));
		  value[i] = calloc(m, sizeof(int));
		  scanf("%d", &matrix[i][0]);
		  if (i != 0 && matrix[i][0] == matrix[i-1][j]) {
			   value[i][0] = 0;
		  }
		  value[i][0] = 1;
		  //printf("%d ", value[i][0]);
		  count = 1;
	 	 for (j = 1; j < m; j++) {
	 	 	 scanf("%d", &matrix[i][j]);
			 if (matrix[i][j] != matrix[i][j-1]) {
				  count++;
			 }else{
				  count = 1;
			 }
			 value[i][j] = count;
			 //printf("%d ", value[i][j]);
	 	 }
		 //printf("\n");
	 }
	 find_largest(matrix, value);
	 printf("%d\n%d\n",max_square * max_square, max);
	 return 0;
}
