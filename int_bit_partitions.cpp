#include<bits/stdc++.h>
using namespace std;

// You are given a 1D integer array B containing A integers.

// Count the number of ways to split all the elements of the array into 3 contiguous parts so that the sum of elements in each part is the same.

// Such that : sum(B[1],..B[i]) = sum(B[i+1],...B[j]) = sum(B[j+1],...B[n]) 
int partition1(int A,vector<int> &B){
    int i =0,j=0,k=0;
    int sum =0;
    int res =0;
    // vector<int> br = B;
    for ( i = 0; i < B.size(); i++)
    {
        sum+=B[i];
    }
    i=0;
    k = sum/3;
    if(sum%3 != 0){
        
        return 0;

    }
    int sumx(0),sumy(0),sumz(0),sum1 = sum,sumt;
    for ( i = 0; i < B.size(); i++)
    {
        sumx+=B[i];
        sum1-=B[i];

        // if(sum1+1 < 2*k){cout<<"breaking at i :"<<i<<endl;break;}
        if(sumx == k){
            sumt = sum1;

            sumy=0;
            for ( j = i+1; j < B.size(); j++)
            {
                sumy+=B[j];  
                sumt-=B[j];
                // if(sumt+1< k){
                //     break;

                // }
                if(sumy == k && sumt == k && j!=B.size()-1){
                    cout<<"for I = "<<i<<" j = "<<j<<endl;
                    res++;
                }

            }
            
        }
        
    }

    return res;

    
}

int main() {
//   vector<int> a = {1, 2, 3, 0,3}; // 2
//   vector<int> a = {3, 3, -3, 3, 3}; //3
  vector<int> a = {0,1,-1,0}; //1

    int k = partition1(a.size(),a);

    cout<<"Answer is "<<k<<endl;
    
    
    cout<<endl;
    return 0;
  }