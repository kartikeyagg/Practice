#include<stdio.h>
#include<stdlib.h>

struct Node{ int data;
struct Node* next;};

void linkedlisttraversal(struct Node *ptr ){
    while((ptr)!=NULL){
    printf("Element: %d\n",ptr->data);
    ptr = ptr->next;}
}
int isEmpty(struct Node *top){
    if (top==NULL){
        printf("the stack is empty\n");
        return 1;
    }
    else {
        return 0;
    }
}
int isFull(struct Node *top){
    struct Node * n = (struct Node *)malloc(sizeof(struct Node)) ;
    if (n==NULL){
        printf("the stack is full\n");
        return 1;
    }
    else{
        return 0;
    }}
    //push the element into the stack 
    // one should always remember that in linked list stack the element at the 
    //top is the first element is the linked list unlike simple array stacks 
struct Node * push(struct Node * ptr, int x){
    if (isFull(ptr)){
        printf("THE STACK IS FULL\n");
    }
    else{
    struct Node * n = (struct Node *)malloc(sizeof(struct Node)) ;
    n->data = x;
    n->next = ptr;
    ptr = n;
    return ptr;
}}

struct Node * peek(struct Node *ptr ,int t){//similar to peek
    int i =0;
    while(i!=t-1){
    printf("Element: %d\n",ptr->data);
    ptr = ptr->next;
    i++;}
    printf("the data of peaked element is %d\n",ptr->data);
    return ptr;
}

int main(){
    struct Node * top = NULL;
    top =push(top,234);//value of element to be pushed
    top =push(top,36);
    top =push(top,98);
    top =push(top,12);
    linkedlisttraversal(top);
    printf("now peeking \n");
    struct Node *top1 =peek(top,2);
    // linkedlisttraversal(top);
    // for top
    printf("the top element is %d \n",top->data);
    //for bottom element simply we can use linkedlisttraversal
    // and print only the last element instead of all



    return 0;
}