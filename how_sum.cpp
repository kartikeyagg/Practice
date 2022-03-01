#include<bits/stdc++.h>
// given a target and  an  array 
// return the elements corresponding to sum 
using namespace std;
vector<int> res ={};
map<int,int> mp; // for memoization
int howsum(int target, vector<int> &arr){
    if(mp.count(target)>0){ // check if we have checked for the given
                            // target already
        return -1;
    }
    if(target==0){
        return 1;
    }
    if(target<0){return -1;}
    int t;
    // int flag =0;
    for (int i = 0; i < arr.size(); i++)
    {
        t = howsum(target-arr[i],arr);
        if(t>0){
            res.push_back(arr[i]);
            return arr[i];
        }
        // else if(t==-1){
        //     mp[target] =-1;
        //     return -1;
        // }
    }
mp[target]  =-1;    
return -1;
}  
int main() 
{  
    // int target =7;
    // vector<int> arr  = {5,3,4,7};
    int target =300;
    vector<int> arr= {7,14};
    res.clear();
    int  p =howsum(target,arr);
    if(res.empty()){cout<<" the resultant array is empty";}
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;    
    cout<<endl;
    return 0;
  }