#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<pair<int,int>,pair<int,int>> a,pair<pair<int,int>,pair<int,int>> b){

    return (a.first).first+(a.second).first < (b.first).first+(b.second).first; 

}

int merge_element(vector<int> &A){
    int n=A.size();
    int res=0;
    if(n==1|| n==0){return 0;}
    vector<pair<pair<int,int>,pair<int,int>>> v;
    for (int i = 0; i < n-1; i++)
    {
        v.push_back(make_pair(make_pair(A[i],i),make_pair(A[i+1],i+1)));

    }
    while(A.size()!=1){

        sort(v.begin(),v.end(),cmp);
        res+=((v[0].first).first +(v[0].second).first );

    }
    



}


int main() 
{  
    vector<int> A  = {1, 2, 3, 4};

    
    cout<<endl;
    return 0;
  }