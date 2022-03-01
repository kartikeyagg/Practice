#include<stdio.h>
#include<stdlib.h>
//bubble sort is not adaptive but can be made adaptive
void printArray(int *a, int n){//prints the array
    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void swap(int *a , int*b)// used
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(int *a, int n){
    int flag = 0; // flag to make the bubble sort adaptive if the array is already sorted after every first loop resulting in O(n) instead of O(n*n)
    //and hence programe have to not go from the loop again and again
    for (int i =0;i<n-1;i++){
        flag = 0; // for number of passes after each one of this we get one more sorted element at the end of the array
        for (int j =0;j<n-1-i;j++){ // for comparisons in each  pass;
            if (a[j]>a[j+1]){
                swap(&a[j],&a[j+1]); //swap 
                flag++;
            }
        }
    printf("the value of flag is %d\n",flag);
    if (flag == 0){
        printf("Breaking \n"); // the bubble sort algorithm has been made adaptive with this
        break;
    }
    }
}
int main(){
    // int a[] ={21,54,65,7,23,9} ;
    int a[] ={1,3,4,2,5,6} ;
    int lenght  =6;
    printArray(a,lenght);
    bubble_sort(a,lenght);
    printArray(a,lenght);
    return 0;
}