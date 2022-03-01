#include<stdio.h>
#include<stdlib.h>
void fibonacci(float a,float *arr){
    int c = a;
    for(int i =2;i<c;i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
//O{n} time complexity
}
int main(){
    float a;
    float *b;
    printf("Enter the number to find fibonacci of\n");
    scanf("%f",&a);
    b = (float *)malloc(sizeof(float)*a);
    b[0] = b[1] =1;
    fibonacci(a,b);
    int c = a;
    printf("the fibonacci of %f (given number) is %f\n",a,b[c-1]);
    printf("the fibonacci of %f (given number) is %f\n",a,b[c-2]);

} 