#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
    };
    void print_data(struct node*head);
    int main(){

//create node
        struct node *head = (struct node*)malloc(sizeof(struct node));
            printf("Enter the data part of the 1st node : ");
            scanf("%d", &head->data);
            head->link =NULL;

// create 2nd node
    struct node *current =(struct node*)malloc(sizeof(struct node));
        printf("Enter data part of 2nd node : ");
        scanf("%d", & current -> data);
        current ->link =NULL;
        head -> link = current;


//create 3rd node
        current = (struct node*)malloc(sizeof (struct node));
            printf("Enter the data part of 3rd node : ");
            scanf("%d", & current -> data);
            current ->link = NULL;
            head ->link ->link= current;
            print_data(head);
            return 0;

    }