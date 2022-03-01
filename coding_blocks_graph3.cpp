#include<bits/stdc++.h>
using namespace std;
// graph representaion via adjacency list in cpp
// struct node
// {
//     int val;
//     struct node* next;
// };
class Graph{
    int V;
    // struct node* l;
    list<int> *l; //  a list pointer 

public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V]; //  an array of list 
        
    }
    void addedge(int x , int y){

        l[x].push_back(y);
        l[y].push_back(x);}


    void printadjlist(){
        for(int i=0;i<V;i++){
            for(int nbr:l[i]){

                cout<<nbr<<" ";

            }
        cout<<endl;

        }
    }


    
};

int main() 
{  Graph g(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(2,3);
    g.addedge(1,2);
    // g.addedge(0,1);
    g.printadjlist();
    
    
    cout<<endl;
    return 0;
  }