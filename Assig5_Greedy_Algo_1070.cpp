#include<iostream>
#include <algorithm> 

using namespace std;

int max_container_loading(int W_capacity, int containers[], int numberOfContainers, int x[]);
int max_weight_loading(int W_capacity, int containers[], int numberOfContainers, int x[]);
// C=400, n=8 and [w_1,.......,w_8]=[100, 200, 50, 90, 150, 50, 20, 80].

int main(){
    int containers[] = {100,200, 50, 90, 150, 50, 20, 80};
    int W_capacity = 400;  
    int numberOfContainers = 8; 
    int x[8] = {0};  
    
    max_weight_loading(W_capacity, containers, numberOfContainers, x);
    
    
    // Output the selected containers
    cout << "Max Containers loaded: ";
    for(int i = 0; i < numberOfContainers; i++){
        if(x[i] == 1)
            cout << containers[i] << " ";
    }
    cout << endl;
    
    return 0;
}


int max_container_loading(int W_capacity, int containers[], int numberOfContainers, int x[]){
   sort(containers, containers + numberOfContainers);
    
    int currentCapacity = W_capacity;  // Remaining capacity of the container
    
    for(int i = 0; i < numberOfContainers; i++){
        if(containers[i] <= currentCapacity){
            x[i] = 1;  
            currentCapacity -= containers[i];  
        } else {
            x[i] = 0;  
        }
    }
    
    return currentCapacity;
}

int max_weight_loading(int W_capacity, int containers[], int numberOfContainers, int x[]){
    sort(containers, containers + numberOfContainers);
    reverse(containers, containers + numberOfContainers);
    
    int currentCapacity = W_capacity;
    
    for(int i=0; i< numberOfContainers; i++){
        if(containers[i] <= currentCapacity){
            x[i] = 1;
            currentCapacity -= containers[i];

        }else{
            x[i]=0;
        }
    }
}
