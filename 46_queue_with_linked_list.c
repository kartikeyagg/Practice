//programe for queue using linked list //an important programe to 
//understand the use of global variables too
#include<stdio.h>
#include<stdlib.h>//for dynamic memory allocation
struct Node { //stucture for the node of the list
int data;
struct Node * next;
}; 
struct Node *rear = NULL,*front=NULL;
int isEmpty(){

    if (front == NULL){
        printf("The queue is empty \n");
        return 1;
    }
    return 0;
}
int isFull(){
    struct Node * test;
    test  = (struct Node * )malloc(sizeof(struct Node));
    if (test == NULL){
        printf("the queue is full \n");
        return 1;
}
    free(test);
    return 0;
}
void traversal(){
    if(isEmpty(front)){
        return;
    }
    struct Node * test;
    test  = (struct Node * )malloc(sizeof(struct Node));
    test  = front;
    printf("the element is : %d \n",test->data);
    while(test != rear){
        test = test->next;
        printf("the element is : %d \n",test->data);
    }
}
void enque(int val){
    if (isFull()){
        return;
}
    struct Node * test;
    test  = (struct Node * )malloc(sizeof(struct Node));
    test->data = val;
    test->next = NULL;
    if(isEmpty(front)){
        front = rear = test;
    }
    else{
        rear->next = test;
        rear=test;
    }
}
int deque(){
    int value = -1;
    if(isFull()){
        ;
    }
    else{
    struct Node * test;
    test  = (struct Node * )malloc(sizeof(struct Node));
    test  =front;
    front  = front->next;
    value  = test->data;
    free(test);
    }

return value;}
int main(){
struct Node * head;
struct Node * second;
struct Node * third;
struct Node * fourth;
head  = (struct Node * )malloc(sizeof(struct Node));
second  = (struct Node * )malloc(sizeof(struct Node));
third  = (struct Node * )malloc(sizeof(struct Node));
fourth = (struct Node * )malloc(sizeof(struct Node));
// head->data = 701;
// head->next = second;
// front = head;
// second->data = 56;
// second->next = third;
// third->data = 432;
// third->next = fourth;
// fourth->data = 987;
// fourth->next = NULL;
// rear  = fourth;
traversal();
printf("erw23\n");
enque(324);
enque(455);
enque(6589);
printf("After enqueing \n");
traversal();
printf("the value at the rear is %d\n",rear->data);
deque();
printf("after dequeing %d\n",rear->data);
traversal();

    return 0;
}