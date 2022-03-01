#include<bits/stdc++.h>
using namespace std;
  
int main() 
{  
    vector<int> a  ={ 1,2,4,3};
    cout<<*max_element(a.begin()+2+1,a.end());
    
    cout<<endl;
    return 0;
  }