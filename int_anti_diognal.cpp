#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > diagonal(vector<vector<int> > &A) {
    int n = A.size();
    int N = 2*(n-1) + 1;//number of vectors in ans
    vector<vector<int>> ans(N);
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
            ans[i+j].push_back(A[i][j]);//sum of index values in 2d array gives the index in ans
    }
    return ans;}
int main() 
{  
    vector<vector<int>> A = 
    {{1,2,3},
    {4,5,6},
    {7,8,9}};
    vector<vector<int>> res  = diagonal(A);

    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<endl;
    return 0;
  }