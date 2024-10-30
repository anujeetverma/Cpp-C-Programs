#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4000
int counter(int arr[],int size);
int *generateIntegers(int n);


int counter(int arr[],int size){
    int count = 0;
    for(int i = 0 ; i<size; i++)
        for(int j= i+1; j<size; j++)
            for(int k = j+1; k<size ; k++)
                if(arr[i] + arr[j] + arr[k] ==0)
                count++;
                
    return count;
}

int *generateIntegers(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Memory allocation failed \n");
        return NULL;
    }

    for(int i= 0 ; i < n ; i++) {
        arr[i] = rand();
    }
    return arr;
}

int generateRanNum() {
    int rand_int = rand();
    return rand_int;
}

int main(){
    clock_t start,end;
    double cpu_time_used;

    start = clock();
    int arr[N];
    
    for (int i = 0 ; i <N ; i++ ) {
        arr[i] = generateRanNum();
        
    }
    ////printing the array
    //for (int i = 0 ; i <N ; i++ ){printf("%d ", arr[i]  );}

    printf("%d " , counter(arr,N));
    


    end = clock();

    cpu_time_used = ((double)(end - start )) / CLOCKS_PER_SEC;
    printf("Elapsed time : %f seconds \n", cpu_time_used);

    return 0;
}