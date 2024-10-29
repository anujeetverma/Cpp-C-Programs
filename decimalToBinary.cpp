#include <iostream>
using namespace std;

int DecToBin(int n){
    int ans=0, pow=1;
    int decNum = n;
    int rem =0;
    while(decNum>0){
        rem = decNum%2;
        decNum = decNum/2;
        ans += rem*pow;
        pow = pow*10;
    }
    return ans;
    }

int main(){

    for(int i=1; i<=10;i++){
        cout << "The decimal form of " << i << "is "<< DecToBin(i)<< "\n";

    }
    for(int i= 10; i>0; i--){
        cout << "The decimal form of " << i << "is "<< DecToBin(i)<< "\n";
    }
}