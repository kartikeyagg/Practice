#include<bits/stdc++.h>
using namespace std;
  
int main() 
{       vector<int> sarr = { 8, 10, 6, 11, 1, 16, 8 };
        sort(sarr.begin(),sarr.end());

        for(int i=0;i<sarr.size()-1;i++){

        if(sarr[i]==sarr[i+1]){
            sarr.erase(sarr.begin()+i);
            i--;
            // n--;
        }

    }
    for (int i = 0; i < sarr.size(); i++)
    {
        cout<<sarr[i]<<" ";
    }
    
    
    cout<<endl;
    return 0;
  }