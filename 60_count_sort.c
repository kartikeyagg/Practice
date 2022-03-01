#include<stdio.h>
#include<stdlib.h>
void printArray(int *a, int n){//prints the array
    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void swap(int *a , int*b)// used for swaping with call by referernce
{   int temp = *a;
    *a = *b;
    *b = temp;
}
void countsort(int *a,int n){
    int max = -100000;
    for(int i = 0;i<n;i++){ // for loop to calculate the maximum value
        if (a[i]>max){
            max = a[i];
        }  
    }
    int *b = (int *)calloc(max+1,sizeof(int));//dynamically allocating the memory as b[max] doesn't work
    // now as we used calloc so every entry equals zero in the b
    for(int j =0;j<n;j++){
        b[a[j]]++; //increaments the same index in b as the value found in a during tranversing

        }
    int t =0;
    for (int k=0;k<=max;k++){ //entering in a[] again
        while(b[k]!=0){ //depending upon the value contained by the element
            a[t] = k;
            b[k]--; 
            t++;
        }
    }
}
int main(){
    int a[] = {3,5,2,13,37,12,34,79,15,14,43,1};
    int size = sizeof(a)/sizeof(a[0]); //lenght of the array
    printf("the size of array is %d\n",size);
    printArray(a,size);
    countsort(a,size);//applying count sort
    printArray(a,size);
    return 0;
}