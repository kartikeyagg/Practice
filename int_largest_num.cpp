#include<bits/stdc++.h>
using namespace std;
// bool comp(int a ,int b){
//     int counta =0,countb =0;
//     int x =a,y=b;
//     while(x>0){
//         counta++;
//         x = x/10;
//     }
//     while(y>0){
//         countb++;
//         y = y/10;
//     }
//     if(counta>countb){
//         int temp = counta-countb;
//         for(int i=0;i<temp;i++){
//             b *=10;
//         }
//     }
//     else{
//         int temp = countb-counta;
//         for(int i=0;i<temp;i++){
//             a*=10;
//         }
//     }
//     return a>b;
// }
bool comp(int a ,int b){
    int counta =0,countb =0;
    int x =a,y=b;
    while(x>0){
        counta++;
        x = x/10;
    }
    while(y>0){
        countb++;
        y = y/10;
    }
    x = a;
    y =b;
    long long t1=x,t2=y;
    for(int i=0;i<countb;i++){
        t1 =t1*10;
    }
    t1+=b;
    for(int i=0;i<counta;i++){
        t2 = t2*10;
    }
    t2+=a;
    return t1>t2;
}
string largestNumber( vector<int> &B) {  
    vector<int> A = B;
    int n = A.size()      ;
    string res ="";
    sort(A.begin(),A.end(),comp);
    for (int i = 0; i < n; i++)
    {
        // cout<<A[i]<<" ";
        res+=to_string(A[i]);
    }
    // cout<<endl;
    return res;
    
}
int main() 
{  
    vector<int> B = {3,30,34,5,9};

    string res =largestNumber(B);
    cout<<res;
    cout<<endl;
    return 0;
  }