#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 TreeNode* createnode(int val2){

    TreeNode* t1 = (TreeNode*)malloc(sizeof(struct TreeNode));
    t1->val = val2;
    t1->left = NULL;
    t1->right = NULL;
    return t1;

}

int idx ;

int searchp(vector<int> &A,int start,int end,int val2){
    for(int i=start;i<=end;i++){
        if(A[i] == val2){
            return i;
        }
    }
return -1;
}
TreeNode* treebuild(vector<int> &A, vector<int> &B,int start,int end){
    if(start>end){
        return NULL;
    }
    int val2  = B[idx],i2;

    TreeNode* p1 = createnode(val2);
    idx--;
    
    i2  = searchp(A,start,end,val2);
    if(i2 ==-1){
        return NULL;
    }
    if(start==end){
        return p1;
    }
    p1->right = treebuild(A,B,i2+1,end);
    p1->left = treebuild(A,B,start,i2-1);

    return p1;

}
void inorder1(struct TreeNode* root){ //left -> root-> right

    if (root!=NULL){
        
        inorder1(root->left); //recursive function
        printf("the element is %d \n",root->val);
        inorder1(root->right);
    }
}
int main() 
{
    vector<int> inorder={2,1,3};
    vector<int> postorder={2,3,1};
    idx= inorder.size()-1;
    struct TreeNode* t1 = treebuild(inorder,postorder,0,postorder.size()-1);
    // inorder(t1);
    cout<<"Displaying\n";
    inorder1(t1);
    cout<<endl;
    return 0;
  }