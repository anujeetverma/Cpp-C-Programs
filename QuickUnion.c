#include <Stdio.h>

#define N 10

//Initialize the id array
void initialize(int id[]) {
    for (int i = 0 ; i < N ; i++)
        id[i] = i;
}

//find the root of the component containing p
int root(int id[], int p) {
    while (p != id[p])
        p = id[p];

    return p;
}

//Merge the component containing p with the component containing q
void union_(int id[], int p , int  q) {
    int root_p = root(id,p);
    int root_q = root(id,q);
    id[root_p] = root_q;
}

void connected (int id[], int p ,int q) {
    if(root(id,p) == root(id,q)){
        printf("%d and %d  are connected. \n",p,q );
    }
    else{
        printf("%d and %d  are not connected. \n",p,q);
    }
}


int main () {
    int id[N];
    initialize(id);
    union_(id,4,3);
    union_(id,3,8);
    union_(id,6,5);
    union_(id,9,4);
    union_(id,2,1);

    //check if 8 and 9 are connected
    connected(id, 8, 9);
    connected(id,9,3);
        
        return 0;

}