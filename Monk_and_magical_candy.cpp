#include<bits/stdc++.h>
using namespace std;
// this question aims use of multiset 
// this question is from hacker earth
// with name monk and magical candy bag;
int main() 
{
  int n =5;
  int k = 3;
  long long A[n]= {2,1,7,4,2};
  multiset<long long> ms;
  for (int i = 0; i < n; i++)
  {
    ms.insert(A[i]);
  }
  long long total_candies =0,candy_ct;

  for (int i = 0; i < k; i++)
  {
    auto last_it = ms.end();
    last_it--;
    candy_ct = *last_it;
    total_candies += candy_ct;
    ms.erase(last_it); // important 
    //  as iterator is passed instead of elements 
    // as passing the element will delete all the element with that value
    // but passing iterator will delete the element present at that iterator only
    ms.insert(candy_ct/2);
  }
  
  
  cout<<"the answer is "<<total_candies<<endl;


  // for(auto x:A){
  //   cout<<"yoyo"<<endl;
  // }
  cout<<endl;
  return 0;
  }