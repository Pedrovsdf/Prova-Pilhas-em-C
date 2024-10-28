#include <stdio.h>
#define STACK_SIZE 5

typedef struct stack Stack;



union Elemento
{
    int i;
    float f;
    char c[10];
};

struct Item
{
    /* 
        1 int
        2 float
        3 character
     */
    int type;
    union Elemento item;
};

struct stack
{ // representa a pilha. Deve ser declarada no main
    // [i, f, c][][][]
    int top;
    struct Item items[STACK_SIZE];
};

void push(Stack *ps, struct Item );
struct Item pop(Stack *ps);

int main()
{
    Stack s;
    s.top = -1; // 10 elementos

    struct Item a;
    struct Item b;
    struct Item c;
    struct Item d;
    struct Item aux;

    a.type = 1;
    a.item.i = 10;

    b.type = 2;
    b.item.f = 20.0;

    push(&s, a);
    push(&s, b);

    aux = pop(&s);
    if(aux.type == 1)
        printf("\n%d", aux.item.i);
    else if(aux.type == 2)
        printf("\n%f", aux.item.f);

    aux = pop(&s);
    if(aux.type == 1)
        printf("\n%d", aux.item.i);
    else if(aux.type == 2)
        printf("\n%f", aux.item.f);

    return 0;
}

void push(Stack *ps, struct Item item)
{
    ++ps->top;
    ps->items[ps->top] = item;
}

struct Item pop(Stack *ps)
{
    struct Item aux = ps->items[ps->top];
    --ps->top;
    return aux;
}