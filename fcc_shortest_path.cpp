#include<bits/stdc++.h>
using namespace std;

// this program aims to find the shortest path btw 2 nodes present in graph
//  BFS is viable

map<char,vector<char>> create_map(vector<vector<char>> ad){
    map<char,vector<char>> res;
    for(auto x:ad){
        if(res.count(x[0]) ==0 ){
            res[x[0]] = {x[1]};

        }
        else{
            res[x[0]].push_back(x[1]);
        }

        if(res.count(x[1]) == 0){
            res[x[1]] = {x[0]};

        }
        else{
            res[x[1]].push_back(x[0]);

        }
    }

    return  res;

}
void bredth_first(map<char,vector<char>> &gp,char sr,char dst){
    char ct;
    unordered_set<char> us;
    queue<char> qt;
    qt.push(sr);
    us.insert(sr);

    
    while(!qt.empty()){
        ct = qt.front();
        
        qt.pop();
        cout<<"the element is "<<ct<<endl;
        if(ct == dst){
            cout<<"found the path "<<endl;
            return ;
        }
        for(auto x:gp[ct]){
            if(us.count(x)==0)
                qt.push(x);
                us.insert(x);

        }
    }
    cout<<"No path exist"<<endl;

}

int main() 
{  
    vector<vector<char>> adj = {{'i','j'},
    {'w','x'},
    {'y','x'},
    {'z','y'},
    {'z','v'},
    {'w','v'}

    };


map<char,vector<char>> gp = create_map(adj);
// {
        // {'a',{'c','b'}},
        // {'b',{'d'}}, 
        // {'c',{'e'}},
        // {'d',{'f'}},
        // {'e',{}},
        // {'f',{}},
    // };
    // printing the graph builded

    // map<char,vector<char>>::iterator iter;
    // cout<<"printin the graph "<<endl;
    // for(iter  = gp.begin();iter!= gp.end();iter++){
    //     cout<<"{ "<<(*iter).first<<" , [ ";
    //     for(auto p:(*iter).second){
    //         cout<<p<<", ";
    //     }
    //     cout<<"] }"<<endl;
    // }
    // graph printed

    // n--o is a different graph which is not connected

    
    bredth_first(gp,'k','l');
    cout<<endl;
    return 0;
  }