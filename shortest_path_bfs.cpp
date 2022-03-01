#include<bits/stdc++.h>
using namespace std;

int bfs(map<int,vector<int>> &mp,int u,int v,vector<int> &vi){

    queue<int> qi;

    vi[u] = 0;
    auto temp = u;
    qi.push(u);
    while(!qi.empty()){

        temp = qi.front();

        for(auto x:mp[temp]){
            if(vi[temp]+1 < vi[x]){

                vi[x] = vi[temp]+1;
                qi.push(x);

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
    map<int,vector<int>> mp = {
        {1,{2,3}},
        {2,{3,1}},
        {3,{1,2}},
        {4,{}}
    };

    cout<<(mp.size())<<endl;
    vector<int> vi(mp.size()+1,INT_MAX);

    int res = bfs(mp,2,4,vi);



    cout<<"result is "<<res<<endl;

    
    
    cout<<endl;
    return 0;
  }