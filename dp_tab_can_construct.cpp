#include<bits/stdc++.h>
using namespace std;
// the program has one string 'target' and a vector of
// strings check whether it can be formed via the strings of the vector
// count construct has also been in itegrated in this program
// count sort means in how many ways the target string can 
// be made
int canconstruct_tab(string target,vector<string> &wordbank){

    vector<int> res(target.size()+1,0);
    res[0] = 1;
    for (int i = 0; i < target.size()+1; i++)
    {
        if(res[i]!=0){ // the word should be itself reachable
            cout<<"for i  = "<<i<<endl;
            for (int j = 0; j < wordbank.size(); j++)
            {   // if the words matches at the position i
                if(target[i] == wordbank[j][0] && target[i+(wordbank[j].size())-1] ==wordbank[j][(wordbank[j].size())-1]) 
                // in above statement it has been checked if the word is present from the present index of target;
                // it needs to be optimized more;
                {   cout<<"matched "<<wordbank[j]<<endl;
                    res[i+wordbank[j].size()] +=res[i]; // for count 
                    // if not for counting it could have been given a value
                    // of 1 only 
                }
            }
        }
    }
    
return res[target.size()];

}
int main() {
   string target = "abcdef";
    vector<string> bank  = {"ab","abc","cd","def","abcd"};
    // string target = "skateboard";
    // vector<string> bank  = {"ate","rd","bo","t","ska","sk","boar"};
    // string target = "enterapotentpot";
    // vector<string> bank  = {"a","p","ent","enter","ot","o","t"};
    // string target = "eeeeeeeeeeeeeeeef";
    // vector<string> bank  = {"e","ee","eee","eeee","eeeee"};
    // string target = "purple";
    // vector<string> bank  = {"purp","p","ur","le","purpl"};
    int t = canconstruct_tab(target,bank);
    if(t>0){
        cout<<"yes it can be constructed \n";
        cout<<"count is "<<t<<endl;
    }
    else{
        cout<<"it can't be constructed \n";
    }
    cout<<endl;
    return 0;
  }