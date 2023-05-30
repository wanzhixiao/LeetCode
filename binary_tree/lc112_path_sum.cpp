#include<bits/stdc++.h>
using namespace std;
/*
    112. 路径总和:给定一棵树root和表示目标的整数targetSum,判断该树中是否存在 根节点到叶子节点的路径，
    这条路径上所有节点值相加等于目标和 targetSum. 例如：targetSum = 6, 路径[3,1,2]
                                                3
                                               / \
                                              1   5
                                             / \ / \
                                            0  2 4  6
    思路：回溯法
    回溯思想的核心在于回退到上一层。先深度遍历，当不满足条件时，回退到上一层；例如，遍历出一条路径3->1->0, 不满足条件；则由0回退到节点1
    深度遍历形成路径，并记录路径上的节点的值。找到一条路径，判断路径上节点的总和是否为targetSum。否则，回退到上一层节点
*/
class Solution {
public:
    bool flag = false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return flag;
        }
        vector<int> path;
        helper(root,path,targetSum);
        return flag;
    }
    //回溯
    void helper(TreeNode *root, vector<int> &path, int target){
        path.emplace_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            int sum = 0;
            size_t size = path.size();
            for(int i=0;i<size;i++){
                sum = sum + path[i];
            }
            if(sum == target){
                flag = true;
            }
            return;
        }
        if(root->left){
            helper(root->left,path,target);
            path.pop_back();
        }
        if(root->right){
            helper(root->right,path,target);
            path.pop_back();
        }
    }


    //回溯+剪枝
    bool hasPathSum2(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        vector<int> path;
        return helper(root,path,targetSum);
    }

    bool helper2(TreeNode *root, vector<int> &path, int target){
        path.emplace_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            int sum = 0;
            size_t size = path.size();
            for(int i=0;i<size;i++){
                sum = sum + path[i];
            }
            if(sum == target){
                return true;
            }
            return false;
        }
        bool res = false;
        if(root->left){
            res = helper(root->left,path,target);
            path.pop_back();
            if(res){
                return true;
            }
        }
        
        if(root->right){
            res = helper(root->right,path,target);
            path.pop_back();
            if(res){
                return true;
            }
        }
        return false;
    }

    //广度优先遍历
    bool hasPathSum1(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        stack<pair<TreeNode*,int>> q;
        q.push(pair<TreeNode*,int>(root,root->val));
        while(!q.empty()){
            pair<TreeNode*,int> node = q.top();
            q.pop();
            if(!node.first->left && !node.first->right && target == node.second){
                return true;
            }
            if(node.first->right){
                q.push(pair<TreeNode*,int>(node.first->right,node.second+node.first->right->val));
            }
            if(node.first->left){
                q.push(pair<TreeNode*,int>(node.first->left,node.second+node.first->left->val));
            }

        }
        return false;
    }
};

int main(){

    return 0;
}