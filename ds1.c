// #include<bits/stdc++.h>
// using namespace std;
#include<stdio.h>
#include<stdlib.h>
  
int main() 
{  
    int n,t;
    printf("Enter the size of the array \n");
    scanf("%d",&n);
    int *A = (int*)malloc(sizeof(int)*n);
    printf("enter the number to be inserted at the middle index \n");
    scanf("%d",&t);

    A[(n-1)/2] = t;

    for (int i = 0; i < n; i++)
    {
        printf("%d ",A[i]);

    }
    printf("\n");
    
    
    return 0;
  }
  //1001110001111010101001110
//   "1000011011000000111100110
//      "1010110111001101101000"

