#include<bits/stdc++.h>
using namespace std;
string convert1(string res){
    if(res.size()==1){
        return "11";
    }
    int i=1;
    int j=1,jr =0;
    string r;
    while(i<res.size()){

        if(res[i] == res[i-1]){
            j++;
        }
        else{
            // jr = j;
            r+=(to_string(j)+res[i-1]);
            j=1;
        }
        i++;
    }
    r+=(to_string(j)+res[res.size()-1]);
    return r;
}  
int main() 
{  
    string res =  "11";
    res = convert1(res);

    cout<<res;
    
    cout<<endl;
    return 0;
  }