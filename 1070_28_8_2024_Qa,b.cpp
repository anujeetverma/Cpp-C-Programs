#include<iostream>
using namespace std;



void verifier(int* arr, int idealWt){
    //time complexity of the following function is O(n)

    //a. Compute the (time) complexity of your algorithm/program by assuming the known weight of a correct coin.

    //c.Compute the (time) complexity of your algorithm/program by assuming the known weight of a correct coin and extending the case to the number of counterfeit coin more than one (01).
    for (int i=1;i<16;i++){
        if(arr[i]!= idealWt){
            cout<< "coin " << i <<" is a counterfiet coin "<<endl;
        }
    }
}

void ukverifiy(int l, int h){
    while(l!=h){
        int m = (l+h)/2;
        if(sum(l,m)<sum(m+1, h))
            h=m;
        else
            l= m+1;
    }return l;
    }
        
    

}

int sum(int arr[]){
    int size = sizeof(arr)-1;
    int i=0, sum =0;
    for(i; i<size; i++){
        sum = sum +arr[i];
    }
    return sum;
}




int main(){
    int arr[16];
    for (int i=0; i<16; i++){
        cout << "Enter the wt of coin";
        cin>>arr[i];
    }
    int idealWt;
    cout <<"Enter the value of ideal Wt of coin";
    cin >> idealWt;
    verifier(arr, idealWt);
    
    
}