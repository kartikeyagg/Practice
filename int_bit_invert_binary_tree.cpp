#include<stdio.h>
#include<stdlib.h>
// using namespace std;
struct node{
    int data;
    struct node* right;
    struct node* left;
};
void inorder(struct node* root){ //left -> root-> right

    if (root!=NULL){
        
        inorder(root->left); //recursive function
        printf("the element is %d \n",root->data);
        inorder(root->right);
    }
}
struct node* createNode(int data){ // to create a node (the node is not linked to any other node for now)
    struct node * n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
    }
void flip1(struct node* A){



    if(A==NULL){return ;}

    struct node* t = A;

    {flip1(t->left);
    flip1(t->right);}
    
    struct node* temp;
    temp = A->left;
    A->left=A->right;
    A->right = A->left;

    
    return ;

}    
int main(){
    //constructing the root node - using function
    //binary tree building 
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);
    struct node *p5 = createNode(7);
    struct node *p6 = createNode(8);

    p->left  = p1;
    p->right  =p2;
    p1->left  = p3;
    p1->right  = p4;
    p2->left = p5;
    p2-> right = p6;
    // this binary tree looks like this:-
    //      4
    //     / \ 
    //    1   6(7,8)
    //   / \ 
    //  5   2
    // finished building the binary tree
    inorder(p);

    flip1(p);

    printf("finished flip \n");
    
    inorder(p);

    return 0;
}
//137 50 2 19 54 26 24 60 9 6 41 36 -1 48 34 47 -1 -1 5 43 27 56 45 14 59 53 -1 -1 46 51 -1 -1 13 67 39 -1 64 58 1 -1 44 10 7 28 -1 -1 49 25 3 57 -1 29 -1 -1 -1 62 -1 17 20 -1 31 18 40 -1 65 52 -1 -1 68 30 21 -1 -1 35 -1 23 -1 -1 -1 -1 -1 -1 -1 -1 61 -1 15 12 -1 -1 -1 8 63 4 -1 -1 -1 -1 11 -1 -1 -1 -1 22 -1 32 -1 -1 -1 -1 -1 16 38 55 42 -1 37 -1 33 66 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1