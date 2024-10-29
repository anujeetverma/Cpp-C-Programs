#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void permute(string s, int l, int r)
{
   // Base case
if (l == r)
    cout<<s<<" ";
else{
    for (int i = l; i <= r; i++)
    {
          // Function to swap
        swap(s[l], s[i]);

          // Recursion called
        permute(s, l+1, r);

        
        swap(s[l], s[i]);
        }
    }
}

int main() {
string str = "ABCDEFGH";

int n = str.size();

permute(str, 0 , n-1);
return 0;
}