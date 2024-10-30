#include <stdio.h>
#include <stdbool.h>

#define N 10

typedef struct {
    int id[N];
} QuickFindUF;

// Initialize the id array
void initialize(QuickFindUF *uf) {
    for (int i = 0; i < N; i++)
        uf->id[i] = i;
}

// Check whether p and q are in the same component
void connected(QuickFindUF *uf, int p, int q) {
    if(uf->id[p] == uf->id[q]){
        printf("Connected");
    }else{printf("Not Connected");}
    printf("\n");
}



// Change all entries with id[p] to id[q]
void union_(QuickFindUF *uf, int p, int q) {
    int pid = uf->id[p];
    int qid = uf->id[q];
    for (int i = 0; i < N; i++)
        if (uf->id[i] == pid)
            uf->id[i] = qid;
}

int main() {
    QuickFindUF list;
    initialize(&list);
    union_(&list, 2, 3);
    union_(&list, 3, 8);
    union_(&list, 7, 8);
    union_(&list, 0, 5);

    // Output the contents of the id array
    printf("ID array after unions:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", list.id[i]);
    printf("\n");

    
    union_(&list ,5,6 );
    union_(&list ,6,7 );
    connected(&list, 0,2);

    return 0;
}
