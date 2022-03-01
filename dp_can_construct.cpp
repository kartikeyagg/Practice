#include<bits/stdc++.h>
using namespace std;
// given a string (target) and an array of strings 
// check wheather the target string can be made  by the strings present in array
// array strings can be used multiple times
map<string,int> mp;
int canConstruct(string target , vector<string> wordbank){
    if(mp.count(target)>0){return 0;}
    if(target == ""){ // if the target is empty return true;(base case)
        return true;
    }
    int ind,pos;
    string temp;
    for (int i = 0; i < wordbank.size(); i++)
    {
        ind=target.find(wordbank[i]); // storing the index of the first letter of substring present in the string
        // if string is not present it returns -1;
        if(ind==0) // checking if the substring is the prefix
        {   pos = ind+wordbank[i].size();
            temp = target.substr(pos); // calling recursive function now for target (target  - prefix)
            if(canConstruct(temp,wordbank)){
                return 1;
            }
        }
        
    }
    mp[target] = 1; // if no string is present in array which is substring of
    // target return 0  and store it for memoization
    return 0;
}

int main() 
{  // temporary code for checking
    string sub = " qwerty";
    string whole = " qwertyuiop";


    int ind =whole.find(sub),pos(0);
    cout<<ind<<endl;
    if(ind!=-1)
    {pos = ind+sub.size();
    whole  = whole.substr(pos);
    
    }
    cout<<whole<<endl<<endl;
    // temp code ends
    mp.clear();
    //
    // string target  = "abcdef";
    // vector<string>  wordbank= {"ab","abc","cd","def","abcd"};
    // string target = "skateboard";
    // vector<string>  wordbank= {"bo","rd","ate","t","ska","sk","boat"};
    string target  = "eeeeeeeeeeeeeeeeeeeef";
    vector<string>  wordbank= {"e","ee","eee","eeee","eeeee"};
    int t  = canConstruct(target,wordbank);
    if(t){
        cout<<"It can be constructed \n";
    }
    else{
        cout<<"No it can't be constructed \n";
    }
    cout<<endl;
    return 0;
  }