#include<bits/stdc++.h>
using namespace std;
// A program that accepts a target string and an array
// of strings , each containg a way of formig target
// using tabulation
vector<vector<vector<string>>>a ;
int canconstruct(string target, vector<string> &wordbank){

    int n = target.size();
   vector<vector<vector<string>>>a(n+1) ;
    a[0][0] = "-1";
    for (int i = 0; i < a.size(); i++)
    {
        if(!a[i][0].empty()){
            for (int j = 0; j < wordbank.size(); j++)
            {
                if((target.substr(i)).find(wordbank[j])==0){

                    for (int k = 0; k < a[i].size(); k++)
                    {
                        a[wordbank[j].size()+i].push_back(a[i][k]);
                        a[wordbank[j].size()+i][-1].push_back(wordbank[j]);
                    }
                                        

                }
                
            }
            

        }
    }
    


}
int main() 
{
    string target = "abcdef";
    vector<string> bank  = {"ab","abc","cd","def","abcd"};
    // cout<<target.substr(0);   

    
    
    cout<<endl;
    return 0;
}