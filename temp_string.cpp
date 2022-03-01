#include<bits/stdc++.h>
using namespace std;
  
int main() 
{  

    vector<int> a = {23,54,6,3,8,1,9};
    a.erase(a.begin()+2);
    cout<<a[2]<<endl;
    a.insert(a.begin()+2,6);
    cout<<a[2]<<endl;

    

    
    cout<<endl;
    return 0;
  }