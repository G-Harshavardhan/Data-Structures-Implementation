#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct QUEUE 
{
    int data[MAX_SIZE];
    int front, rear;
};

void queue_initialize(struct QUEUE *q) 
{
    q->front = q->rear = -1;
}

void queue_push(struct QUEUE *q, int v) 
{
    if (q->rear == MAX_SIZE - 1) 
        printf("SORRY, QUEUE IS FULL AND CANNOT PUSH.\n");
    else
    {
        if (q->front == -1) 
            q->front = 0;
        q->data[++q->rear] = v;
    }
}

void queue_pop(struct QUEUE *q) 
{
    if (q->front == -1) 
        printf("SORRY, QUEUE IS EMPTY AND CANNOT POP.\n");
    else 
    {
        int v = q->data[q->front];
        if (q->front == q->rear) 
            q->front = q->rear = -1;
        else 
            q->front++;
    }
}

void queue_peek(struct QUEUE *q) 
{
    if (q->front == -1) 
        printf("SORRY, QUEUE IS EMPTY AND CANNOT PEEK.\n");
    else 
        printf("QUEUE IS POINTING : %d\n",q->data[q->front]);
}

void queue_display(struct QUEUE *q)
{
    if(q->front == -1)
        printf("SORRY, QUEUE IS EMPTY AND CANNOT DISPLAY.\n");
    else
    {
        printf("QUEUE ELEMENTS: ");
        for(int i=q->front;i<=q->rear;i++)
            printf("%d ",q->data[i]);
        printf("\n");
    }
}
