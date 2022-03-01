//interesting
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
char popfromstack(struct stack *s){
    char val ;
    if (isEmpty(s)){
        printf("the stack is empty");
        return NULL;
    }
    else {
        val = s->arr[s->top];
        // free(s->arr[s->top]);
        s->top--;
        return val;
        }
}
int match(char a,char b){
    if (a== '(' && b== ')'){
        return 1;
    }
        if (a== '{' && b== '}' ){ // i wasted a lot of time as i put " instead of ' in the comparison
        return 1; // and the warning thrown was :-can not compare a pointer with an integer 
    }
        if (a== '[' && b== ']'){
        return 1;
    }
    return 0;


}
int parenthesismatch(char *exp)
{
    struct stack *sp;
    char ch;
    sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 80; //2 for check it is full
    sp->top = -1;
    sp->arr = (char *)malloc((sp->size) * sizeof(char));

    for (int i=0;exp[i]!='\0';i++){
        printf("the current charc is %c\n",exp[i]);
        if (exp[i]=='('||exp[i]=='['||exp[i]=='{'){

            // sp->top++;
            // sp->arr[sp->top]==
            pushinstack(sp,exp[i]);
            printf("the pushed element is %c\n",exp[i]);
        }
        else if (exp[i]==')'||exp[i]==']'||exp[i]=='}'){
            if(isEmpty(sp)){
                printf("the exp is not stable 3 \n");

                return  0;
            }
            else{

                ch =popfromstack(sp);
                printf("the poped element is %c\n",ch);

                

                if(!match(ch,exp[i])){
                printf("the exp is not stable mate \n");

                    return 0;
                }
            }
        }


    }
    printf("the string is '%s'\n",sp->arr);

    if (isEmpty(sp)){
        printf("the exp is stable 1 \n");

        return 1;
    }
    else {
        printf("the exp is not stable 2 \n");
        return 0;
    }
}
int main()
{ char s[100];
int a;
  printf("enter the value of the expression\n");
//   gets(s);
scanf("%s",s);
  a=parenthesismatch(s);
    return 0;
}