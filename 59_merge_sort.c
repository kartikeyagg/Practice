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
void merge(int *a, int mid, int low, int high){
    int i,j,k,b[100];
    i = k = low;
    j = mid +1;
    while(i<=mid&&j<=high){ //to insert the sortest element into b
        if (a[i]<a[j]){
            b[k] = a[i];
            i++;
            k++;   }
        else {
            b[k] = a[j];
            k++;
            j++;
        }}
        //inserting the left over elements into b
    while(i<=mid){
        b[k] = a[i];
        i++;
        k++;

    }
    //inserting the left over elements into b
    while(j<=high){
        b[k] = a[j];
        j++;
        k++; }
    
    //copying into a again
    for(int l = low;l<=high;l++){//as b also started entry from k = mid not from the zero index
        a[l] = b[l];
    }   
}
// high is ind
void mergesort(int *a,int low,int high){ //recursive programe for merging
    int mid;
    if (low<high){ // means atleast the array should cotain two elements
    mid = (low+high)/2; // gives an integer value only no .5
    mergesort(a,low,mid);   // again applying mergesort two bifurcated array
    mergesort(a,mid+1,high);
    merge(a,mid,low,high);//merging them both
}}
int main(){
     
    int a[] = {3,5,2,13,37,12,34,99,15,14,43,37};
    int size = sizeof(a)/sizeof(a[0]); //lenght of the array
    printf("the size of array is %d\n",size);
    printArray(a,size);
    mergesort(a,0,size-1);//applying merge sort
    printArray(a,size);
    return 0;
}