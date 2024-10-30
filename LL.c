#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*start = NULL;

void create() {
    struct node *newNode, *p;
    newNode = (struct node* )malloc (sizeof(struct node));
    printf("Enter the data of the new node");
    scanf("%d", &newNode -> data);
    newNode -> next = NULL;

    if(struct == NULL)
    struct = newNode;

    else {
        p = *start ;
        while(p -> next != NULL)
        p = p -> next;
        p  -> next = newNode;
    }

}