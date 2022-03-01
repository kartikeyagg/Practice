#include<bits/stdc++.h>
using namespace std;
  

int solve(vector<int> &A, int B, int C) {
    if(A.empty()){
        return 0;
    }
    if(A.size()==1 && B==1){

        if(A[0]<C){return 1;}

    }
    int res=0;
    vector<int> vec;
    int temp =C;
    while(temp>0){

        vec.push_back(temp%10);
        temp /=10;

    }
    reverse(vec.begin(),vec.end());
    int zcount=0;
    for(int i=0;i<A.size();i++){
        if(A[i]==0){zcount++;}
        if(A[i]>0){break;}
    }

    if (vec.size()<B){
        return 0;
    }
    if(vec.size()>B){
        res=1;
        for(int i=0;i<B;i++){

            if(i==0 && A[0]==0 && B!=1){
                res*=A.size()-zcount;
            }
            else{
                res*=A.size();
            }

        }
        
    return res;
    }
    int ln(0);//less numbers;
    int slot=1;
    vector<int> :: iterator iter;

    for(int i=0;i<vec.size();i++){
        iter = lower_bound(A.begin(),A.end(),vec[i]);
        ln = iter-A.begin();
        if(i==0 && A[0]==0 && B!=1){
            ln-=zcount;
        }
        slot =ln;
        for(int j=i+1;j<vec.size();j++){
            slot*=A.size();
        }
        cout<<"the value of slot "<<i<<" is "<<slot<<endl;
        if(slot==0){break;}
        res+=slot;



    }
    return res;
}
int main() 
{  
    vector<int> A = {0, 2, 3, 4, 5, 7, 8, 9 };
    int B,C;
    // : 5
    // C : 86587
    B=5;
    C = 86587;
    int res = solve(A,B,C);
    cout<<"answer is "<<res;
    cout<<endl;
    return 0;
  }
//  vector<int> A = {0,1,2,5},c;
//     if(A.size()==0){
//         return 0;
//     }
//     vector<int> c;
//     // int B = 2, C = 21,count =0,b,t=0,res=0,xc=0;
//     int count =0,b,t=0,res=0,xc=0;
//     while (C>0)
//     {
//         c.push_back(C%10);
//         C = C/10;
//     }
//     int nc= c.size();
//     // reverse(c.begin(),c.end());
//     b=B;int flag=0;
//     int is0 =0;
//     if(A[0]==0){
//         is0 =1;
//     }
//     int i,j,n=A.size();
//     while(b>-1){
//         if(b==B && B!=1){t=1;}
//         else{t=0;}
//         count =0;
//         for (int i = 0; i < n; i++)
//         {
//             if(A[i]>=c[nc-1]){
//                 count = i;
//                 flag =1;
//                 break;
//             }
//         }
//         if (flag ==0){
//             count = A.size();
//         }
//         if(is0 == 1 && (b==B && B!=1)){
//             count--;
//         }
//         xc = count;
//         for (int j = 0; j < b-1; j++)
//         {
//             xc*=(n-j);
            
//         }
//         res+=xc;
        
//         b--;
//         nc--;

//     }

// if(c.size()>B){res++;}
// return res;


// }
