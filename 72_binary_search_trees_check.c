#include<stdio.h>
#include<stdlib.h>
//condition of checking a binary search tree is that its inorder traversal gives an ascending array
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
int isbst(struct node* root){ //check if is a bst using inorder 
    static struct node * prev = NULL; //very very important
    if (root!=NULL){   
        if (!isbst(root->left)){
            return 0;
        }
        if (prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isbst(root->right);
        
    }
    else {
        return 1;
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
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(2);
    struct node *p4 = createNode(4);

    p->left  = p1;
    p->right  =p2;
    p1->left  = p3;
    p1->right  = p4;
 
    //binary search tree:-
     //     5
    //     / \ 
    //    3   6
    //   / \ 
    //  2   4
    // finished building the binary tree
    inorder(p);
    printf("value of isbst is %d\n",isbst(p));
    return 0;
}  