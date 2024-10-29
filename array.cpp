#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int a;
    int arr[10000];
    cin >> a;
    
    for(int i=0;i<a;i++){
        scanf("%d ", &arr[i]);
    }
    
    for(int i=a-1;i>=0;i--){
        printf("%d ",arr[i]);
    }
    
    
    return 0;
}
