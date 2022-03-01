#include<bits/stdc++.h>
using namespace std;
// this question utilizes matrix exponencation

// function for muliplication of sq matrices
vector<vector<int>> multip1(vector<vector<int>> &a,vector<vector<int>>&b){
  int n = a.size();
  vector<vector<int>> ans(n,vector<int> (n,0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        ans[i][j]+= a[i][k]*b[k][j];
      }
      
    }
    
  }
  return ans;
  

}
// funtion to exponentiate
vector<vector<int>> matrixexpon(vector<vector<int>> &a,int n){

  if(n==0){
    int sz = a.size();
    vector<vector<int>> ans(sz,vector<int> (sz,0));

    for (int i = 0; i < sz; i++)
    {
      ans[i][i] =1;
    }

    return ans;
    

  }
  if(n==1){
    return a;
  }
  vector<vector<int>> temp = matrixexpon(a,n/2);

  vector<vector<int>> ans = multip1(temp,temp);
  if(n%2==1){
    ans = multip1(ans,a);
  }
  return ans;


}
int main() 
{  

  int n;
  cout<<"Enter a num \n";
  cin>>n;
  vector<vector<int>> a  = {{1,1},{1,0}};

  vector<vector<int>> ans = matrixexpon(a,n);

  int sz = ans.size();
  for (int i = 0; i < sz; i++)
  {
    for (int j = 0; j < sz; j++)
    {
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
  

    
    
    cout<<endl;
    return 0;
  }