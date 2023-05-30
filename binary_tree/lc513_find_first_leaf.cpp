#include<bits/stdc++.h>
using namespace std;

/*
 513. 找树左下角的值
 给定一个二叉树的根节点 root，请找出该二叉树的 最底层 最左边 节点的值。假设二叉树中至少有一个节点。
                            3
                           / \
                          1   5
                         / \ / \
                        0  2 4  6
    左下角的第一个数是0
                            3
                           / \
                          1   5
                           \ / \
                           2 4  6
    左下角的第一个数是2

思路1：层序遍历，用数组记录每层的节点，最深层的第一个叶点即为左下角的数
思路2：先序遍历，记录当前树的深度，最深层的第一个叶子节点即为左下角的数
*/
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = root->val;
        queue<TreeNode*> q;
        q.emplace(root);
        while(!q.empty()){
            size_t size = q.size();
            vector<int> vec;
            for(int i=0; i<size; i++){
                root = q.front();
                vec.emplace_back(root->val);
                q.pop();
                if(root->left){
                    q.emplace(root->left);
                }
                if(root->right){
                    q.emplace(root->right);
                }
            }
            if(vec.size()>0){
                ans = vec[0];
            }
        }
        return ans; 
    }

    //先序遍历
    int level = 0;
    int ans = 0;
    int findBottomLeftValue(TreeNode* root) {
        ans = root->val;
        helper(root,0);
        return ans; 
    }

    void helper(TreeNode *root, int depth){
        // level = level > depth ? level : depth;
        if(!root->left && !root->right){
            if(depth>level){
                ans = root->val;
                level = depth;
            }
            return;
        }
        if(root->left){
            helper(root->left,depth+1);
        }
        if(root->right){
            helper(root->right,depth+1);
        }
    }
};

int main(){

    return 0;
}