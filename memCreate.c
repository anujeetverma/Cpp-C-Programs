#include <stdio.h>
#include<stdlib.h>

int main(){
    int *ptr = NULL;
    ptr=(int*)malloc(sizeof(int)*5);

//Input
    for(int i=0; i<5; i++)
        scanf("%d", ptr +1);

//printing
    for(int i=0;i<5; i++)
        printf("%d", *(ptr+1));
    return 0;
}