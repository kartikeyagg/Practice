#include<stdio.h>
#include<stdlib.h>
// important
// the program aims to delete a node present in a binary search tree;

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
struct node* inorderpredeceser(struct node* root){
    //  works on pricipal that the inorder predesecor is 
    // right most node of the left subtree;
    root  = root->left;
    while(root->right !=NULL){
        root = root->right;
    }
    return root;

}
struct node* deletenode(struct node *root,int value){
    struct node * inpre;
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
     // searching starts here
    if(value<(root->data)){
        root->left=deletenode(root->left,value);
    }
    else if(value>(root->data)){
        root->right=deletenode(root->right,value);
    }
    // deletion stratergy when the node is found
    else{
        inpre  = inorderpredeceser(root);
        root->data  = inpre->data;
        root->left = deletenode(root->left,inpre ->data);        
    }
    return root;
}
struct node *searchiter(struct node *root,int key,int *level1){
    while(root!=NULL){
    *level1 = *level1+1;
    if (key == root->data){
        return root;
    }
    else if (key< root->data){
        root = root->left;
    }
    else if (key> root->data){
    root = root->right;
            }
    }
    return NULL;
}
struct node* createNode(int data){ // to create a node (the node is not linked to any other node for now)
    struct node * n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
    }
int maxValue(struct node* node)
{   
    // right most leaf is maximum
    struct node* current = node;
    while (current->right != NULL) 
        current = current->right;
      
    return (current->data);
}
int minValue(struct node* node)
{
struct node* current = node;
 // left most node is the minimum
 // or the first element in the inorder traversal
while (current->left != NULL)
{
    current = current->left;
}
return(current->data);
}
int main(){
    //constructing the root node - using function
    //binary tree building 
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(2);
    struct node *p4 = createNode(4);
    struct node *temp;

    p->left  = p1;
    p->right  =p2;
    p1->left  = p3;
    p1->right  = p4;
    int level1 =0;
    int *ptr ;
    ptr = &level1;
 
    //binary searchiter tree:-
     //     5
    //     / \ 
    //    3   6
    //   / \ 
    //  2   4
    // finished building the binary tree
    inorder(p);//just an traversal through the elements
    printf("deleting \n");
    temp  = deletenode(p,5); //  works for all 3 cases

    inorder(p);
    return 0;
}  
