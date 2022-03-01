// You are given an array of Denominations and a value X. You
// need to find the minimum number of coins required to make
// value X.
// each coin supply is unlimited
//Approach
//1- Start from the largest value, till we can include it, take it.
//2- Else move on the smaller value.

#include<bits/stdc++.h>
using namespace std;

int cmp(int a,int b){
    return a>b;
}

int num_coins(vector<int> &coins,int amount){
    sort(coins.begin(),coins.end(),cmp);
    for(auto x:coins){
        cout<<x<<" ";
    }
    cout<<endl;
    int i =0;
    int count =0;
    while(amount>0){

        while(coins[i]>amount && i<coins.size()-1){
            i++;
        }
        amount-=coins[i];
        count++;

    }
    return count;
}
  
int main() 
{  
    vector<int> coins = {2000,500,200,100,50,20,10,5,2,1};

    int amount = 254;
    int result  = num_coins(coins,amount);
    cout<<"the result is "<<result;
    cout<<endl;
    return 0;
  }