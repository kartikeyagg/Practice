#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    Node *arb;

    Node(int x){
        data = x;
        next = NULL;
        arb = NULL;
    }

};
void display_LL(Node* head){
    cout<<"the linked list is \n";
    while(head!=NULL){
        cout<<(head->data)<<" ";
        head = head->next;
    }cout<<endl;}

Node* build_node(int d1){
        Node * t = (Node *)malloc(sizeof(Node));
        t->data = d1;
        t->next = NULL;
        t->arb = NULL;
        return t;
    }
    
Node *copyList(Node *head)
    {
        //Write your code here
        if(head ==NULL){
            return NULL;
        }
        Node * t = build_node(head->data);
        t->next = copyList(head->next);
        // t = head;
        t->arb = copyList(head->arb);
        return t;
    }
Node * LL_build(vector<int> &A){

    Node* head = build_node(A[0]);
    Node* y= head;
    int i=1;
    while(i<A.size()){
        head->next = build_node(A[i]);
        head = head->next;
        i++;
    }
    return y;

}    

int main() 
{  
    vector<int> a = {2332,3,23,};
    
    
    cout<<endl;
    return 0;
  }