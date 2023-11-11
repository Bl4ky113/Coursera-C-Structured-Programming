/* 
	Stack an Abstract Data Stucture
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100
#define EMPTY -1
#define FULL (MAX_LEN - 1)

typedef struct stack {
	char data[MAX_LEN];
	int top;
} stack;

char top (stack *stk) {
	return stk->data[stk->top];
}

int push (char data_char, stack *stk) {
	stk->top++;
	stk->data[stk->top] = data_char;

	return stk->top;
}

char pop (stack *stk) {
	return stk->data[stk->top--];
}

void reset (stack *stk) {
	stk->top = EMPTY;
}

int is_full (stack *stk) { return stk->top == FULL; }
int is_empty (stack *stk) { return stk->top == EMPTY; }

int main (void) {
	stack my_stack;

	push('a', &my_stack);
	push('s', &my_stack);
	push('3', &my_stack);
	push('t', &my_stack);

	printf("%c\n", top(&my_stack));

	printf("\t%c\n", pop(&my_stack));

	printf("%c\n", top(&my_stack));

	reset(&my_stack);

	printf("%c\t%d\t%c\t%d\n", top(&my_stack), my_stack.top, my_stack.data[my_stack.top], is_empty(&my_stack));

	return 0;
}
