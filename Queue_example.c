/*
 * File   : main.c
 * Author : zentut.com
 * Purpose: queue program
 */
#include <stdio.h>
#include <stdlib.h>
 
#include "ARRAYQueue.h"
 
int main()
{
    const int SIZE = 5; /* queue's size */
    int head, tail, element;
    int queue[SIZE];
 
    init(&head,&tail);
 
    printf("--Enqueue elements--\n");
    /* push elements into stack */
    while(!full(tail,SIZE))
    {
        printf("Enter a number to enqueue:");
        scanf("%d",&element);
 
        enqueue(queue,&tail,element);
 
        display(queue,head,tail);
    }
    printf("Queue is full\n\n");
 
    printf("--Dequeue elements --\n");
    while(!empty(head,tail))
    {
        element = dequeue(queue,&head);
        printf("dequeue element %d \n",element);
 
        display(queue,head,tail);
    }
    printf("Queue is empty\n");
    return 0;
}