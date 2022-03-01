#include<bits/stdc++.h>
using namespace std;
// depth first search for graph
// bfs :- 
// 1.) str
// 2.) go to neibours
// mark the visited node so not visit again

template<typename T>
class Graph{

    map<T,list<T>> l;
    public:
        void addEdge(int x, int y){
            l[x].push_back(y);
            l[y].push_back(x);

        }
        // void bfs(T src ){
        //     map<T,int> visited; // to check if the element is  already visited
        //     queue<T> q;

        //     q.push(src);
        //     visited[src] =1;//true

        //     while(!q.empty()){
        //         T node = q.front();
        //         q.pop();
        //         cout<<node<<" ";
        //         for(int nbr:l[node]){ // nbr  = neighbour

        //             if(visited[(nbr)]==0){
        //                 q.push(nbr);
        //                 visited[nbr] = 1;
        //             }

        //         }
        //     }
        // }
        void dfs_helper(T src,map<T,bool> &visited){
            // recursiv func to traverse the graph
            cout<<src<<" ";
            visited[src] = true;
            // go to all nbr of that node that is not visited
            for(T nbr:l[src]){
                if(visited[nbr]==0){
                    dfs_helper(nbr,visited);
                }
            }
        }
        void dfs(T src){  //  the aim of this function is to 
        // intialize a map with all value false
        // and then call dfs helper
            map<T,bool> visited;
            for(auto p:l){
                T node = p.first;
                visited[node] = false;
            }
            dfs_helper(src,visited); 
        }
};
int main() 
{  
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    // g.bfs(0);
    g.dfs(2); // ideally started from 0

    
    
    cout<<endl;
    return 0;
  }