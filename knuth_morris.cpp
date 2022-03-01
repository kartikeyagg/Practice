#include<bits/stdc++.h>
using namespace std;
  // this program aims to implement KMP algorithm to
  // for pattern matching

vector<int> generate_pattern_vec(string &s){
    int n = s.size();
    cout<<" the size of string is "<<n<<endl;
    int i =0,j=0;
    vector<int> res;
    res.clear();
    if(n==0){return res;}
    res.push_back(0);
    i=1;
    while(i!=n){
        cout<<"i and j are "<<i<<" "<<j<<endl;

        if(s[i] == s[j]){
            // res[i] = res[j]+1;
            res.push_back(j+1);
            j++;
        }
        else{
            // if(j==0){i++;continue;}
            if(j!=0){ 
                while(j!=0){
                    j = res[j-1];
                    cout<<"Updated j to "<<j<<endl;
                    if(s[i]==s[j]){
                        // res[i] = res[j]+1;
                        res.push_back(j+1);
                        j++;
                        break;
                    }
                }
                if(s[0]!=s[i]){
                    res.push_back(0);

                }
            }
            else{
                res.push_back(0);
            }
        }

        i++;
    }
    return res;
}
void displayv(vector<int> &a){
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int kmp(string &pattern, string &s){

    vector<int> a = generate_pattern_vec(pattern);
    int ns  = s.size(),np = pattern.size();
    int i=0,j=0;
    cout<<"vector a size is "<<a.size()<<endl;
    displayv(a);

    while(j<np){
        if(s[i] == pattern[j]){
            // i++;
            j++;
        }
        else {
            while(j!=0){
                j = a[j-1];
                if(s[i]==pattern[j]){
                    j++;
                    break;
                }
            }
        }
        i++;

    }

    if(j==np){return 1;}
    return 0;



}


int main() 
{   
    string mainst = "abxabcabcaby";
    string pattern = "abcaby";
    // vector<int> a = generate_pattern_vec(s);
    // cout<<"The size of res is "<<a.size()<<endl;
    // for (int i = 0; i < a.size(); i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    if(kmp(pattern,mainst)){
        cout<<" yes \n";
    }
    else{
        cout<<" not found \n";
    }
    cout<<endl;
    return 0;
  }