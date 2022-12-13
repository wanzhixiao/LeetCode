#include<bits/stdc++.h>
using namespace std;
/*
平衡二叉树
    根节点的左子树高度与右子树高度的绝对值之差不超过1，并且左、右子树都是平衡二叉树
                        1                               1
                       / \                             / \
                      2   3                           2   3
                     / \ /                           / \
                    4  5 6                          4   5
                                                   /
                                                  6
    思路1：求左右子树的高度，高度是指从下往上的层数，叶子节点的高度是1，根节点高度最大
    使用后序遍历，判断两棵子树是否是平衡二叉树，
            若左子树和右子树都是平衡二叉树，则返回子树的高度max(height_left,height_right)，否返回-1
    思路2：根节点的左子树高度-右子树高度绝对值之差不超过-1，并且左右子树都是平衡二叉树
    (abs(helper(root->left)-helper(root->right))<=1)&&isBalanced(root->left)&&isBalanced(root->right);

*/
struct TreeNode{
    TreeNode *left, *right;
    int val;
    TreeNode(int val):val(val),left(NULL),right(NULL){}
    TreeNode(){}
    ~TreeNode(){
    }
    
    int getheight(TreeNode *root){
        if(root==nullptr){
            return 0;
        }
        int height_left = getheight(root->left);
        if(height_left==-1){
            return -1;
        }
        int height_right = getheight(root->right);
        if(height_right==-1){
            return -1;
        }
        if(abs(height_left - height_right)<=1){
            return max(height_left,height_right)+1;
        }
        return -1; 
    }
};

int main(){
    int arr[] = {1,2,3,4,5};
    vector<int> result;
    TreeNode *root = new TreeNode(arr[0]);
    root->left = new TreeNode(arr[1]);
    root->right = new TreeNode(arr[2]);
    root->left->left = new TreeNode(arr[3]);
    root->left->left->left = new TreeNode(arr[4]);
   
    cout <<  root->getheight(root) << endl;

    delete root->left;
    root->left = NULL;
    delete root->right;
    root->right = NULL;
    delete root;  
    root = NULL;
    return 0;
}