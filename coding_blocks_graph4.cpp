#include<bits/stdc++.h>
using namespace std;
// graph using using hash map
class Graph{

    public:
    unordered_map<string,list<pair<string,int>>> l;

    void addEdge(string x,string y,bool bidir,int wt){
        l[x].push_back(make_pair(y,wt)); // make pair makes the pair
        if(bidir){
            l[y].push_back(make_pair(x,wt));
        }
    }

    void gtravel(){
        for(pair<string,list<pair<string,int>>> city:l){
            cout<<"for node "<<city.first<<endl;
            for(pair<string,int> p:city.second){

                cout<<p.first<<" "<<p.second<<"; ";

            }
            cout<<endl;

        }
        
    }



};

int main() 
{  // parent edge , child edge , bidirectional or not,distance

    Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",false,15);
    g.addEdge("A","C",true,40);
    g.addEdge("C","D",false,30);
    g.addEdge("A","D",false,10);
    g.gtravel();
    
    
    
    cout<<endl;
    return 0;
  }