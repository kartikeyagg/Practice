#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//the stack consists of a string and not an array
struct stack
{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {

        return 1;
    }
    // no need for returning 0 from a else statement as
    // a int function by default return 0
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    // printf("%d and %d \n", ptr->top, ptr->size);
    if (ptr->top == (ptr->size) - 1)
    {

        return 1;
    }
    else
        return 0;
    // no need for returning 0 from a else statement as
    // a int function by default return 0
}
void pushinstack(struct stack* sp,char value){
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
int parenthesismatch(char *exp)
{
    struct stack *sp;
    sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 80; //2 for check it is full
    sp->top = -1;
    sp->arr = (char *)malloc((sp->size) * sizeof(char));

    for (int i=0;exp[i]!='\0';i++){
        if (exp[i]=='('){

            // sp->top++;
            // sp->arr[sp->top]==
            pushinstack(sp,'(');
        }
        else if (exp[i]==')'){
            if(isEmpty(sp)){
                printf("the exp is not stable \n");
                return  0;
            }
            else{

                popfromstack(sp);
            }
        }


    }
    if (isEmpty(sp)){
        printf("the exp is stable \n");

        return 1;

    }
    else {
        printf("the exp is not stable \n");
        return 0;
    }
}

int main()
{ char s[100];
  printf("enter the value of the expression\n");
//   gets(s);
scanf("%s",s);
  parenthesismatch(s);
    return 0;
}