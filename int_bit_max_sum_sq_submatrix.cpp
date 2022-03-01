#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

int solve(vector<vector<int> > &A, int B) {
    int n = A.size();
    int maxsum = -INT_MAX,curret_sum =0;
    vector<vi> col(n-(B-1));

    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < B; k++)
        {
            curret_sum+=A[k][j];
        }
        col[0].push_back(curret_sum);
        // curret_sum =0;
        for (int i = 1; i < n-(B-1); i++)
        {
            curret_sum  -= A[i-1][j];
            curret_sum+= A[i+B-1][j];

            col[i].push_back(curret_sum);
        }
        curret_sum =0;
        
        
    }
    curret_sum =0;

    for (int i = 0; i < col.size(); i++)

    {  
        for (int k = 0; k < B; k++)
        {
            curret_sum+=col[i][k];
            cout<<"cur sum is "<<curret_sum<<endl;
        }
        maxsum = max(maxsum,curret_sum);

        for(int j=1;j<n-(B-1);j++){

            curret_sum -= col[i][j-1];
            curret_sum += col[i][j+B-1];
            cout<<"cur sum is "<<curret_sum<<endl;
            maxsum = max(maxsum,curret_sum);




        }
        curret_sum =0;
        
    }
    

    for (int i = 0; i < n-(B-1); i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<col[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
    cout<<"maxsum is "<<maxsum<<endl;
    return maxsum;
    }

int main() 
{    
    vector<vi> A = {{1,2,3},{4,5,6},{7,8,9}};
    int B = 3;
    int res = solve(A,B);
    
    return 0; 
    }