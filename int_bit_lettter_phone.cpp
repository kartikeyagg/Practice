#include<bits/stdc++.h>
using namespace std;
vector<string> rans;
void phoneletter(vector<string> &pad,string res,int ind,vector<int> v){
    
    if(ind==-1){
        // cout<<res<<" ";
        rans.push_back(res);

        return;

    }
    int digit = v[ind];
    int len = pad[v[ind]].size();
    for (int i = 0; i < len; i++)
    {
        phoneletter(pad,pad[digit][i]+res,ind-1,v);
    }
    

    
}
int main() 
{   rans.clear();
    vector<string> pad = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    cout<<"enter the nums"<<endl;
    int a;
    cin>>a;
    vector<int> v;
    int t =a;
    int n = pad.size();
    while(a>0){
        v.push_back(a%10);
        a/=10;
    }
    string temps  ="";
    if(v.size()==1){
        for (int i = 0; i < pad[v[0]].size(); i++)
        {   temps ="";
            temps+=pad[v[0]][i]; 
            rans.push_back(temps);
        }
        return 0;//rans;
        
    }
    reverse(v.begin(),v.end());

    cout<<endl;
    string temp="";
    phoneletter(pad,temp,2,v);
    sort(rans.begin(),rans.end());
    cout<<endl;
    return 0;
  }