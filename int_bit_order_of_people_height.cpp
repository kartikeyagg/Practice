#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector<int> order(vector<int> &A, vector<int> &B) {
    int i=0,j(0),n=A.size();
    map<int,int> mp;
    vector<int> res(n,-1);
    if(n<2){return A;}
    for(i=0;i<n;i++){
        mp[A[i]] = B[i];

    }
    map<int,int> :: iterator iter;
    int counto =0;i=0;
    for(iter = mp.begin();iter!=mp.end();iter++){
        cout<<"for element "<<(*iter).first<<endl;
        if(res[(*iter).second]==-1){
            res[(*iter).second] = (*iter).first;
            cout<<"inserting at index "<<(*iter).second<<endl;
        }
        else{counto=0;i=0;
            while(counto!=(*iter).second){
                if(res[i]==-1)
                    {counto++;}
                i++;                
            }
            while(res[i]!=-1){
                i++;
            }
            cout<<"inserting "<<(*iter).first<<" at index "<<i<<endl;
            res[i] = (*iter).first;
        }
    }
    



return res;
}
  
int main() 
{  vector<int> A,B,res;
    A = {86, 92, 49, 21, 62, 27, 90, 59};
    B = {2, 0, 0, 2, 0, 2, 1, 3};
    res = order(A,B);
    cout<<endl;

    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    
    
    
    cout<<endl;
    return 0;
  }