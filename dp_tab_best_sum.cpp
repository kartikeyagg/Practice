#include<bits/stdc++.h>
using namespace std; // same like dp_tab_cansum but we need to tell how the target has been reached;
vector<int> bestsum(int target,vector<int> & a,vector<int> & tab){

    vector<vector<int>> vec(target+1,vector<int> (1,-1));
    vec[0][0] = 0;
    for (int j = 0; j < target+1; j++)
    {   if(vec[j][0]!=-1)
       { for (int i = 0; i < a.size(); i++)
        {   
            if(j+a[i]<=target){
                if(vec[j+a[i]][0]==-1 || vec[j].size()<vec[j+a[i]].size()){
                    vec[j+a[i]] = vec[j];
                    vec[j+a[i]].push_back(a[i]);}
                    }
            // if(j+a[i]==target){
            //     return vec[target];
            // }
        }}
    }
    return vec[target];
}
int main() {

    // int target = 7;
    // vector<int> a={ 5,3,4}; //returns {3,4}
    // int target = 300;
    // vector<int> a={7,14}; // return empty array
    int target = 8;
    vector<int> a = { 2,3,5}; // returns (5,3) the shortest required array
    vector<int> tab;
    tab = bestsum(target,a,tab);
    for (int i = 1; i < tab.size(); i++)
    {
        cout<<tab[i]<<", ";
    }
    cout<<endl;
    return 0;
  }