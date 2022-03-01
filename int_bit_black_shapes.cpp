#include<bits/stdc++.h>
using namespace std;
  

void recfun(int i,int j,vector<string> &A,vector<vector<int>> &vec){

    if(i-1>=0 && A[i-1][j] == 'X' && vec[i-1][j] == 0 ){
        vec[i-1][j] =1;

        recfun(i-1,j,A,vec);
    }
    if(j-1>=0 && A[i][j-1] == 'X' && vec[i][j-1] == 0){
        vec[i][j-1]  = 1;
        recfun(i,j-1,A,vec);
    }
    if(i+1<A.size() && A[i+1][j] == 'X' && vec[i+1][j] == 0){
        vec[i+1][j] = 1;
        recfun(i+1,j,A,vec);
    }
    if(j+1<A[0].size() && A[i][j+1] == 'X' && vec[i][j+1] == 0){
        vec[i][j+1] = 1;
        recfun(i,j+1,A,vec);
    }
    return ;
}
int black(vector<string> &A) {
    vector<vector<int>> vec(A.size(),vector<int> (A[0].size(),0));
    for(int i =0 ;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;}

    int ans=0;
    for(int i =0 ;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(A[i][j] == 'X' && vec[i][j]==0){
                cout<<"found an X at "<<i<<" "<<j<<endl;
                ans++;
                recfun(i,j,A,vec);           
            }
        }
    }
    return ans;
}
int main() 
{  vector<string> A = {"OOOXOOO", "OOXXOXO", "OXOOOXO" };
    int t  = black(A);
    cout<<t<<endl;
    
    
    cout<<endl;
    return 0;
  }