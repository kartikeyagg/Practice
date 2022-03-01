#include<bits/stdc++.h>
using namespace std;
//  A wood cutter needs timber in forest
// he set a height in his machine all the portion 
// of trees greater than height is cut and 
// collected as timber;
// given M : - the amount of wood needed;
// find the maximun height which can be set to get the required wood;

// this programee uses 'predicate' function
// a predicate func is a func which returns bool

// a monotonic predicate function is function which return same value before and after a point
//  eg :- ffftttt // from index 3 all are t before it all are false
// eg : - ttttffff // such index is 4; 
const int N=1e6+10;
int n;
long long m;
long long trees[N] ={20,15,10,17};

bool iswoodsufficien(int h){ ///  return something like this ttttfffffff
     long long wood(0);
     for(int i =0;i<n;i++){
         if((trees[i]-h)>=0)
         wood+= (trees[i]-h);
     }
     return wood>=m;

}

int main() 
{   
    n =4;
    m = 7;
    long long lo =0, hi = 1e9,mid;
    while(hi-lo>1){
        mid = (hi+lo)/2;
        if(iswoodsufficien(mid)){
            lo = mid;   }
        else{
            hi = mid-1;
        }
    }
    if(iswoodsufficien(hi)){
        cout<<hi<<endl;
    }
    else if(iswoodsufficien(lo)){
        cout<<lo<<endl;     }
    else{
        cout<<"not found"<<endl;
    }
    cout<<endl;
    return 0;
  }