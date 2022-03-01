#include<bits/stdc++.h>
using namespace std;

vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> res;
        queue<int> q;
        int i,j;
        for( i=0;i<k;i++){
            q.push(arr[i]);
        }
        int mt = *max_element(arr,arr+k);
        res.push_back(mt);
        i = k;
        int prev_m = (mt);
        int temp,t2;
        while(i<n){
            temp = q.front();
            
            if(prev_m != temp && arr[i]<=prev_m){
                res.push_back(prev_m);
            }
            else if(arr[i]>=prev_m){
                res.push_back(arr[i]);
            }
            else{
                int maxt = -INT_MAX;
                for(j=i;j>i-k;j--){
                    if(maxt<arr[j]){
                        maxt = arr[j];
                    }
                }
                res.push_back(maxt);
                
            }
            q.pop();
            q.push(arr[i]);
            prev_m = res.back();
        i++;}
        
        return res;
    }

int main() 
{  
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int n=9,k=3;
    vector<int> res = max_of_subarrays(arr,n,k);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    

    
    
    cout<<endl;
    return 0;
  }