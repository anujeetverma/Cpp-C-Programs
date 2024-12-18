#include<stdio.h> 
#include<stdlib.h> 
 
struct node{ 
    int data; 
    struct node* next; 
}; 
 
void LinkList_Traversal(struct node *top){ 
    while (top!=NULL) 
    { 
        printf("%d ",top->data); 
        top=top->next;  
    } 
    printf("\n"); 
     
} 
 
int IsEmpty(struct node* top){ 
    if(top==NULL){ 
        return 1; 
    } 
    else{ 
        return 0; 
    }     
} 
 
int IsFull(struct node* top){ 
    struct node* new = (struct node*)malloc(sizeof(struct node)); 
    if(new==NULL){ 
        return 1;  // memory allocation not done. 
    } 
    else{  
        return 0; 
    }     
} 
 
struct node* push(struct node* top, int value){ 
    if(IsFull(top)){ 
        printf("stack is full"); 
    } 
    else{ 
        struct node* new = (struct node*)malloc(sizeof(struct node)); 
        new->data = value; 
        new->next = top; 
        top = new; 
        return top; 
        // return top; 
    } 
} 
 
int pop(struct node** top){ 
    if(IsEmpty(*top)){ 
        printf("stack is Empty"); 
    } 
    else{ 
        struct node* new = *top; 
        (*top)=(*top)->next; 
        int x = new->data; 
        free(new); 
        return x; 
    } 
} 
 
 
int main(){ 
    struct node* top = NULL; 
 
    int choice, data; 
    while (1) { 
        printf("\nStack Operations Using Arrays:\n"); 
        printf("1. Push\n"); 
        printf("2. pop\n"); 
        printf("3. Is Empty\n"); 
        printf("4. Is Full\n"); 
        printf("5. Display\n"); 
        printf("6. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter data to insert: "); 
                scanf("%d", &data); 
                top = push(top,data); 
                break; 
            case 2: 
                pop(&top); 
                break; 
            case 3: 
                IsEmpty(top); 
                break; 
            case 4: 
                IsFull(top); 
                break; 
            case 5: 
                LinkList_Traversal(top); 
                break; 
            case 6: 
                exit(0); 
            default: 
                printf("Invalid choice!\n"); 
        } 
    } 
    return 0; 
}