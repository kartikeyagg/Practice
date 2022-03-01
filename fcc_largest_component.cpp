#include<bits/stdc++.h>
using namespace std;
  // this programme aims to find the largest component means
  // a graph with highest number of nodes

unordered_set<int> st; // contains the visited nodes
int ans =0;

void breadth_first(map<int,vector<int>> &gp, int src){

    int count_nodes =0;
    queue<int> qt;
    qt.push(src);
    st.insert(src);

    int t ;
    while(!qt.empty()){
        t = qt.front();
        qt.pop();
        cout<<"the element is "<<t<<endl;
        count_nodes++;
        // st.insert(t);
        for(auto x:gp[t]){
            if(st.count(x)==0)
                {qt.push(x);
                st.insert(x);
                }
        }
    }
    if(count_nodes>ans){
        ans =  count_nodes;
    }
}

int count_connected(map<int,vector<int>> &gp){
    map<int,vector<int>>::iterator iter;
    int res =0;
    for(iter = gp.begin();iter!=gp.end();iter++){
        if(st.count((*iter).first) ==0){
            res++;
            breadth_first(gp,(*iter).first);
        }
    }
return res;
}

int main() 
{  
    map<int,vector<int>> gp = { { 0 ,{8,1,5}},
    {1,{0}},
    {5,{0,8}},
    {8,{0,5}},
    {2,{3,4}},
    {3,{2,4}},
    {4,{3,2}},
    };
    // cout<<endl;
    // breadth_first(gp,1);
    int res  = count_connected(gp);
    cout<<"the answer is "<<res<<endl;
    cout<<"the max connected components are "<<ans<<endl;
    return 0;
  }