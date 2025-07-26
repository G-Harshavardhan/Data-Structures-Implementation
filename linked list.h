#include <stdio.h>
#include <stdlib.h>

struct NODE 
{
    int data;
    struct NODE* next;
};

struct NODE* createNode(int v) 
{
    struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
};

void append(struct NODE** head, int v) 
{
    struct NODE* newNode = createNode(v);
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    struct NODE* current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
}

void delete(struct NODE** head, int v) 
{
    if (*head == NULL) 
        return;
    if ((*head)->data == v) 
    {
        struct NODE* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct NODE* current = *head;
    while (current->next != NULL && current->next->data != v) 
        current = current->next;
    if (current->next == NULL) 
        return;
    struct NODE* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void display(struct NODE* head)
{
    struct NODE* current = head;
    printf("LINKED LIST ELEMENTS : ");
    while (current != NULL) 
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
