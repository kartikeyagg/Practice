#include<bits/stdc++.h>
using namespace std;
// breadth firth search for graph
// bfs :- 
// 1.) str
// 2.) go to neighbours
//3. add them to queue
// pop the current elemeent and continue
// dont forget to keep check of visited elements
// mark the visited node so not visit again

template<typename T>
class Graph{

    map<T,list<T>> l;
    public:
        void addEdge(int x, int y){
            l[x].push_back(y);
            l[y].push_back(x);

        }
        void bfs(T src ){
            map<T,int> visited;
            queue<T> q;

            q.push(src);
            visited[src] =1;//true

            while(!q.empty()){
                T node = q.front();
                q.pop();
                cout<<node<<" ";
                for(int nbr:l[node]){ // nbr  = neighbour

                    if(visited[(nbr)]==0){
                        q.push(nbr);
                        visited[nbr] = 1;
                    }

                }
            }
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
    g.bfs(0);

    
    
    cout<<endl;
    return 0;
  }