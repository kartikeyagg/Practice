#include<bits/stdc++.h>
using namespace std; //same as dp count but this time the elements need to be returned
// from which the target is build;
map<string,int> mp;
vector<vector<string>> ans;
int allConstruct(string target , vector<string> wordbank,vector<string> &ar){
    if(mp.count(target)>0){return 0;}
    if(target == ""){ // if the target is empty return true;(base case)
        ans.push_back(ar); // storing the whole element if the target is reached
        return 1;
    }
    int ind,pos,counts=0,tp=0;
    string temp;
    for (int i = 0; i < wordbank.size(); i++)
    {
        ind=target.find(wordbank[i]); // storing the index of the first letter of substring present in the string
        // if string is not present it returns -1;
        if(ind==0) // checking if the substring is the prefix
        {   
            pos = ind+wordbank[i].size();
            temp = target.substr(pos); // calling recursive function now for target (target  - prefix)
            ar.push_back(wordbank[i]); //  IMPORTANT
            tp = allConstruct(temp,wordbank,ar);//  IMPORTANT
            ar.pop_back();//  IMPORTANT
            // if(tp){
            //     return 1;
            // }
            counts+=tp;

        }
        
    }
    if(counts>0){
        return counts;
    }
    mp[target] = 1; // if no string is present in array which is substring of
    // target return 0  and store it for memoization
    return 0;
}

int main() 
{   ans.clear();
    // string target  = "abcdef";
    // vector<string>  wordbank= {"ab","abc","cd","def","abcd"};
    string target  = "purple";
    vector<string>  wordbank= {"purp","p","ur","le","purpl"};    
    vector<string> emp;
    int counts = allConstruct(target,wordbank,emp);
    cout<<counts<<endl;
    cout<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<", ";
        }
        cout<<endl;
        
    }
    // output:-
        // purp, le, 
        // p, ur, p, le, 

    
    cout<<endl;
    return 0;
  } 