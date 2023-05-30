#include<bits/stdc++.h>
using namespace std;

/*
404. 左叶子之和:给定二叉树的根节点 root ，返回所有左叶子之和。
                3
               / \
              9  20
                 / \
                15  7
思路1：先序遍历，用一个标记标记当前节点是否是左节点，如果是左节点，并且左右子节点都为空，则为左叶子节点
思路2：层序遍历，左子树的左右子树都为空，则为左叶子节点
*/
class Solution {
public:
    int ans = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr){
            return ans;
        }
        queue<TreeNode*> q;
        q.emplace(root);
        while(!q.empty()){
            size_t size = q.size();
            for(int i=0; i<size; i++){
                root = q.front();
                q.pop();
                if(root->left){
                    if(root->left->left==nullptr && root->left->right==nullptr){
                        ans += root->left->val;
                    }
                    q.emplace(root->left);
                }
                if(root->right){
                    q.emplace(root->right);
                }
            }
        }
        return ans; 
    }
    void helper(TreeNode *root, bool isLeft){
        if(root==nullptr){
            return;
        }
        if(isLeft && root->left == nullptr && root->right==nullptr){
            ans += root->val;
            return;
        }
        helper(root->left,true);
        helper(root->right,false);
    }
};

int main(){
    return 0;
}