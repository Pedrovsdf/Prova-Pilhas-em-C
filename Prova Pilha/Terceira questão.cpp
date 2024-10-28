#include <stdio.h>
#include <stdio.h>
#define STACK_MAX 100

struct Stack {
	int top;
    int items[STACK_MAX];
};

void push(struct Stack * S, int elm){
	S->top++;
	S->items[0] = S->top;
    S->items[S->top] = elm;
}

int pop(struct Stack * S){
	S->items[0] = S->top - 1;
	return S->items[--S->top];
}

int top(struct Stack * S){
    int top = pop(S);
    push(S, top);
    return top;
}

bool empty(struct Stack * S){	
	return S->top == 0;
}

int main(){

	return 0;
}

