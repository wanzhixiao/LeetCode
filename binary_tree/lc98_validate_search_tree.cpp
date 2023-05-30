#include<bits/stdc++.h>
using namespace std;
/*
lc98: 验证二叉搜索树
思路1：
函数参数：   isValidBST(TreeNode *root, long long lowe, long long upper);
    设置上界和下界，
递归终止条件：
    如果节点为空，则为一棵合理的二叉搜索树
    if(root==nullptr){
        return true;
    }
单层逻辑
    如果下界 >=  root->val , 返回false
    如果上界 <= root->val, 返回false
    递归验证左子树 isValidBST(root->left,lower, root->val);
    递归验证右子树 isValidBST(root->right,root->val,upper);
返回值
    左子树为二叉搜索树 &&  右子树为二叉搜索树

思路2：
函数参数: isValidBST(TreeNode *root);
递归终止条件：
    if(root==nullptr){
        return true;
    }
单层逻辑
    遍历左子树
    通过设置pre指针，使用中序遍历，判断pre->val >= root->val, 是则返回false, 否则pre = root; 
    遍历右子树
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return traverse(root,LONG_MIN,LONG_MAX);
    }

    bool traverse(TreeNode *root,long long lower, long long upper){
        if(root==nullptr){
            return true;
        }
        if(lower != LONG_MIN && lower >= root->val){
            return false;
        }
        if(upper != LONG_MAX && upper <= root->val){
            return false;
        }
        if(!traverse(root->left,lower,root->val)){
            return false;
        }
        if(!traverse(root->right,root->val,upper)){
            return false;
        }
        return true;
    }  

    TreeNode *pre = NULL;
    bool isValidBST2(TreeNode *root){
        if(root==NULL){
            return true;
        }
        bool left = isValidBST2(root->left);
        if(pre != nullptr && pre->val >= root->val){
            return false;
        }
        pre = root;
        bool right = isValidBST2(root->right);
        return left && right;
    }
};

int main(){

    return 0;
}