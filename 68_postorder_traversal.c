#include<stdio.h>
#include<stdlib.h>
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
int main(){
    //constructing the root node - using function
    //binary tree building 
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);

    p->left  = p1;
    p->right  =p2;
    p1->left  = p3;
    p1->right  = p4;
    // this binary tree looks like this:-
    //      4
    //     / \ 
    //    1   6
    //   / \ 
    //  5   2
    // finished building the binary tree
    inorder(p);
    return 0;
}