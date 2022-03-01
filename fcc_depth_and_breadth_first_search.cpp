// #include<bits/stdc++.h>
// using namespace std;

// this function aims to implement depth first search
void depthfirst(map<char,vector<char>> &gp,char sr){

    unordered_set<char> sc; // to not repeat the already found elements
    stack<char> st;
    char p;
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
        {'c',{'e'}},
        {'d',{'f'}},
        {'e',{}},
        {'f',{}},
    };
    
    // depthfirst(gp,'a');
    // cout<<"\n";
    // cout<<"calling recursively "<<endl;
    // cout<<endl;
    // rec_depthfirst(gp,'a');
    cout<<"doing bredth first search now "<<endl;
    bredth_first(gp,'a');
    cout<<endl;
    return 0;
  }