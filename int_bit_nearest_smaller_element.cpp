#include <iostream>
#include <vector>
#include <utility>
#include <stack>
using namespace std;

vector<int> prevSmaller(vector<int> &A) {
    cout<<"in the fun \n";

    int n = A.size(),i,j;
    i=0;
    vector<int> res;
    stack<pair<int,int>> st;
    stack<pair<int,int>> temp;
    pair<int,int> p;
    cout<<"123' \n";


    while(i<n){
        cout<<"ern\n";

        cout<<"for index "<<i<<" and element "<<A[i]<<endl;

        if(st.empty()){
            p = {A[i],i};
            st.push(p);
            res.push_back(-1);
        }

        else{

            temp =st;
            while(!temp.empty()){
                if(temp.top().first < A[i]){
                    res.push_back(temp.top().first);
                }
                else{
                    temp.pop();
                }
            }
            if(temp.empty()){
                res.push_back(-1);
            }
          
        

        while((!st.empty()) && A[i]<=st.top().first){

            cout<<"the top element is "<<st.top().first<<"\n";
            st.pop();

        }

        p = {A[i],i};

        st.push(p);}



    i++;
    }







return res;

}

  
int main() 
{  vector<int> a  = {34, 35, 27, 42, 5, 28, 39, 20, 28};

    vector<int> c = prevSmaller(a);

    cout<<"ans is "<<endl;

    for (int i = 0; i < c.size(); i++)
    {
        cout<<c[i]<<" ";
    }
    
    
    
    cout<<endl;
    return 0;
  }