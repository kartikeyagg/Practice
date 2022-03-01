#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
void display_LL(Node* head){
    cout<<"the linked list is \n";
    while(head!=NULL){
        cout<<(head->data)<<" ";
        head = head->next;
    }cout<<endl;}
struct Node* partition(struct Node* head, int x) {
    // code here
    cout<<"in the code"<<endl;
    struct Node* t1= (struct Node*)malloc(sizeof(Node)) ;
    t1->data = -(INT_MAX-1000);
    t1->next  = head;
    struct Node* t2 = (struct Node*)malloc(sizeof(Node));
    t2 = t1;
    struct Node* t3 = (struct Node*)malloc(sizeof(Node));
    t3->data  = -150;
    t3->next = NULL;
    
    struct Node* t4 = (struct Node*)malloc(sizeof(Node));
    t4->data  = -160;
    t4->next = NULL;
    struct Node* temp  =(struct Node*)malloc(sizeof(Node));
    struct Node* temp1  =(struct Node*)malloc(sizeof(Node));
    struct Node* temp2  =(struct Node*)malloc(sizeof(Node));
    int flag1 =0,flag2=0;
    struct Node* temp5  =(struct Node*)malloc(sizeof(Node));
    temp5 = t2;
    temp2->data  = -4342;
    temp1->data  = -4342;
    temp1->next = NULL;
    temp2->next = NULL;
    cout<<"before loop"<<endl;
    while(t2->next!=NULL){
        cout<<"for node "<<t2->data<<endl;
        if(((t2->next)->data)>x){
            temp = t2->next;
            t2->next = temp->next;
            t4->next = temp;
            cout<<"resetling node "<<(temp->data)<<endl;
            temp->next = NULL;
            t4 = t4->next;
            if(flag1==0){
                flag1=1;
                temp2 = t4;
            }
            
        }
        else if(((t2->next)->data)==x){
            temp = t2->next;
            t2->next = temp->next;
            t3->next = temp;
            temp->next = NULL;
            cout<<"resetling node "<<(temp->data)<<endl;

            t3 = t3->next;
            if(flag2==0){
                flag2=1;
                temp1 = t3;
            }
            
        }
        else{
            t2 = t2->next;
        }
    }
    // cout<<"Loop completed \n";
    // while(t2!=NULL){
    //     if(t2->data == x){
    //         t3 = t2;
    //     }
    //     else if(t2->data >x){
    //         t4 = t2;
    //         break;
    //     }
    //     t2 = t2->next;
    // }
    cout<<"displaying single lists \n";
    display_LL(temp1);
    display_LL(temp2);
    display_LL(t1->next);
    if(temp1->data != -4342 )
    {t2->next = temp1; // change here as it pointing from head
    // and not from the tail;
    
    while(temp1->next !=NULL){
        temp1 = temp1->next;}
        t2 = temp1;
    }
    if(temp2->data != -4342)
    {t2->next = temp2;}
    return t1->next;
    
}
Node* build_node(int data1){
    struct Node* temp2  =(struct Node*)malloc(sizeof(Node));
    temp2->data = data1;
    temp2->next = NULL;
    return temp2;
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
{  cout<<endl;
    // vector<int> A = {1,4,3,2,5,2,3};
    vector<int> A = {9,7};
    Node * t = LL_build(A);
    display_LL(t);
    Node * t2 = partition(t,9);
    cout<<"final LL :-"<<endl;
    display_LL(t2);
    
    
    cout<<endl;
    return 0;
  }