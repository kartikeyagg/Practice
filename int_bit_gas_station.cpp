#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int check_c(const vector<int> &A,const vector<int> &B,int i){
    int j(0),na = A.size();

    int curr_gas;
    int temp =0;
    int kst =temp;
    // vector<int> vec(na,0);
    vec.clear();
    for(int tk =0 ;tk<=na;tk++){

        vec.push_back(0);

    }
    vec[0] = 1;
    while(temp<na){

        if(vec[temp]!=0){

        curr_gas = A[i];
        j=i;
        kst = temp;
        while(curr_gas - B[i]>=0){
          cout<<"i is "<<i<<endl;
          cout<<"current gas is "<<curr_gas<<endl;
          cout<<"temp is "<<temp<<endl;
            curr_gas-=B[i];
            i= (i+1)%na;
            temp++;
            curr_gas += A[i];
            if(temp>=na){
                vec[na] =1;
                return 1;
                // break;
            }
            else{vec[temp] = 1;}
        }
        cout<<"redef"<<endl;  
        i = (j+1)%na;
        temp  =kst+1;
        cout<<" i and temp are "<<i<<" "<<temp<<endl; 
    }
    else{
        cout<<"redef1"<<endl;  
        i= (i+1)%na;
        temp++;
        cout<<" i and temp are "<<i<<" "<<temp<<endl; 

        
    }
    }
    return 0;

}
int check_c1(const vector<int> &A,const vector<int> &B,int i){
    int j(0),na = A.size();
    int curr_gas =0;
    int temp =0;
    int kst =temp;
    while(temp<=na){
        curr_gas+=A[i];
        if(curr_gas-B[i]>=0){
            curr_gas-=B[i];
            temp++;
            i = (i+1)%na;
        }
        else{
            return 0;
        }
    }
return 1;

}
int canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    vec.clear();
    int j(0),i(0),na = A.size();
    int curr_gas = A[0];
    int res =-1;
    for(i =0 ;i<na;i++){
        cout<<"for starting pt"<<i<<endl;
        if(check_c1(A,B,i) == 1){
            res = i;
            break;
        }
    }
    return res;
}

int main() 
{ 
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = { 3, 4, 5, 1, 2};
    // A : [ 2, 3, 4 ]
// B : [ 3, 4, 3 ]
    // A : [ 1, 2, 3, 4, 5 ]
    // B : [ 3, 4, 5, 1, 2 ]
    int t  = canCompleteCircuit(A,B);
    cout<<"#result is "<<t<<endl;
    cout<<endl;
    return 0;
  }