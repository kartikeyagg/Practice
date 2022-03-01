#include<stdio.h>
#include<stdlib.h> //for dynamic memory allocation
//struct node for containing an element and address of the next structure to it where next element is present
struct Node{
    int data;
    struct Node *next;
}; 

//travelsing through list to print the data
void linkedlisttraversal(struct Node *ptr ){
    while((ptr)!=NULL){
    printf("element: %d\n",ptr->data);
    ptr = ptr->next;}

}
//function to insert an element in the begining
struct Node *insertAtfirst(struct Node *head,int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    int a; 
    return ptr;
}
//function to insert an element in btw given an index
struct Node *insertinbtw(struct Node *head,int data,int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *y1 = head;
    ptr->data = data;
    int i =0;
   while(i!=index-1){ //travelsing to the given index
       y1 = y1->next;
       i++;
 }
 struct Node *temp;
 temp = y1->next;            //adding a node in btw
 y1->next = ptr;
 ptr->next = temp;

    return ptr;
}
//function to insert the element at the end of the array
struct Node *insertAtlast(struct Node *head,int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *y1 = head;
    while((y1->next)!=NULL){


        y1 = y1->next;  //travelsing to the last element
    }
    y1->next = ptr;
    ptr->next = NULL;
    return head;
}
//to insert an element after the given node {time complexity = O(n) //very important}
struct Node *insertAfterNode(struct Node *prevnode,int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;  
    ptr->next = prevnode->next;      //adding it after a
    prevnode->next = ptr;
    return prevnode;
}
int main(){
    //intializing various struct Node pointers;
struct Node *head;
struct Node *ptr;
struct Node *ptr1;
struct Node *ptr2;
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
printf("inserting element at the starting of list\n");

ptr=insertAtfirst(head,6523);
linkedlisttraversal(ptr);
//insert in between the list given an index
printf("inserting element in between  of list at the given index\n");
ptr1 = insertinbtw(ptr,3242,3);
linkedlisttraversal(ptr);
//inserting an element at the last 
printf("INsertting at the last \n");
ptr=insertAtlast(ptr,9623);
linkedlisttraversal(ptr);
printf("INsertting after given node \n");
//for inserting an element after an given node;
ptr2 = insertAfterNode(second,54863);
linkedlisttraversal(ptr);
    return 0;
}