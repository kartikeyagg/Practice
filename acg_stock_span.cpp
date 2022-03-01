#include<bits/stdc++.h>
using namespace std;
// tell the num of prev consecutive days
// which prices were smaller than the current one 
int main() 
{   
    vector<int> a= {100,80,60,70,60,75,85};
    vector<int> ans(a.size(),0);
    deque<int> q;

    for (int i = 0; i < a.size(); i++)
    {   
        if(q.empty()){
            q.push_back(a[i]);
        }
        else{

            while(!q.empty() && q.back()>=a[i]){
                q.pop_back();
            }
            q.push_back(a[i]);
            
            
        }
        // q.push(a[i]);
        // while(q.size()>1){

        //     if(q.front()>=q.back() ){
        //         q.pop();
        //     }
        //     else{

        //     }

        // }
        ans[i] = q.size();
    }

    for (int i = 0; i < a.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    
    
    
    cout<<endl;
    cout<<endl;
    return 0;
  }