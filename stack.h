#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct STACK 
{
    int data[MAX_SIZE];
    int top;
};

void stack_initialize(struct STACK *s) 
{
    s->top = -1;
}

void stack_push(struct STACK *s, int v)
{
    if (s->top == MAX_SIZE - 1) 
        printf("SORRY, STACK IS FULL AND CANNOT PUSH.\n");
    else 
        s->data[++s->top] = v;
}

void stack_pop(struct STACK *s)
{
    if (s->top == -1) 
        printf("SORRY, STACK IS EMPTY AND CANNOT POP.\n"); 
    else
        s->data[s->top--];
}

void stack_peek(struct STACK *s) 
{
    if (s->top == -1) 
        printf("SORRY, STACK IS EMPTY AND CANNOT PEEK.\n");
    else 
        printf("STACK IS POINTING : %d ",s->data[s->top]);
}

void stack_display(struct STACK *s)
{
    printf("STACK ELEMENTS : ");
    for(int i=0;i<=s->top;i++)
        printf("%d ",s->data[i]);
}
