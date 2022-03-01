//insertion sort programe
#include<stdio.h>
#include<stdlib.h>

void printArray(int *a, int n){//prints the array
    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void swap(int *a , int*b)//not used
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insetionSort(int *a, int n){
    //loop for passes
    int key, j;
for (int i =1; i<n;i++){
    key = a[i];
    j = i-1;
    //loop for each pass(comparisons from the array at the left)
    while(j>=0 && a[j]>key){ 
        a[j+1] = a[j];
        a[j] = key;
        j--;
    }
       }
   }
int main(){
    int a[] = {12,54,65,7,23,9};
    int lenght = 6;
    printArray(a,lenght);
    insetionSort(a,lenght);
    printArray(a,lenght);
    return 0;
}