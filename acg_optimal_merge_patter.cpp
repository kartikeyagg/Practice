// Problem: You are given n files with their computation
// times in an array.
// Operation: Choose/take any two files, add their computation
// times and append it to the list of computation
// times. {Cost =Sum of computation time}
// Do this until we are left with only one file in the
// array. We have to do this operation such that
// we get minimum cost finally.

#include <queue>
#include <iostream>

using namespace std;


struct comparator
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};


int main()
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // minHeap.push(12);
    // minHeap.push(8);
    minHeap.push(7);
    minHeap.push(2);
    minHeap.push(4);
    minHeap.push(5);
    int temp =0,res =0;
    while(minHeap.size()>1){
        temp =  minHeap.top();
        minHeap.pop();
        temp+=minHeap.top();
        minHeap.pop();
        
        res+= temp; 
        minHeap.push(temp);

    }
    cout<<endl;
    cout<<"the size is "<<minHeap.size()<<endl;
    cout<<"the answer is "<<res<<endl;
    cout<<endl;

    return 0;

}