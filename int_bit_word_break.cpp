#include<bits/stdc++.h>
using namespace std;
int recfunc(string A ,vector<string> B){
    cout<<"for string "<< A<<" of size "<<A.size()<<endl;
    if(A.empty()){return 1;}
    if(B.empty()){return 0;}
    int pre,pos;
    string temp;
    for(int i=0;i<B.size();i++){

        pre = A.find(B[i]);
        if(pre==0){
            pos  = B[i].size();
            temp = B[i];
            cout<<"erasing "<<B[i]<<endl;

            B.erase(B.begin()+i);
            if(recfunc(A.substr(pos),B)==1){
                return 1;
            }
            else{
                cout<<" got zero \n";
            }
            B.insert(B.begin()+i,temp);
        }

    }
    return 0;
}
// int Solution::wordBreak(string A, vector<string> &B) {

//     return (recfunc(A,B));}


int main() 
{  string A = "aaaabbbbababbaababbbabbabaaabbaaaabbababbaabababaabbbababaaababbbbbaaababababbbbbaaaabbabbabaabbababbaaaaabbaababababbbaaaabaaabaabaababbabaaabaaababababbaabbbbbaabbabbaaaaabbabbbabbbbaaaaabababbaababbabbbabbbababaabaababbbaaaaababababbaabaabaabbbbaaabbbbbbababbabbabaabbaababbbbbbabaababbbbababbabbbbbbabbbbbbaabbbbbbabaabbabaabbbaaaababaababbbabaabbbbabbbbbbbababbaabbbaaabaabaabaabbbab";
    vector<string> B  ={"bbabaaaaba", "abbaa", "bbabbaaba", "bbaabbab", "ab", "b", "abaaaababa", "aa", "babaa", "aaa", "baa", "ab", "baaabbbba", "aaaba", "a", "bbaababaab", "baaaaaaa", "aaab", "bbabbbbaaa", "ab", "aaa", "bbb", "a", "bab", "aaaaaa", "aa", "b", "ababaabbb", "bbb", "babbbbba", "bbabb", "ab", "a", "baabaabbb", "aaabab", "aba", "a", "babba", "aaaababbbb", "b", "baab", "baabbbb", "babbb", "ababaa", "babbaa", "abaaa", "babababab", "bab", "aa", "abbaa", "abb", "bbbaaaaba", "bbbabababb", "aaaa", "ba", "bbaabbbaab", "bababb", "bbbb", "baaabbaab", "bababbbaaa", "bbaab", "ab", "bbbaaa", "aaaa", "aab", "baabaabaa", "bb", "ba", "bbbb", "abbaababab", "baaaaaa", "baaabbbb", "baab"};
    int t  = recfunc(A,B);
    cout<<t<<endl;

    
    
    cout<<endl;
    return 0;
  }