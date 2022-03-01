#include<stdio.h>

void printArray(int *a, int n){//prints the array
    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void swap(int *a , int*b)// used for swaping with call by referernce
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int *a, int n){
    int t = 100000;  //a large number for comparison
    int *min ;  //min pointer to store the address of t
    min = &t;
    for(int i=0;i<n-1;i++){ //loop for passes
        min = &t; //every time min should again point to the t otherwise it will store the value of minimum of previous array leading to discripencies
        for (int j=i;j<n;j++){
            if (a[j]<*min){   // loop for comparison
                min = &a[j];
            }
        }
        swap(min,&a[i]);
    }
}
int main(){
    int a[] = {31,5,20,15,42,2,26,7,12};
    int lenght  = 9;
    printf("The given array is :- \n");
    printArray(a,lenght);
    selection_sort(a,lenght);
    printf("The sorted array is :- \n");
    printArray(a,lenght);

    return 0;
}