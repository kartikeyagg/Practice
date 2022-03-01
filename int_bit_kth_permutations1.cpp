#include<bits/stdc++.h>
// #include<vector>
using namespace std;
vector<int> facto;
int findfacto(int n){
    if(n==0){ facto.push_back(1); return 1;}
    int f = n*(findfacto(n-1));
    facto.push_back(f);
    return (f);
}
void kthperm(int n, float k, vector<int> &vec,string &res){
    int it=0,t;float p;

    if(k==1){
        for (int i = 0; i < vec.size(); i++)
        {
            res.push_back(vec[i]+48);
        }
        
        return;
    }
    int l,m;

    while(n!=1){

    // k = floor(k);
    p = facto[n-1];
    cout<<"p is "<<p<<endl;
    int flag=0;
    // if(k%p ==0){
    //     // t-=1;
    //     k--;flag=1;

    // }
    t = ceil(k/p);
    t--;
    if (t==-1){
        t =vec.size()-1;
    }
    cout<<"t is "<<t<<endl;


    //bring  t+it index element to front move all other left
    // erase the t th index and add it into the map
    // mp[vec[t]] = t;
    res.push_back(vec[t]+48);
    vec.erase(vec.begin()+t);
    k = floor(k);
    l =k;
    m =p;
    k = l%m;
    // it++;
    n--;
    // vec.push_back();
    }
    for (int i = 0; i < vec.size(); i++)
    {
        res.push_back(vec[i]+48);
    }
    
}

int main(){

    int n=3,k=4;
    vector<int> vec;
    // vector<char> res;
    string res;
    int temp = 5+48;
    char c = temp;
    // cout<<c<<endl;
    int ft = findfacto(n);
    for (int i = 0; i < n; i++)
    {
        vec.push_back(i+1);
    }
    map<int,int> mp;
    kthperm(n,k,vec,res);
    cout<<endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    


    return 0;
}