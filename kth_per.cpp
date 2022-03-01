#include<bits/stdc++.h>
// #include<vector>
using namespace std;
vector<int> facto;
int findfacto(int n){
    if(n==0){ facto.push_back(1); return 1;}
    int tf = findfacto(n-1);
    if(tf==INT_MAX || tf>=INT_MAX/n){
            facto.push_back(INT_MAX);
            return (INT_MAX);
    }
    int f = n*(tf);
    facto.push_back(f);
    return (f);
}
void kthperm(int n, float k, vector<int> &vec,string &res){
    int it=0,t;float p;

    if(k==1){
        for (int i = 0; i < vec.size(); i++)
        {
            // res.push_back(vec[i]+48);
            res+=(to_string(vec[i]));
        }
        
        return;
    }
    int l,m;

    while(n!=1){

    // k = floor(k);
    if(n<13)
    {p = facto[n-1];}
    else{
        p = INT_MAX;
    }
    // cout<<"p is "<<p<<endl;
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
    // cout<<"size is "<<vec.size()<<endl;
    // cout<<"t is "<<t<<endl;


    //bring  t+it index element to front move all other left
    // erase the t th index and add it into the map
    // mp[vec[t]] = t;
    // res.push_back(vec[t]+48);
    res+=(to_string(vec[t]));
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
        // res.push_back(vec[i]+48);
        res+=(to_string(vec[i]));

    }
    
}
int main(){
    facto.clear();
    int n=100;float k=10000000;
// A:    100
// B : 10000000
    vector<int> vec;
    // vector<char> res;
    string res;
    // int temp = 5+48;
    // char c = temp;
    // cout<<c<<endl;
    if(n<=12)
    {int ft = findfacto(n);}
    else{
        int ft = findfacto(12);
    }
    for (int i = 0; i < n; i++)
    {
        vec.push_back(i+1);
    }
    // map<int,int> mp;
    kthperm(n,k,vec,res);
    cout<<res<<endl;
        
    return 0;
}