#include<stdio.h>
#include<stdlib.h>
//given a grid of m x n order and the programme needs 
// to return the total number of ways one can travel from
//top left to bottom right
//given that it can travel only right or down(no up or left)
//for a single celled grid ways  =1 (not zero)
int gridtravel(int m, int n){ //time complexity  = O(2^(m+n)) not desired
    if (m==1&&n==1){ // duplicate tress occur in this recurssive tree which slow down the program

        return 1;
    }
    if (m==0 || n==0){
        return 0;
    }
    return gridtravel(m-1,n)+gridtravel(m,n-1);//this programe(function) was not able to calculate for the value 18 x 18 as it is too slow

}
int optimizedgridtravel(int x, int y,int *arr[]){ // we used memonization here
    int m =x-1;
    int n = y-1;
    if (arr[m][n]!=-1){
        printf("1 \n");
        return arr[m][n]; 
    }
    if (m==1 && n==1){ // duplicate tress occur in this recurssive tree which slow down the program
        arr[m][n] = 1;
        printf("2 \n");

        return 1;
    }
    if (m==0 || n==0){
        arr[m][n] = 0;
        printf("3 \n");

        return 0;
    }
    arr[m][n] =optimizedgridtravel(m-1,n,arr)+optimizedgridtravel(m,n-1,arr);
        printf("4 \n");


    return  arr[m][n];

} // not complete 
void printarr(int m ,int n, int *arr[]){
      for (int i =0;i<m;i++){
        for(int j =0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    

}
int main(){
    int m,n;
    printf("enter the value of order of the grid\n");
    scanf("%d",&m);
    fflush(stdin);
    scanf("%d",&n);
    int ti = gridtravel(m,n); //simple recursion method
    printf("total numbers of ways one can travel the grid is %d \n",ti);
    //generating an dynamic 2d array
    //given m and n as no. of row and column respctively
    int *arr[m];
    for (int i= 0;i<m;i++){
        arr[i] = (int*)malloc(n*sizeof(int));
    }
    
    for (int i =0;i<m;i++){
        for(int j =0;j<n;j++){
            arr[i][j] = -1;
        }
    }
    int t = optimizedgridtravel(m,n,arr);
    printarr(m,n,arr);

    //arr is 2d array now and one can access its elements with
    // arr[i][j]
    return 0;
}