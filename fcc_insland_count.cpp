#include<bits/stdc++.h>
using namespace std;

// this programme aims to find the the number of island 
// in a given grid;

void breadth_first(int x,int y,vector<vector<int>> &grid,vector<vector<int>> &mark)
{
    if(grid[x][y] ==0 || mark[x][y] ==1 ){
        return ;
    }
    int ni = grid.size(),nj = grid[0].size();
    mark[x][y] =1;
    // breadth_first()
    if(x>0){
        breadth_first(x-1,y,grid,mark);
    }
    if(y>0){
        breadth_first(x,y-1,grid,mark);
    }
    if(x<ni-1){
        breadth_first(x+1,y,grid,mark);
    }
    if(y<nj -1){
        breadth_first(x,y+1,grid,mark);
    }



}

int island_count(vector<vector<int>> &grid,vector<vector<int>> &mark){
    int count =0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if(grid[i][j] == 1 && mark[i][j] ==0){

                breadth_first(i,j,grid,mark);
                count++;

            }
        }
        
    }
    return count;
        
}

int main() 
{  
    vector<vector<int>> mark1(6,vector<int> (5,0));
    vector<vector<int>> grid = {{0,1,0,0,0},
    {0,1,0,0,0},
    {0,0,0,1,0},
    {0,0,1,1,0},
    {1,0,0,1,1},
    {1,1,0,0,0}
    };
    int count = island_count(grid,mark1);
    cout<<"the answer is "<<count<<endl;


    cout<<endl;
    return 0;
  }