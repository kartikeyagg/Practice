#include<stdio.h>
#include<stdlib.h>
struct Node{ int data;
struct Node* next;};
//function for travalsing through linked list
void linkedlisttraversal(struct Node *ptr ){
    while((ptr)!=NULL){
    printf("Element: %d\n",ptr->data);
    ptr = ptr->next;}
}
//to check if the stack is empty
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
//very important pop function is ** ptr is passed to change the value of passed
//top by call by reference
//or one can also make a global variable top at the starting of the programe

int pop(struct Node ** ptr){
    if (isEmpty(*ptr)){
        printf("THE STACK Underflowed\n");
    }
    else{
    struct Node * n = *ptr;
    *ptr = (*ptr)->next;
    int c = n->data;
    free(n);
    return c;
}}

int main(){
    struct Node * top = NULL;
    top =push(top,234);//value of element to be pushed
    top =push(top,36);
    top =push(top,98);
    top =push(top,12);
    linkedlisttraversal(top);
    int c  = pop(&top);
    printf("the poped element is %d\n",c);
    linkedlisttraversal(top);


    return 0;
}