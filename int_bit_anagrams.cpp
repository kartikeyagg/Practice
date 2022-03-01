#include<bits/stdc++.h>
using namespace std;
  
int main() 
{   
    map<string,vector<int>> mp;
    mp.clear();
    vector<string> a = { "cat", "dog", "god","tca"};
    vector<vector<int>> res;
    string t;
    int j=1;
    for(auto i: a){
        t = i;
        
        sort(t.begin(),t.end());
        if(mp.count(t) == 0){

            mp[t] = {j};

        }
        else{
            mp[t].push_back(j);
        }
        j++;
    }
    vector<int> tempv;
    for(auto k: mp){
        tempv.clear();
        for(auto r:k.second){
            // cout<<r<<" ";
            tempv.push_back(r);
        }
        // cout<<endl;
        res.push_back(tempv);
    }
    for (int i = 0; i < res.size(); i++)
    {
        for (int k = 0; k < res[i].size(); k++)
        {
            cout<<res[i][k]<<" ";
        }
        cout<<endl;
    }
    
    
    cout<<endl;
    return 0;
  }