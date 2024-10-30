#include<stdlib.h>
#include<stdio.h>

struct stack{
    int top;
    int size;
    char* arr;
};

int IsEmpty(struct stack* sp){
    if(sp->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int IsFull(struct stack* sp){
    if(sp->top==sp->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void PUSH(struct stack* sp, char v){
    if(IsFull(sp)){

    }
    else{
        sp->top++;
        sp->arr[sp->top]=v;
    }
}

char pop(struct stack* sp){
    if(IsEmpty(sp)){
        printf("underflow");
    }
    else{ 
        char v = sp->arr[sp->top]; 
        sp->top--; 
        return v; 
    } 
}
int match(char a, char b){ 
    if(a=='(' && b==')'){ 
        return 1; 
    } 
    if(a=='{' && b=='}'){ 
        return 1; 
    } 
    if(a=='[' && b==']'){ 
        return 1; 
    } 
    return 0; 
} 
 
int Multi_Paranthesis(char * exp){ 
    struct stack* sp = (struct stack*)malloc(sizeof(struct stack)) ; 
    sp->size=100; 
    sp->top = -1; 
    sp->arr = (char*)malloc(sp->size*sizeof(char)); 
    char popd_chr; 
 
    for(int i = 0; exp[i]!='\0'; i++){ 
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){ 
            PUSH(sp, exp[i]); 
        } 
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){ 
            if(IsEmpty(sp)){ 
                return 0; 
            } 
            else{ 
                popd_chr = pop(sp); 
                if(match(popd_chr,exp[i])){ 
                    return 1; 
                } 
                return 0; 
            } 
        } 
    } 
    if(IsEmpty(sp)){ 
        return 1; 
    } 
    else{ 
        return 0; 
    } 
} 
 
int main(){ 
    char * a = "[a]"; 
 
    if(Multi_Paranthesis(a)){ 
        printf("Paranthesis Matched"); 
    } 
    else{ 
        printf("Paranthesis Not Matched"); 
    } 
    return 0; 
}


