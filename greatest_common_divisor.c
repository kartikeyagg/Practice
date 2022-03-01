#include<stdio.h>
#include<stdlib.h>
int gcd(int a, int b){ int t;
   while(1){
       if (a==b){
           return a;
       }
       else if (a>b){
           t = a%b;
           if (t==0){
               return b;
           }
           a = t;
       }
       else{
           t = b%a;
           if (t==0){
               return a;
           }
           b = t;
       }
   } 
}
int main(){
    printf("Enter the two numbers to find greatest common divider of\n");
    int a,b,g;
    scanf("%d",&a);
    fflush(stdin);
    scanf("%d",&b);
    g= gcd(a,b);
    printf("The greatest common diviser is %d\n",g);
    return 0;
}