#include<bits/stdc++.h>
using namespace std;
// this programe aims to implement lower bound and 
// upper bound using binary search

// lower bound : - index of the element present & if not present then the index of element just greater than that
int lower_bound(vector<int> &v , int element){

    int low = 0, high = v.size()-1;
    int mid();
    while(high-low>1){
        int mid  = (high+low)/2;
        if(v[mid]<element){

            low = mid+1;


        }
        else {
            high = mid; // it is not mid+1 in this case; 
        }

    }

    if(v[low]>= element){return low;}
    if(v[high] >= element){return high;}
    
    return -1; // means no such element exist
    }

    // upper bound  = index of element just greater than given one
int upper_bound(vector<int> &v , int element){

    int low = 0, high = v.size()-1;
    int mid();
    while(high-low>1){
        int mid  = (high+low)/2;
        if(v[mid]<=element){ // change

            low = mid+1;


        }
        else {
            high = mid; // 
        }

    }

    if(v[low]> element){return low;} // change
    if(v[high] > element){return high;} // change
    
    return -1; // means no such element exist
    }
int main() 
{  
    vector<int> v ={ 2,3,4,5,6,7,8};
    cout<<"Enter the elment to be searched"<<endl;
    int t;
    cin>>t;
    int res,res1;
    res = lower_bound(v,t);
    if(res!=-1)
    cout<<"Lower bound for element "<<t<<" is "<<v[res];
    else{cout<<"Not found";}
    res1 = upper_bound(v,t);
    cout<<endl;
    if(res1!=-1)
    cout<<"Upper bound for element "<<t<<" is "<<v[res1];
    else{cout<<"Not found";}
    
    
    cout<<endl;
    return 0;
  }