#include<bits/stdc++.h>
using namespace std; // similar to EKO but more advance

const int N = 1e5+10;
int n=5,cows;
int position[N] = {1,2,8,4,9};

bool canplacecows(int dist){
    int last_pos =0;
    int cows_ct  = cows;
    // cout<<"   cows_ct is "<<cows_ct<<endl;
    for (int i = 0; i < n; i++)
    {   
        if(position[i]-last_pos>=dist || last_pos ==0){ 

            cows_ct--;
            last_pos = position[i];


        }
        if(cows_ct ==0){break;}
        
    }
    return cows_ct <=0 ;
}

int main() 
{   
    cout<<endl;
    int nc = 3; // number of cows;
    cows = nc;
    sort(position,position+n);
    int high = 10e8,low=0,mid;
    while(high-low>1){
    
    mid = (low+high)/2;
    if(canplacecows(mid)){
        low = mid;
    }
    else{
        high = mid-1;
    }


    }
    if(canplacecows(high)){
        cout<<"ans is "<<high<<endl;
    }
    else if(canplacecows(low)){
        cout<<"ans is "<<low<<endl;

    }
    else{
        cout<<"Not found"<<endl;

    }
    
    cout<<endl;
    return 0;
  }