#include<bits/stdc++.h>
using namespace std;
// similar to dp_can construct but this time we need to return 
// number of ways target sum can be made
map<string,int> mp;
int countConstruct(string target , vector<string> wordbank){
    if(mp.count(target)>0){return 0;}
    if(target == ""){ // if the target is empty return true;(base case)
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
            tp = countConstruct(temp,wordbank);
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
{  
    string target  = "abcdef";
    vector<string>  wordbank= {"ab","abc","cd","def","abcd"};
    int counts = countConstruct(target,wordbank);
    cout<<counts<<endl;
    cout<<endl;
    return 0;
}