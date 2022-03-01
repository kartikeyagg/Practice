#include<bits/stdc++.h>
using namespace std;

void recf(int ind,int target,vector<int> &arr,vector<vector<int>> &ans, vector<int> &ds){
  if(target==0){
      ans.push_back(ds);

    return ;
  }
  if(ind==arr.size()){
    if(target==0){
      ans.push_back(ds);
    }
    return ;
  }
    if(arr[ind]<=target){
      ds.push_back(arr[ind]);
      recf(ind,target-arr[ind],arr,ans,ds);
      ds.pop_back();
    }
  
    recf(ind+1,target,arr,ans,ds);

}
  
int main() 
{  
    int target = 7;
    vector<int> sarr = {3,2,4,7,6};
    vector<int> ds ;
    vector<vector<int>> ans;
    sort(sarr.begin(),sarr.end());
    recf(0,target,sarr,ans,ds);
    cout<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
      for (int j = 0; j < ans[i].size(); j++)
      {
        cout<<ans[i][j]<<" ";
      }
      cout<<endl;
    }
    
    cout<<endl;
    return 0;
  }