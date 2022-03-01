#include<bits/stdc++.h>
using namespace std;
set<int> se;
void fibfun(int A, vector<int> &ar){

    int t = ar[ar.size()-1]+ar[ar.size()-2];
    if(t<=A)
    {ar.push_back(t);
    se.insert(t);
    fibfun(A,ar);}
    else{
        return;
    }

}

int fibsum(int A) {
    se.clear();
    se.insert(1);
    if(A==0){
        return 0;
    }
    if(A==1){
        return 1;
    }
    vector<int> ar = {1,1};
    fibfun(A,ar);
    ar.erase(ar.begin());
    // cout<<"Printing ar\n";
    // for (int i = 0; i < ar.size(); i++)
    // {
    //     cout<<ar[i]<<" ";
    // }
    // cout<<endl;
    if(se.count(A)>0){
        return 1;
    }
    vector<int> res(A+1,INT_MAX);
    res[0] =1;
    res[1] =1;
    int t=0;
    for(int i =0;i<ar.size();i++){

        res[ar[i]] = 1;

    }
    for(int i =0;i<=A;i++){
        // cout<<"for i = "<<i<<endl;
        if(res[i]!=INT_MAX){

        for(int j =0;j<ar.size();j++){
       
            if(i+ar[j]<=A){
            // if(res[i+ar[j]]==1){
            //     continue;
            // }
            res[i+ar[j]] = min(res[i+ar[j]],res[i]+1);
            // cout<<"updated res["<<i+ar[j]<<"] to "<<res[i+ar[j]]<<endl;
            }



        }
        }
    }
    // for (int i = 0; i < A+1; i++)
    // {
    //     cout<<res[i]<<" ";
    // }
    // cout<<endl;
    
if(res[A] == INT_MAX){
    return A;
}
return res[A];
}

int main() 
{  int a  =804289383;
    int t = fibsum(a);
    
    
    cout<<endl;
    return 0;
  }