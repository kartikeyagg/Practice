#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int arr[][5],int x ,int y,int n){
    // cout<<"in safe"<<endl;

    if(x<n && y<n && arr[x][y] == 1 ){
        // cout<<"element "<<x<<","<<y<<" is safe"<<endl;
        return true;
    }

    return false;
}

bool ratinmaze(int arr[][5],int x, int y,int n, int **res){

    if(x == n-1 && y == n-1){
        res[x][y] =1;
        return true;
    }

    if(isSafe(arr,x,y,n)){
        
        res[x][y] =1;
        if(ratinmaze(arr,x+1,y,n,res)){

            return true;

        }
        if(ratinmaze(arr,x,y+1,n,res)){

            return true;

        }

        res[x][y] =0; //backtracking
        return false;
        
    }
return false;


}
  
int main() 
{
    int n=5;
    // cin>>n;

    // maze array (0 means the block is full and 1 means it is empty ans so is traversable)
    // int**arr = new int*[n];  // dynamicalyy alocating 2d array;
    // // notice 2 astresik;
    // for (int i = 0; i < n; i++)
    // {
    //     arr[i] = new int[n](); // allocating each row of abovve array;
    // }
    int arr[5][5]= {{1,0,1,0,1},{1,1,1,1,1},{0,1,0,1,0},{1,0,0,1,1},{1,1,1,0,1}};
    // int ** ptr  = arr;

    // path followed array
    int**res = new int*[n];  
    for (int i = 0; i < n; i++)
    {
        res[i] = new int[n](); 
    }

    int t =ratinmaze((arr),0,0,n,res);
    cout<<endl;

        for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<res[i][j]<<" ";
        }
    cout<<endl;

         
    }
    cout<<endl;
    
    cout<<endl;
    return 0;
  }