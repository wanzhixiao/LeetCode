#include<bits/stdc++.h>
using namespace std;

/*
236. 二叉树的最近公共祖先
如果递归函数有返回值，如何区分要搜索一条边，还是搜索整个树。
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==NULL || root==p || root==q){
           return root;
       }
       TreeNode *left = lowestCommonAncestor(root->left,p,q);
       TreeNode *right = lowestCommonAncestor(root->right,p,q);
       //如果left 和 right都不为空，说明此时root就是最近公共节点
       if(left && right){
           return root;
       }
       //如果left为空，right不为空，就返回right
       if(right && !left){
           return right;
       }
       if(!right && left){
           return left;
       }
       return NULL;
    }
};

int main(){

    return 0;
}