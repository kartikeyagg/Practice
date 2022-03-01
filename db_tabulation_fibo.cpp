#include<bits/stdc++.h>
using namespace std;
// find the fibonacci of given num using tabulation
long int fibo(int n){
    vector<long int> A(n+1,0); // building a table of size N+1 and intial values to be 0
    A[1] =1; // given;
    int i = 0;
    for ( i = 0; i < n-1; i++)
    {
        A[i+1]  += A[i];  // adding the value of current element to next two elements;
        A[i+2] += A[i]; 
    }
    A[i+1] += A[n-1]; // for second last element

    return A[n];
    
}
// the time and space complexities are both O(n);
int main() 
{  long int t = fibo(50);
    cout<<"the fibo of the givn no. is "<<t<<endl;
    
    cout<<endl;
    return 0;
}