#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int mice(vector<int> &A, vector<int> &B) {

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int res =0,t=0,y=0;
    int n = A.size();
    vector<int>::iterator low1, low2, low3;
    for(int i=0;i<n;i++){

        // res+=abs(A[i]-B[i]);
        low1 = lower_bound(B.begin(),B.end(),A[i]);
        t= B[low1-B.begin()];
        cout<<"t is "<<t<<endl;
        if(low1-B.begin()>0){
            y =A[low1-B.begin()-1];
        }
        else{
            y = INT32_MAX;
        }
        cout<<"y is "<<y<<endl;

        if(abs(t-A[i])<abs(y-A[i])){
            res+=abs(t-A[i]);
            cout<<"erasing "<<B[low1-B.begin()]<<endl;

            B.erase(low1);
            // cout<<"first element is "<<B[0]<<endl;

        }
        else{
            res+=abs(y-A[i]);
            cout<<"erasing "<<B[low1-B.begin()-1]<<endl;

            B.erase(low1-1);

        }


    }
    return res;
}


  
int main() 
{  vector<int> vec1 = {4, -4, 2};
   vector<int> vec2 = {4, 0, 5 };
    int t = mice(vec1,vec2);
    cout<<"res is "<<t;
    
    cout<<endl;
    return 0;
  }