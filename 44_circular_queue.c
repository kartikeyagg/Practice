//for the important logic see line 13
//circular queue counters the problem of excessive memory used by the linear queue
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct circularqueue{
int size;
int f;//index before the first element 
int r; // r is the index of the last element in the circularqueue
int *arr;
};
int isFull(struct circularqueue *q){
    if ((q->r+1)%q->size == q->f){ //very important logic is here
        printf("the queue is full\n");
        return 1;
    }
    else{
        return 0;
    }

}
int isEmpty(struct circularqueue *q){//if both the f and r index are equal then the q is empty
    if (q->r==q->f){
         printf("the circularqueue is empty\n");
        return 1;
    }
    else{
        return 0;
    }
}
//traverse through the list

void qtraversal(struct circularqueue *q){
    int i;
    if(isEmpty(q)){
       
        return;
    }

    for (i = q->f+1;i!=(q->r+1);i = (i+1)%(q->size)){
        printf("Element : %d \n",q->arr[i]);
    }}

int peek(struct circularqueue *q,int index){
    int i;
    if(isEmpty(q)){
       
        return;
    }
    printf("Element peeked : %d \n",(q->arr[index+(q->f)+1]));//not simple index could not be used
    //as the circularqueue need not to be starting with 0  and p+1 is the real starting index
    return (q->arr[index+(q->f)+1]);


}
//function to add at the end of the circular_queue
void enque(struct circularqueue *q,int data){
    if (isFull(q)){
        return;
    }
    q->r = (q->r+1)%(q->size);
    q->arr[q->r] = data;

}
//to delete the first entry in circular_queue
int deque(struct circularqueue *q){
     int a = -1;
    if (isEmpty(q)){
        printf("the circular_queue is empty\n");
    }
    else{
    q->f = (q->f+1)%(q->size);
    a=q->arr[q->f];
    }
    return a;

}
int main(){
    struct circularqueue *q; //a structure pointer
    q = (struct circularqueue*)malloc(sizeof(struct circularqueue*)); //dynamic memory allocation to it
    q->size = 100;
    q->f = q->r =-1;
    q->arr = (int *)malloc(sizeof(q->size*(sizeof(int)))); //dynamic memory allocatin for an integer array
    qtraversal(q);
    enque(q,3443); //enqueing elements in the array (from the rear end)
    enque(q,767);
    enque(q,8786);
    enque(q,544);
    enque(q,908);
    qtraversal(q); // traversal through queue to look all the entries 

    int t = deque( q); // dequeing the queue (from the front end)
    printf("After deque \n");
    qtraversal(q);
    peek(q,2);
    // t = deque( q);
    // t = deque( q);
    // t = deque( q);
    // t = deque( q);
    // printf("After deque \n");
    // qtraversal(q);

    return 0;
}