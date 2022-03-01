#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
struct TreeNode1{
    char val;
    // vector<TreeNode1*> vec;
    map<char,struct TreeNode1*> mp;
    int freq;

};
//vector<string> Solution::prefix(vector<string> &A) {

TreeNode1* createnode(char val1){

    TreeNode1* tp  = (struct TreeNode1*)malloc(sizeof(struct TreeNode1));
    tp->val = val1;
    // vector<TreeNode1*> tv;
    map<char,TreeNode1*> mp1;
    tp->mp = mp1;
    tp->freq =0; //number of time used;
    return tp;

}

vector<string> prefix(vector<string> &A) {
    // sort(A.begin(),A.end());
    int n = A.size();
    TreeNode1* c  = createnode('9');//(struct TreeNode1*)malloc(sizeof(struct TreeNode1));
    // c->val = '9';
    TreeNode1* r  ;//= (struct TreeNode1*)malloc(sizeof(struct TreeNode1));
    TreeNode1* at =c;
    for(int i =0;i<n;i++){
        cout<<"in 12 loop \n";
        cout<<"for string "<<A[i]<<endl;

        c =at;

        for(int j=0;j<A[i].size();j++){
            cout<<"11 loop \n";
            cout<<"for char "<<A[i][j]<<endl;



            if((c->mp).count(A[i][j])==0){
                cout<<"not found"<<endl;
                r = createnode(A[i][j]);
                (c->mp)[A[i][j]] = r;
                c= (c->mp)[A[i][j]];


            }
            else{
                cout<<"found"<<endl;

                c= (c->mp)[A[i][j]];
                c->freq++;
            }
        }

    }
    cout<<"fin firs loop \n";
        c =at;
        int trew=0;
    vector<string> res;
    string s;
    int flag=0;
    for(int i =0;i<n;i++){
    c =at;
    s.clear();
    for(int j=0;j<A[i].size();j++){

        c= (c->mp)[A[i][j]];
        s+=A[i][j];
        if((c->mp).size()<2 && c->freq==0){
            // r =c;
            // trew = 0;
            // while((c->mp).size()!=0){
            //     c =(c->mp)[A[i][j+trew]];
            //     if((c->mp).size()>1){
            //         flag =1;
            //         break;
            //     }
            //     trew++;
            // }
            // c=r;
            // if(flag==0)
            break;
            }


    }
    res.push_back(s);
    }

return res;
}

  
int main() 
{  vector<string> a = {"zebra", "dog", "duck", "dot"};//{"zebra","dog","dove","duck","dot"};

    vector<string> res = prefix(a);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    return 0;
  }