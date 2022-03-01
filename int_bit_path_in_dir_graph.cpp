#include<bits/stdc++.h>
using namespace std;
int solve(int A, vector<vector<int> > &B) {
    int i,n  = B.size(),j;
    vector<int> res(A+1,0);
    res[0] =1;
    sort(B.begin(),B.end());
    for (int k = 0; k < B.size(); k++)
    {
        for (int h = 0; h < B[0].size(); h++)
        {
            cout<<B[k][h]<<" ";
        }
        cout<<endl;
        
    }
    
    if(B[0][0] != 1){
        return 0;
    }
    res[1] =1;
    for(i =0;i<n;i++){

        if(res[B[i][0]]==1){
            res[B[i][1]]=1;
        }
        if(res[A]==1){
            return 1;
        }
    }
    return res[A];
}  


int main() 
{  
    int A = 5;
    vector<vector<int>>B = {  {1, 2}, 
        {4, 1}, 
        {2, 4}, 
        {3, 4}, 
        {5, 2}, 
        {1, 3} };
    int t =solve(A,B);

    cout<<"Ans "<<t<<endl;

    
    cout<<endl;
    return 0;
  }