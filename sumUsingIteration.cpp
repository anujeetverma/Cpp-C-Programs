#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void permutation(char a,char b, char c, char d);

int sumOfNaturalNo(int n){
    int sum=0;
    if(n==1){
    return 1;
    }
    if(n==0){
    return sum;
    }
    else{
    return sum = n + sumOfNaturalNo(n-1);
    }
    
    
}

int sumUsingIteration(int n) {
    int sum =0;
    for(int i = n;i>=0; i-- ){
        sum = i+sum;    
    }
    return sum;
}



int main() {


int ans = sumUsingIteration(100);
cout<<ans;

return 0;
}