#include<bits/stdc++.h>
using namespace std;

// this function aims to implement depth first search
void depthfirst(map<char,vector<char>> &gp,char sr){

    unordered_set<char> sc; // to not repeat the already found elements
    stack<char> st;
    char p;
    st.push(sr);
    auto iter = gp.begin();

    while(!st.empty()){
        p = st.top();
        st.pop();
        sc.insert(p);
        cout<<"The element is "<<p<<endl;
        for( auto x : gp[p]){
            if(sc.count(x)==0)
                st.push(x);
        }
    }
}
// this function also aims for implementing DFS but wiht recursion
// unordered_set<char> gset;
// unordered_set<char> g1set;
// vector<int> gset(6);
// vector<int> g1set(6);

map<int,int> gset;
map<int,int> g1set;

int rec_depthfirst(map<char,vector<char>> &gp,char sr)
{
    cout<<"the element is "<<sr<<endl;
    gset[sr] =1;
    g1set[sr] =1;
    int temp = 0;

    for(auto x:gp[sr]){
        if(gset.count(x)==0 || gset[sr]==0){
            
            temp =rec_depthfirst(gp,x);
            if(temp==1){
                return 1;
            }}
        else if (g1set[x] ==1){
            cout<<"found the cycle at "<<x<<" from "<<sr<<endl;
            return 1 ;
        }
    }
    g1set[sr] = 0; //

    return 0;

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
        cout<<"the element is "<<ct<<endl;
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
    map<char,vector<char>> gp{
        {'a',{'c','b'}},
        {'b',{'d'}},
        {'c',{'b','e'}},
        {'d',{'f'}},
        {'e',{}},
        {'f',{'b'}},
    };
    
    // depthfirst(gp,'a');
    // cout<<"\n";
    // cout<<"calling recursively "<<endl;
    // cout<<endl;
    // rec_depthfirst(gp,'a');
    // cout<<"doing bredth first search now "<<endl;
    int res  = rec_depthfirst(gp,'a');
    cout<<"the answer is "<<res<<endl;
    cout<<endl;
    return 0;
  }