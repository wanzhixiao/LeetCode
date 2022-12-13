#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    TreeNode *left, *right;
    int val;
    TreeNode(int val):val(val),left(NULL),right(NULL){}
    TreeNode(){}
    ~TreeNode(){
    }

    int countNodes(TreeNode *root){
        if(root==nullptr){
            return 0;
        }
        return helper(root);
    }
    int helper(TreeNode *root){
        if(root==nullptr){
            return 0;
        }
        int leftDepth = 0, rightDepth = 0;
        TreeNode *leftNode=root->left, *rightNode=root->right;
        
        for(;leftNode;leftNode=leftNode->left,leftDepth++){}
        for(;rightNode;rightNode=rightNode->right,rightDepth++){}

        if(leftDepth==rightDepth){
            return (2<<leftDepth)-1;
        }
        return helper(root->left) + helper(root->right)+1;
    }
};

int main()
{
    int arr[] = {1,2,3};
    vector<int> result;
    TreeNode *root = new TreeNode(arr[0]);
    root->left = new TreeNode(arr[1]);
    root->right = new TreeNode(arr[2]);
   
    cout <<  root->countNodes(root) << endl;

    delete root->left;
    root->left = NULL;
    delete root->right;
    root->right = NULL;
    delete root;  
    root = NULL;
    return 0;
}