#include <iostream>
#include <vector>
using namespace std;
  
int main() 
{  
    vector<int> vec = {1,34,5,46};
    vec.erase(vec.begin());
    cout<<vec[0];
    
    cout<<endl;
    return 0;
  }