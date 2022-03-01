#include<stdio.h>
#include<stdlib.h>
 // a structure named node to contain data and pointer of the next element
struct Node{

int data;
struct Node *next;


};

void linkedlisttraversal(struct Node *ptr ){
    while((ptr)!=NULL){
    printf("element %d\n",ptr->data);
    ptr = ptr->next;}


}
int main(){
struct Node *head;
struct Node *second;
struct Node *third;
//allocate memory of nodes in the linked list in heap
head=(struct Node *)malloc(sizeof(struct Node));
second=(struct Node *)malloc(sizeof(struct Node));
third=(struct Node *)malloc(sizeof(struct Node));

//link first and second node
head->data=34;
head->next=second;


//link third and second node
second->data=24;
second->next=third;

third->data=66;
third->next=NULL ;//important to close the linked list we pointed last 'next'o NULL
linkedlisttraversal(head);


    return 0;
}