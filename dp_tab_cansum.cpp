#include<bits/stdc++.h>
using namespace std;

bool cansumtab(int target,vector<int> &elem){
    vector<int> vec(target+1,-1);
    vec[0] = 1; // seed is 0 as it is possible to cansum as no matter what
    // the algo is this way
    // if an elements is possible to generate than all the elements 
    // which are sum of that element and the elements in the given
    // array is also possible
    for (int j = 0; j < target+1; j++)
    {
        if(vec[j]==1){      

            for (int i = 0; i < elem.size(); i++)
            {
                if(j+elem[i]<=target){

                    vec[elem[i]] = 1;

                }
            } //  we could have returned when the target is reached 
            // but the same won't go for the next problems
            }
    }
    if(vec[target]==1){
        return 1;
    }       
}  
int main() 
{  
    int target = 7;
    vector<int> elem = {5,3,7};
    if(cansumtab(target,elem)){
        cout<<" yes the target is possible ";
    }
    else{
        cout<<" no the target is not possible ";

    }        
    cout<<endl;
    return 0;
}