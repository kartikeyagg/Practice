#include<stdio.h>
#include<stdlib.h>
//struct node for containing an element and address of the next structure to it where next element is present
struct Node{
    int data;
    struct Node *next;
}; 
void linkedlistTraversal(struct Node * head){

struct Node * ptr = head;
// do while loop is used in circular linked list for convenience
do {

printf("element: is %d \n",ptr->data);
ptr =  ptr->next;

}while(ptr!=head);


}
struct Node *insertAtfirst(struct Node *head,int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p;
    p = head->next;
    ptr->data = data;
    // ptr->next = head;
    do {
        p = p->next;
    }while(p->next!=head);
    p->next = ptr;
    ptr->next = head;
    return ptr;
}

int main()
{   //intializing various struct Node pointers;
struct Node *head;
struct Node *ptr;
struct Node *ptr1;
struct Node *ptr2;
struct Node *second;
struct Node *third;
struct Node *fourth;
int index ;
int element = 643;
//allocate memory of nodes in the linked list in heap
head=(struct Node *)malloc(sizeof(struct Node));
second=(struct Node *)malloc(sizeof(struct Node));
third=(struct Node *)malloc(sizeof(struct Node));
fourth=(struct Node *)malloc(sizeof(struct Node));

//link first and second node
head->data=7;
head->next=second;


//link third and second node
second->data=11;
second->next=third;

third->data=36;
third->next=fourth;

fourth->data=78;
fourth->next=head ;//ar circular L.list it will point to head
linkedlistTraversal(head);
printf("inserting at head in circular linked list \n"); //int element is defined above for insertion
head = insertAtfirst(head,element);

linkedlistTraversal(head);





    return 0;
}