#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct queue{
int size;
int f;//index before the first element 
int r; // r is the index of the last element in the queue
int *arr;
};
int isFull(struct queue *q){
    if (q->r == q->size-1){
        return 1;
    }
    else{
        return 0;
    }

}
int isEmpty(struct queue *q){//if both the f and r index are equal then the q is empty
    if (q->r==q->f){
         printf("the queue is empty\n");
        return 1;
    }
    else{
        return 0;
    }
}
//traverse through the list

void qtraversal(struct queue *q){
    int i;
    if(isEmpty(q)){
       
        return;
    }

    for (i = q->f+1;i<=(q->r);i++){
        printf("Element : %d \n",q->arr[i]);
    }}

int peek(struct queue *q,int index){
    int i;
    if(isEmpty(q)){
       
        return;
    }
    printf("Element peeked : %d \n",(q->arr[index+(q->f)+1]));//not simple index could not be used
    //as the queue need not to be starting with 0  and p+1 is the real starting index
    return (q->arr[index+(q->f)+1]);


}
//function to add at the end of the queue
void enque(struct queue *q,int data){
    if (isFull(q)){
        return;
    }
    q->r++;
    q->arr[q->r] = data;

}
//to delete the first entry in queue
int deque(struct queue *q){
     int a = -1;
    if (isEmpty(q)){
        printf("the queue is empty\n");
    }
    else{
    q->f++;
    a=q->arr[q->f];
    }
    return a;

}
int main(){
    struct queue *q;
    q = (struct queue*)malloc(sizeof(struct queue*));
    q->size = 100;
    q->f = q->r =-1;
    q->arr = (int *)malloc(sizeof(q->size*(sizeof(int))));
    qtraversal(q);
    enque(q,3443);
    enque(q,767);
    enque(q,8786);
    enque(q,544);
    enque(q,908);
    qtraversal(q);
    int t = deque( q);
    printf("After deque \n");
    qtraversal(q);
    peek(q,2);


    return 0;
}