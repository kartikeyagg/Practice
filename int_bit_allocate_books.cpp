#include<bits/stdc++.h>
using namespace std;
int findsum(vector<int> &A){
    int t =0;
    for(int i =0;i<A.size();i++){
        t+=A[i];
    }
    return t;
}

int books(vector<int> &A, int B) {
    int n  = A.size(),i,j;
    if(n<B){
        return -1;
    }
    if(B==n){return *max_element(A.begin(),A.end());}
    i=0;
    int suma = findsum(A);
    cout<<"sum of vec is "<<suma<<endl;
    if(n==1){return suma;}
    int c=0,k = suma/B;
    cout<<"K is "<<k<<endl;
    int maxt=0,cursum = 0;
    while(i<n && c <B ){
        cout<<"for index "<<i<<endl;

        if(cursum+A[i] <= k || cursum ==0 || c == B-1){
            cursum+=A[i];
            cout<<"cursum is "<<cursum<<endl;
        }
        else{
            if(*min_element(A.begin()+i,A.end()) == A[i]){
                cursum+= A[i];
                cout<<"cursum is "<<cursum<<endl;    
                maxt = max(maxt,cursum);
            }
                cursum =0;
                c++;

        }
        maxt = max(maxt,cursum);
        i++;
    }

    return maxt;
    
}

int main() 
{  
    vector<int> A = { 73, 58, 30, 72, 44, 78, 23, 9 };
    int B = 5;
    int t = books(A,B);
    cout<<"Answer is "<<t<<endl;
    
    
    cout<<endl;
    return 0;
  }
// A : [ 73, 58, 30, 72, 44, 78, 23, 9 ]
// B : 5

// The expected return value: 
// 110
// Your function returned the following: 
// 44
