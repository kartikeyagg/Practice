#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int trap(const vector<int> &A) {
    int n = A.size(),i(0),j,res =0,maxind= 0;
    if(n<3){
        return 0;
    }
    
    int maxt = -INT32_MAX;
    int mint = INT32_MAX;

    for(i=0;i<n;i++){

        if(A[i]>=maxt){

            maxt = A[i];
            maxind = i;


        }
        if(A[i]<mint && A[i]>0){
            mint  = A[i];
        }
        

    }
    cout<<"maxind is "<<maxind<<endl;
    // if(mint == maxt){return 0;}
    cout<<"1 loop \n";

    stack<int> st;
    i =0;
    while(i<maxind){
        cout<<"for element "<<A[i]<<endl;
        cout<<"of index: "<<i<<endl;

        if((st.empty()) && A[i]>0){
            cout<<" in first condition"<<endl;
            st.push(A[i]);
        }

        else if(A[i]>0 && A[i]>st.top()){
            cout<<" in 2nd condition"<<endl;


            st.push(A[i]);

        }

        else{
            cout<<" in 3rd condition"<<endl;

            if(!st.empty()){
            res += (st.top()) - A[i];}
            cout<<"2323 \n";

        }

        i++;
    }
    cout<<"2 loop \n";

    i= n-1;
    stack<int> st1;
    while(i>maxind){

        cout<<"for element "<<A[i]<<endl;
        cout<<"of index: "<<i<<endl;

        if(st1.empty() && A[i]>0){
            cout<<" in first condition"<<endl;

            st1.push(A[i]);
        }

        else if(A[i]>0 && A[i]>st1.top()){
            cout<<" in 2nd condition"<<endl;


            st1.push(A[i]);

        }

        else{ 
            cout<<" in 3rd condition"<<endl;

            if(!st1.empty())
            {res+= st1.top() - A[i];}

        }

        


        i--;


    }
    cout<<"3 loop \n";




return res;

}

int main() 
{  const vector<int> a= {0 ,1 ,0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int t = trap(a);

    cout<<"the result is "<<t<<endl;
    
    
    cout<<endl;
    return 0;
  }