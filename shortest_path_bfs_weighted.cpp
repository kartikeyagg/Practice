#include<bits/stdc++.h>
using namespace std;

int bfs(map<int,vector<pair<int,int>>> &mp,int u,int v,vector<int> &vi){

    queue<int> qi;

    vi[u] = 0;
    auto temp = u;
    qi.push(u);
    while(!qi.empty()){

        temp = qi.front();

        for(auto x:mp[temp]){
            if(vi[temp]+x.second < vi[x.first]){

                vi[x.first] = vi[temp]+x.second;
                qi.push(x.first);

            }
        }
        qi.pop();


    }
    if(vi[v]==INT_MAX){
        vi[v] = -1;
    }
    return vi[v];

    

}


int main() 
{  
    map<int,vector<pair<int,int>>> mp = {
        {1,{{2,1},{3,5}}},
        {2,{{3,2}}},
        {3,{}},
        {4,{{1,2}}}
    };

    // cout<<(mp.size())<<endl;
    vector<int> vi(mp.size()+1,INT_MAX);

    int res = bfs(mp,1,3,vi);



    cout<<"result is "<<res<<endl;

    
    
    cout<<endl;
    return 0;
  }