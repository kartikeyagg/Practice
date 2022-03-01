#include<bits/stdc++.h>
using namespace std;

// this programme aims to find the island with smallest area
// and output the smallest area

void breadth_first(int x,int y,vector<vector<int>> &grid,vector<vector<int>> &mark,int &is_count)
{
    if(grid[x][y] ==0 || mark[x][y] ==1 ){
        return ;
    }
    int ni = grid.size(),nj = grid[0].size();
    mark[x][y] =1;
    is_count++;
    // breadth_first()
    if(x>0){
        breadth_first(x-1,y,grid,mark,is_count);
    }
    if(y>0){
        breadth_first(x,y-1,grid,mark,is_count);
    }
    if(x<ni-1){
        breadth_first(x+1,y,grid,mark,is_count);
    }
    if(y<nj -1){
        breadth_first(x,y+1,grid,mark,is_count);
    }



}

int island_count(vector<vector<int>> &grid,vector<vector<int>> &mark){
    int count =0;
    int is_count =0;
    int min_c =INT_MAX;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if(grid[i][j] == 1 && mark[i][j] ==0){
                is_count =0;
                breadth_first(i,j,grid,mark,is_count);
                min_c = min(is_count,min_c);
                count++;

            }
        }
        
    }
    return min_c;
        
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