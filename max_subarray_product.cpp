#include<bits/stdc++.h>
using namespace std;
  
int main() 
{  
    vector<int> A ={6,-3,-10,0,2};
    int n = A.size();
    int maxp =1;
    int res=1;
    if(n==1){
        return A[0];
    }
    int countn(0),count0(0);
    for(auto x:A){
        if(x<0){
            countn++;
        }
        else if(x==0){count0++;}
    }
    if(count0 ==0 && countn%2==0){
        for(auto x:A){
            res*=x;
        }
        cout<<res<<endl;
        // return x;
    }
    if(count0 == n){
        cout<<n<<endl;
    }
    stack<int> sp;
    for(auto x:A){
        if(x<0){
            sp.push(x);
        }
        else if(x==0){
            
        }
    }
    
    cout<<endl;
    return 0;
  }