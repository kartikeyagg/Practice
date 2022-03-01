#include<bits/stdc++.h>
using namespace std;
 // this function returns the number of painter required to complete the job in 
 // given time limit
int findfeasable(vector<int> boards,int n,int limit){
    int sum =0,painters =1;
    for (int i = 0; i < n; i++)
    {
        sum+= boards[i];
        if(sum > limit){
            sum = boards[i];
            painters++;

        }
    }
    return painters;
    
}
int painterspartition(vector<int> boards,int n,int m){ // m : = number of painter

    int totallenght =0,k=0; // k is for largest board size, n:= size of the array baords
    // max time is when one paiter do it  
    // which is equal to total unit area(sum of all elements)
    // min time required is the area of the largest paiting
    // as one painter can paint the painting at the time
    for (int i = 0; i < n; i++)
    {
        k = max(k,boards[i]);
        totallenght += boards[i];
    }

    int low = k, high  = totallenght;
    int painters;
    while(low<high){
        int mid = (low+high)/2;
        painters = findfeasable(boards,n,mid); // mid is the limit(time)
        if(painters<=m){
            high = mid;
        }else{
            low = mid+1;
        }

    }
    return low;

}
 
int main() 
{  
    vector<int> arr = { 10,20,30,40};
    int n = 4;
    int m = 2;
    int t  = painterspartition(arr,n,m);
    cout<<"result is "<<t<<endl;
    cout<<endl;
    return 0;

  }