#include<bits/stdc++.h>
using namespace std;

int check_palindrome(string &a){
    int n = a.size();
    for(int i =0;i<(n/2);i++){
        if(a[i]!=a[n-1-i]){
            return 0;
        }
    }
    return 1;
}

int mincut(string &s){
    int i(0),j(0),res=0;
    int n = s.size();

}

int main() 
{  
    
    string a  = "aab";


    
    cout<<endl;
    return 0;
  }

  