#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack* ptr){
    if (ptr->top ==-1){

        return 1;
    }
    // no need for returning 0 from a else statement as
    // a int function by default return 0
    else {return 0;}
    
}
int isFull(struct stack *ptr){
    printf("%d and %d \n",ptr->top,ptr->size);
    if (ptr->top == (ptr->size)-1){

        return 1;
    }
    else 
    return 0;
    // no need for returning 0 from a else statement as
    // a int function by default return 0
}
// function to push an element is the stack
void pushinstack(struct stack* sp,int value){
    if (isFull(sp)){
        printf("the stack overflowed");
    }
    else{
        sp->top++;
        sp->arr[sp->top] = value;
    }

}
int popfromstack(struct stack *s){
    int val = 0;
    if (isEmpty(s)){
        printf("the stack is empty");
        return -1;
    }
    else {
        val = s->arr[s->top];
        // free(s->arr[s->top]);
        s->top--;
        return val;
        }
}
int main(){
    struct stack *sp;
    int value = 320;
    sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size= 8;
    sp->top = -1;
    sp->arr = (int *)malloc(sizeof(int)*sp->size);
    //following line of code are for checking if the array is empty or not
        if(isEmpty(sp)){
        printf("the array is empty \n");
    } 
    else {
        printf("the array is not empty\n");
    }
    //checking ends

    //pushing an element

    pushinstack(sp,value); // pushing an element into the stack 
    //following line of code are for checking if the array is empty or not

    int x;
    x = isEmpty(sp);
    printf("the value of x is %d\n",x);
    if(isEmpty(sp)){
        printf("the array is empty \n");
    } 
    else {
        printf("the array is not empty\n");
    }
    //checking ends

    //poping an element
    int t=popfromstack(sp);
    printf("the value poped is %d\n",t);
    //following line of code are for checking if the array is empty or not
        if(isEmpty(sp)){
        printf("the array is empty \n");
    } 
    else {
        printf("the array is not empty\n");
    }
    //checking ends
    return 0;
}