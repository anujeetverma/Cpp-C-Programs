#include <iostream>
using namespace std;

void towerOfHanoi(int n, char x, char y, char z){      
    if(n==0)
    return;
    towerOfHanoi(n-1,x,z,y);
    cout << x << "-->" << y <<endl;
    towerOfHanoi(n-1, z,y,x);
    return;
}


int main(){
    int n;
    cout << "Enter the number of disks : ";
    cin >> n;
    towerOfHanoi(n ,'A' ,'B' ,'C');
    return 0;
}