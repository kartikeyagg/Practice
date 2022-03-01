#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &a,int n,int i){

    int maxidx  = i;

}

void heapsort(vector<int> &a){

    int n = a.size();

    for(int i = n/2-1; i>=0;i--){

        heapify(a,n,i);
    }

    for(int i =n-1;i>0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }

}
  
int main() 
{  
    int n;
    cin>>n;
    vector<int> a = {10,15,21,30,18,19};
    heapsort(a);        
    
    cout<<endl;
    return 0;
  }