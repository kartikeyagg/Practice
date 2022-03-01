#include<bits/stdc++.h>
using namespace std;
vector<int> res;
map<vector<int>,int> mp;
map<int,int> tp;
int bestsum(int target,vector<int> &arr,vector<int> tk){
    if(tp.count(target)>0){
        return -1;
    }
    if(target==0){

        mp[tk] =1;
        return 1;

    }
    if(target<0){return -1;}
    int t;
    int flag =0;
    for (int i = 0; i < arr.size(); i++)
    {   
        tk.push_back(arr[i]);
        t  =bestsum(target-arr[i],arr,tk);
        tk.pop_back();
        if(t!=-1){
            flag=1;
        }
        
            // return -1;
    

    }
    if(flag==0)
    {tp[target] = -1;
    return -1;}
    else{return 1;}
    
}
int main() 
{  
    {  
    // int target =7;
    // vector<int> arr  = {5,3,4,7};
    int target =100;
    vector<int> arr= {1,2,5,25};
    res.clear();
    mp.clear();
    tp.clear();
    vector<int> tl;
    int  p =bestsum(target,arr,tl);
    // if(res.empty()){cout<<" the resultant array is empty";}
    // for (int i = 0; i < res.size(); i++)
    // {
    //     cout<<res[i]<<" ";
    // }
    map<vector<int>,int> :: iterator iter,iterr;
    int minsize = INT32_MAX,temp;
    for ( iter=mp.begin(); iter != mp.end(); iter++)
    {   
        if((*iter).first.size()<minsize){
            minsize = (*iter).first.size();
            iterr = iter;
        }
        // (*iter).first.size();
    }
    vector<int> r1 = (*iterr).first;
    for (int i = 0; i < r1.size(); i++)
    {
        cout<<r1[i]<<" ";
    }
    
    
    cout<<endl;    
    cout<<endl;
    return 0;
  }
    
    cout<<endl;
    return 0;
  }