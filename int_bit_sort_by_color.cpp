#include<bits/stdc++.h>
using namespace std;
void sortColors(vector<int> &A) {

    int n = A.size();
    int count0=0, count1=0,i,j;
    for(i=0;i<n;i++){
        if(A[i]==0){
            count0++;
        }
        else if(A[i]==1){
            count1++;

        }
    }
    int i0 =0,i1 =1,i2 =1;
    i=0;

    i=-1;j=0;
    while(i<n-1 && j<n){
        if(i==j){
            j++;
        }
        if(A[i+1]==0)
        {
            i++;
        }
        else if(A[j]==0 && j!=i ){

            swap(A[i+1],A[j]);
            j++;

        }
        else {
            j++;

        }

    }
    i=count0-1;j=count0;
    while(i<n-1 && j<n){
        if(i==j){
            j++;
        }        
        if(A[i+1]==1)
        {
            i++;
        }
        else if(A[j]==1 && j!=i){

            swap(A[i+1],A[j]);
            j++;

        }
        else {
            j++;

        }

    }     
} 
int main() 
{  
    vector<int> a  = { 1, 0, 0, 1, 1, 0, 0, 2, 1, 2, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0, 0, 2, 0, 2, 2, 2, 0, 0, 1, 1, 1, 2, 2, 0, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 1, 2, 1, 1, 0, 0, 1, 2, 1, 1, 0, 1, 0, 2, 0, 2, 1, 0, 1, 1, 0, 0, 1, 2, 0, 1, 0, 2, 1, 0, 1, 0, 1, 0, 1, 2, 2, 2, 0, 1, 1, 0, 2, 2, 2, 0, 0, 0, 0, 1, 1, 2, 1, 0, 1, 0, 1, 2, 2, 1, 0, 2, 0, 0, 1, 2, 1, 0, 2, 1, 0, 2, 0, 2, 1, 1, 1, 1, 1, 0, 1, 2, 0, 0, 1, 0, 1, 2, 0, 1, 1, 2, 1, 0, 2, 0, 0, 0, 2, 0, 1, 0, 2, 1, 1, 0, 1, 2, 1, 0, 0};
    sortColors(a);
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    cout<<endl;
    return 0;
  }