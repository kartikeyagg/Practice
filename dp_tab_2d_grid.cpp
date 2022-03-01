#include<bits/stdc++.h>
using namespace std;
// no. of ways of traveling a grid 
long int gridtravel(int n, int m){

    vector<vector<long int>> vec(n+1,vector<long int> (m+1,0));
    vec[1][1] = 1; // seed value
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            if(i!=n){
                vec[i+1][j]+=vec[i][j];
            }
            if(j!=m){
                vec[i][j+1]+=vec[i][j];
            }
        }
        
    }

    return vec[n][m];
} 
int main() 
{  
    // long int t = gridtravel(3,3);
    long int t = gridtravel(18,18);
    cout<<"the number of ways of traveling a grid of given dimensions is \n";
    cout<<t<<endl;    
    cout<<endl;
    return 0;
  }