#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void print_permute(string &A,int ind){

    int n = A.size();
    if(ind ==n-1){
        for (int i = 0; i < n; i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
        return;
    }
    int i=0,j=0;
    for ( i = ind; i < n; i++)
    {   
        if(i!=ind && A[i] == A[ind]){ // top avoid cases where duplicates are there
        continue; 
    }
        // do
        swap(A[i],A[ind]);
        //recuresion
        print_permute(A,ind+1);
        // undo ( means backtrack)
        swap(A[i],A[ind]);

    }
    
return;
}
  
int main() 
{   
    string A = "abb";
    sort(A.begin(),A.end());

    print_permute(A,0); 
    cout<<endl;
    return 0;
  }