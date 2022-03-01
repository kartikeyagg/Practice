#include<stdio.h>
#include<stdlib.h>

// searching through the bst(binary search tree) using recursion

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
struct node *search(struct node *root,int key,int *level1){

    *level1+=1;
    printf("the value of level is %d \n",*level1); // the code also tells the level at which the element is present
    if (root == NULL){
        return NULL;
    }
    if (root->data == key){
        return root;
    }
    else if (root->data > key){
        return search(root ->left,key,level1);
        
    }
    else{
         
        return search(root->right,key,level1);
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
    int level1 =0;
    int *ptr ;
    ptr = &level1;
 
    //binary search tree:-
     //     5
    //     / \ 
    //    3   6
    //   / \ 
    //  2   4
    // finished building the binary tree
    inorder(p);//just an traversal through the elements
    struct node *t =search(p,2,ptr); //passing level throu call by reference
    if (t == NULL){
        printf("not found \n");
    }
    else{
    printf("the searched element is %d\n",t->data);
    printf("At the level %d \n", level1); 
    }
    return 0;
}  