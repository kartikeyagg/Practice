#include<bits/stdc++.h>
using namespace std;

// this function aims to implement depth first search
stack<int> stc;
unordered_set<int> sc; // to not repeat the already found elements
void depthfirst(map<int,vector<int>> &gp,int sr){

    
    stack<int> st;
    // stack<char> st;
    char p;
    map<int,vector<int>> ::iterator iter = gp.begin();

    for(iter = gp.begin();iter!=gp.end();iter++){

        if(sc.count(iter->first) ==0){
            sr = iter->first;
            st.push(sr);
            while(!st.empty()){
                p = st.top();
                st.pop();
                sc.insert(p);
                cout<<"The element is "<<p<<endl;
                for( auto x : gp[p]){
           
                    if(sc.count(x)==0)
                        st.push(x);
                }

        
                stc.push(p);
                }
        }

    }
}
// this function also aims for implementing DFS but wiht recursion
unordered_set<char> gset;

void rec_depthfirst(map<char,vector<char>> &gp,char sr)
{
    cout<<"the element is "<<sr<<endl;
    gset.insert(sr);

    for(auto x:gp[sr]){
        if(gset.count(x)==0)
            rec_depthfirst(gp,x);
    }

}
// this fun aims to implement bfs
// notice how dfs used stack and in this approch
// (bfs) we are using queues instead
void bredth_first(map<char,vector<char>> &gp,char sr){
    char ct;
    unordered_set<char> us;
    queue<char> qt;
    qt.push(sr);
    us.insert(sr);

    while(!qt.empty()){
        ct = qt.front();
        qt.pop();
        // cout<<"the element is "<<ct<<endl;
        for(auto x:gp[ct]){
            if(us.count(x)==0)
                qt.push(x);
                us.insert(x);

        }
    }

}

int main() 
{  
    // creating a Graph using (LL)
    size_t n, m;
    map<int,vector<int>> gp;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 1; i <= n; i++)
  {
      gp[i] = {};
  }
  
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    gp[x].push_back(y);
  }
    // map<char,vector<char>> gp{
    //     {'a',{'c','b'}},
    //     {'b',{'d'}},
    //     {'c',{'e','b'}},
    //     {'d',{'f'}},
    //     {'e',{}},
    //     {'f',{}},
    // };
    
    for (auto x:gp){

        if(sc.count(x.first)==0)
        depthfirst(gp,x.first);

    }
    vector<int> vec;
    while(!stc.empty()){
        vec.push_back(stc.top());
        // cout<<stc.top();
        stc.pop();
    }

    // reverse(vec.begin(),vec.end());
    // cout<<"\n";
    // cout<<"calling recursively "<<endl;
    // cout<<endl;
    // rec_depthfirst(gp,'a');
    // cout<<"doing bredth first search now "<<endl;
    // bredth_first(gp,'a');
    cout<<endl;
    for(auto x:vec){
        cout<<x<<" ";
    }
    // cout<<endl;
    return 0;
  }