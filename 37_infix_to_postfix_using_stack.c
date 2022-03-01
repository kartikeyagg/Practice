#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
int size;
char *arr;
int top ;
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
   // printf("%d and %d \n",ptr->top,ptr->size);
    if (ptr->top == (ptr->size)-1){

        return 1;
    }
    else 
    return 0;
    // no need for returning 0 from a else statement as
    // a int function by default return 0
}
// function to push an element is the stack
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
        printf("the stack is empty1\n");
        
    }
    else {
        val = s->arr[s->top];
        // free(s->arr[s->top]);
        s->top--;
        return val;
        }
}
int check_prescedence(char a){

    if (a=='+' ||a=='-'){
        return 1;
    }
    else if (a=='/' ||a=='*'){
        return 2;
    }
    printf("invalid operator passed\n");
}

char * infixtopostfix1(struct stack *s,char * exp){
    char psch[100] ="";//post fix string to be returned by the function
    char *ptr = psch;//pointer which contains the first address of first char in string
    for(int i=0;exp[i]!='\0';i++){ 
        if ((exp[i])=='+'||(exp[i])=='-'||(exp[i])=='/'||(exp[i])=='*'){
            if (isEmpty(s)){
               // printf("the stack is empty2\n");
                pushinstack(s,exp[i]);
            }
            else{
            int t =check_prescedence(exp[i]);
            
            int top_prescedence = check_prescedence(s->arr[s->top]);
            if (top_prescedence<t){
                ;
            }
            else{
                do{
                char y = popfromstack(s);
                strncat(psch,&y,1);}while(!(isEmpty(s)) && check_prescedence(s->arr[s->top])>=t );
            }
                pushinstack(s,exp[i]);


        }}
        else{
            strncat(psch,&exp[i],1);
        }
    }
do{
                char y = popfromstack(s);
                strncat(psch,&y,1);}while(!(isEmpty(s)) );
//do while loop ends
printf("The postfix exp is :- '%s'\n",psch);
char yt ='t' ;
                return ptr ;

}
int main(){
    char ch[100] ;
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size=30;
    s->top = -1;
    s->arr = (char *)malloc(sizeof(s->size*(sizeof(char))));
    printf("Enter an valid expression\n");
    scanf("%s",ch);
    char *t= infixtopostfix1(s,ch);//string to store the result
    printf("the postfix expresion is :- '%s'\n",t);

    return 0;
}