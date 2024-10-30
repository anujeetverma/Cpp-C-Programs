#include<stdio.h>
#include<stdlib.h>
    //to create a node in linked list

    struct node{
        int data;
        struct node *link;

    };

    
int main(){
    struct node *head = NULL;
    head = (struct node*)malloc(sizeof (struct node));
    printf("Enter data part of the node: ");
    scanf("%d", &head -> data);
    head -> link = NULL;
    printf("The data part of the node is : %d\n", head -> data);
    printf("The link part of node is : %d", head ->link);
    return 0;
    }