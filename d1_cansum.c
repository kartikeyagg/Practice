#include<stdio.h>

int targetsum(int target, int *arr,int size){
    if (target == 0){
        return 1;

    }
    if (target < 0){
        return 0;
    }
    int remain;
    for (int i=0;i<size;i++){
        remain = target - arr[i];
        if( targetsum(remain, arr,size)){
            return 1;
        }
    }
    return 0;
}

int main(){
    int target_val = 7;
    int arr[] = {2,4}; //sorted arrays
    int size = 2;
    int arr1[] = {3,4,5,7};
    int size2 = 4;
    //for 1st array
    
    if(targetsum(target_val,arr,2)){
        printf("yes it can be reached\n");
    }
    else{
        printf("nope the target can't be reached\n");
    }
    //for 2nd array
    if(targetsum(target_val,arr1,4)){
        printf("yes the target can be reached\n");
    }
    else{
        printf("nope the target can't be reached\n");
    }


    return 0;
}