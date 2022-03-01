#include<bits/stdc++.h>
using namespace std;
    string reverseWords(string S) 
    { 
        // code here 
        string res,temp;
        S+='.';
        int i =0, n = S.size();
        while(i<n){
            if(S[i] == '.'){
                res="."+temp+res;
                temp = "";
            }
            else{
                temp+=S[i];
            }
            i++;
        }
        cout<<"function completed"<<endl;
        
        string tk = res.substr(1);
     return (tk);   
    } 
int main() 
{  
    string st = "Hello.world";
    cout<<st.substr(1);
    cout<<endl;
    string tk = reverseWords(st);
    cout<<tk<<endl;
    cout<<"endl \n";
    
    cout<<endl;
    return 0;
  }