#include<stdio.h>
#include<stdlib.h>

//inserting a key in th e best
//first one needs to check if its already present
//as bst dont have duplicate  entries
//and if not found insert beneath the previous node
struct node{
    int data;
    struct node* right;
    struct node* left;
};
struct node* createNode(int data){ // to create a node (the node is not linked to any other node for now)
    struct node * n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
    }
void inorder(struct node* root){ //left -> root-> right

    if (root!=NULL){
        
        inorder(root->left); //recursive function
        printf("the element is %d \n",root->data);
        inorder(root->right);
    }
}
void insert_bst(struct node *root,int key,int *level1){
    struct node *ptr = createNode(key);
    int flag =0;// if the element is found if cant insert it in the bst
    struct node * prev;
    prev =NULL;
    while(root!=NULL){
    prev = root;
    *level1 = *level1+1;
    if (key == root->data){
        // return root;
        flag++;
        break;

    }
    else if (key< root->data){
        root = root->left;
    }
    else if (key> root->data){
    root = root->right;
            }
    }
    if (flag == 0){
    
    if (key < prev->data){
        prev->left = ptr;
    }
    else if (key > (prev->data)){
        prev->right = ptr ;
    }

    }
    else{
        printf("key ' %d ' already present\n",key);
    }
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
    insert_bst(p,1,ptr);//second entry is the key to be inserted //passing level throu call by reference
    insert_bst(p,4,ptr); //passing level throu call by reference
    insert_bst(p,12,ptr); 
    printf("After insertion op :- \n");
    inorder(p);

    return 0;
}  