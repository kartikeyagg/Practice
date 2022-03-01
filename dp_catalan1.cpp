#include<bits/stdc++.h>
using namespace std;

long int catalank(int cat){
    vector<long int> vec((cat)+1,0);
    vec[0]=vec[1] =1;
    for (int i = 2; i < cat+1; i++)
    {   for (int j = 0; j < i; j++)
    {
        vec[i] += vec[j]*vec[i-1-j];
    }
    

        // vec[i] = vec[i-1]*i;    
    }

    // return (vec[2*cat])/(vec[cat+1]*vec[cat]);
    return vec[cat];

}

int main() 
{  
    int cat = 11;
    long int t = catalank(cat);
    cout<<t<<endl;
    cout<<endl;
    return 0;
  }