#include<stdio.h>
#include<stdlib.h>
//struct node for containing an element and address of the next structure to it where next element is present
struct Node{
    int data;
    struct Node *next;
}; 
//travelsing through list to print the data
void linkedlisttraversal(struct Node *ptr ){
    while((ptr)!=NULL){
    printf("Element: %d\n",ptr->data);
    ptr = ptr->next;}

}
struct Node * deleteFirst(struct Node *head){
    struct Node * p;

 p = head->next;
 free(head);
 return p;

}
void delete_at_index(struct Node *head,int index){
    struct Node *p = head;
    struct Node *q;
    int i = 0;
    while(i!=index-1){
        p =p->next;
        i++;  
    }
    q= p->next;
    p->next = q->next;
    free(q);

}
void delete_at_end(struct Node *head){

    struct Node *p = head;
    struct Node *q;
    q =p->next;

    while(q->next != NULL){
        p = q;
        q=q->next;
    }
    p->next = NULL;
    free(q);

}
//very important case
void delete_the_element(struct Node *head,int element){
     struct Node *p = head;
     struct Node *q;
     q =p->next;
     if(p->data == element){
         printf("this is the first element try other funciton\n");
         exit(0);
     }
    while(q->data != element && q->next!=NULL){
        p = q;
        q=q->next;
 }
 if (q->data == element)
    {p->next = q->next;
    free(q);}
else{
    printf("\n****The element given not found**** \n\n");
}
}

int main()
{   //intializing various struct Node pointers;
struct Node *head;
struct Node *ptr;
struct Node *ptr1;
struct Node *ptr2;
struct Node *second;
struct Node *third;
int index ;
//allocate memory of nodes in the linked list in heap
head=(struct Node *)malloc(sizeof(struct Node));
second=(struct Node *)malloc(sizeof(struct Node));
third=(struct Node *)malloc(sizeof(struct Node));

//link first and second node
head->data=7;
head->next=second;


//link third and second node
second->data=11;
second->next=third;

third->data=66;
third->next=NULL ;//important to close the linked list we pointed last 'next'o NULL
linkedlisttraversal(head);

// head = deleteFirst(head); //for deleting the first element

// index = 1;   For deleting the element at given index
// delete_at_index(head,index);

// delete_at_end(head); // for deletion at the end

int element = 643;
delete_the_element(head,element);

printf("list after deletion \n");
linkedlisttraversal(head);

    return 0;
}