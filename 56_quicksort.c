#include<stdio.h>
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
int partition(int *a ,int low,int high){
        int pivot = a[low];
        int i = low +1;
        int j = high;
        do{
        while(a[i]<=pivot){
            i++;
            }
        while(a[j]>pivot){
            j--;
            }
        if(i<j){
            swap(&a[i],&a[j]);
            }
        }while(i<j);
        swap(&a[low],&a[j]);
        return j;
}
void quicksort(int *a ,int low,int high){
    int partitionindex;
    if(low<high){
    partitionindex = partition(a,low,high); // the element index returned will have the fix position now
    // printArray(a,11);
    quicksort(a,low,partitionindex -1);  //for the two array it has been bifurcated//applying recursion
    quicksort(a,partitionindex +1,high);
    } 
}
int main(){
    int a[] = {3,5,2,13,37,12,34,99,15,14,43,37};
    int size = sizeof(a)/sizeof(a[0]); //lenght of the array
    printf("the size of array is %d\n",size);
    printArray(a,size);
    quicksort(a,0,size-1);//applying quick sort
    printArray(a,size);
    return 0;
}