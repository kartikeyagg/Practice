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
    string temp;//conta;
    for (int i = 0; i < wordbank.size(); i++)
    {
        ind=target.find(wordbank[i]); // storing the index of the first letter of substring present in the string
        // if string is not present it returns -1;
        if(ind==0) // checking if the substring is the prefix
        {   
            pos = ind+wordbank[i].size();
            temp = target.substr(pos); // calling recursive function now for target (target  - prefix)
            ar.push_back(wordbank[i]); //  IMPORTANT
            // conta = wordbank[i];
            // wordbank.erase(wordbank.begin()+i);
            tp = allConstruct(temp,wordbank,ar);//  IMPORTANT
            // wordbank.insert(wordbank.begin()+i,conta);
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
    mp.clear();
    // string target  = "abcdef";
    // vector<string>  wordbank= {"ab","abc","cd","def","abcd"};
    // string target  = "purple";
    // vector<string>  wordbank= {"purp","p","ur","le","purpl"};    
    // string target  = "catsanddog";
    // vector<string>  wordbank= {"cats","cat","and","sand","dog"};
    string target  = "aaabaaaaab";
    vector<string>  wordbank= {"aabbbaaa", "aaba", "a", "b","a", "babbbabb", "baaaab"};
    map<string,int> mpc;
    for (int i = 0; i < wordbank.size(); i++)
    {
        if(mpc.count(wordbank[i])==0){
            mpc[wordbank[i]]=1;
        }
        else{
            wordbank.erase(wordbank.begin()+i);
            i--;
        }
    }
    
    vector<string> emp;
    int counts = allConstruct(target,wordbank,emp);
    cout<<counts<<endl;
    cout<<endl;
    sort(ans.begin(),ans.end());
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
//   A : "aabbbabaaabbbabaabaab"
// B : [ "bababbbb", "bbbabaa", "abbb", "a", "aabbaab", "b", "babaabbbb", "aa", "bb" ]
//
// A : "aaabaaaaab"
// B : [ "aabbbaaa", "aaba", "a", "b", "a", "babbbabb", "baaaab" ]