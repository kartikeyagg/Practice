#include<stdio.h>
//binary search
int binsearch(int arr[],int size,int element){
    int low=0,high=size-1,mid;
    
    int a=1;
    //it keeps searching until low and high converges
    while(low<=high){
        mid =(low+high)/2;
        if (arr[mid]==element){

return mid;

        }
        if (arr[mid]<element)
        {
            low=mid+1;
        }
        else{
            high =mid-1;
        }       

    }    
return -1;
}

int main()
{int arr[32] = {2,5,7,12,16,23,26,34};//sorted array
int flag=0,num,index,size;
printf("enter the number to be searched \n");
scanf("%d",&num);
size=8;

flag=binsearch(arr,size,num);
//linear search
if(flag==-1){
    printf("number not found");
}
else{
printf("the number %d is at %d index ",num,flag);
}



    return 0;
}