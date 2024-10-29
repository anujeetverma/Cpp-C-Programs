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

int main() {
    int ans = sumOfNaturalNo(100);
    cout<< ans;
}