#include<bits/stdc++.h>
using namespace std;


// Utilized tabulation here
int lis(const vector<int> &A) {
    int i,j,n = A.size(),temp;
    // vector<pair<int,int>> vec;
    vector<int> empt ={};
    vector<vector<int>> res(n+1,empt); // resultant vector for tabulation all intialized with empty vectors
    // for(i=0;i<n;i++){
    //     vec.push_back(make_pair(A[i],i));
    // }
    // vector<pair<int,int>> veb;

    // res[0] = {0};
    for(i =0;i<n;i++){
        for(j =i+1;j<n;j++){
            if(A[j]>A[i]){
                if(res[j].size()<=res[i].size()){
                    res[j] = res[i];
                    res[j].push_back(A[i]);
                }
            }
        }
    }
    int maxsize1=0 ;
    for(auto t:res){
        if(t.size()>maxsize1){
            maxsize1 = t.size();
        }
    }

    return maxsize1+1;




}

int main() 
{  int n =5;
    // vector<int> empt = {};
    // vector<vector<int>> res(n+1,empt);
    vector<int> v = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int t  = lis(v);
    cout<<"result is "<<t<<endl;
    
    cout<<endl;
    return 0;
  }