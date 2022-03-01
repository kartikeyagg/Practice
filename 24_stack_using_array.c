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

int main()
{struct stack *s;
s = (struct stack *)malloc(sizeof(struct stack));
s->size =  80;//2 for check it is full
s->top = -1;
s->arr = (int *)malloc((s->size)*sizeof(int));
//it is very important to check whether a stack is empty
// or full depending upon if you are using push or pop
s->arr[0] =7;
s->top++;
s->arr[1] =3;
s->top++;
int x;
x = isEmpty(s);
printf("the value of x is %d\n",x);
if(isEmpty(s)){
    printf("the array is empty \n");
} 
else {
    printf("the array is not empty\n");
}
if (isFull(s)){
    printf("the stack is full\n");
}
else{
    printf("the stack is not full\n");
}
    return 0;
}