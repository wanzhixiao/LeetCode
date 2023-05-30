#include<bits/stdc++.h>

/*
最近公共祖先的定义：
    对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先
    且 x 的深度尽可能大（一个节点也可以是它自己的祖先）

*/

struct TreeNode{
    TreeNode *left, *right;
    int val;
    TreeNode(int val):val(val),left(NULL),right(NULL){}
    TreeNode(){}
    ~TreeNode(){
    }
}

/*

1.搜索整棵树的写法
left = 递归函数(root->left);
right = 递归函数(root->right);
left与right的逻辑处理;

2.搜索一边的写法
if (递归函数(root->left)) return ;
if (递归函数(root->right)) return ;
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return root;
        }
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
};

int main(){

    return 0;
}