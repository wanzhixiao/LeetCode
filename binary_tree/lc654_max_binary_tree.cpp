#include<bits/stdc++.h>
using namespace std;

/*
654. 最大二叉树
给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:
1.创建一个根节点，其值为 nums 中的最大值。
2.递归地在最大值 左边 的 子数组前缀上 构建左子树。
3.递归地在最大值 右边 的 子数组后缀上 构建右子树。
输入：nums = [3,2,1,6,0,5]
输出：[6,3,5,null,2,0,null,null,1]
                6 -> [3,2,1] -> [3], [2,1] -> [2] ->[1]
                  -> [0,5] -> [5] -> [0]
思路1：
    将数组按照最大数分成左右两个部分，使用先序遍历，递归地构造最大二叉树
思路2：
    单调栈：https://leetcode.cn/problems/maximum-binary-tree/solution/zhua-wa-mou-si-by-muse-77-myd7/
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }

    TreeNode* helper(vector<int>& nums,int left,int right){
        //递归终止条件
        if(left > right){
            return NULL;
        }
        //找最大的数
        int max_val = INT_MIN, max_index = left;
        size_t size = nums.size();
        for(int i=left; i<=right; i++){
            if(nums[i]>max_val){
                max_val = nums[i];
                max_index = i;
            }
        }
        //构建新节点
        TreeNode *root = new TreeNode(max_val);
        root->left = helper(nums,left,max_index-1);
        root->right = helper(nums,max_index+1,right);
        return root;
    }

    TreeNode* constructMaximumBinaryTree1(vector<int> &nums){
        //nums = [3,2,1,6,0,5]
        if(nums.size() == 0){
            return nullptr;
        }
        stack<TreeNode*> stk;
        stk.emplace(new TreeNode(nums[0]));

        size_t size = nums.size();
        for(int i=1; i<size; i++){
            TreeNode *root = stk.top();
            TreeNode *p = new TreeNode(nums[i]);
            if(root->val > nums[i]){
                root->right = p;
                stk.emplace(p);
            }
            else
            {   
                p->left = root;
                stk.pop();
                while(!stk.empty()){
                    root = stk.top();
                    if(root->val > p->val){
                        root->right = p;
                        break;
                    }
                    else{
                        p->left = root;
                        stk.pop();
                    }
                }
                stk.push(p);
            }
        }
        TreeNode *p;
        while(!stk.empty()){
            p = stk.top();
            stk.pop();
        }
        return p;
    }

    void traverse(TreeNode *root){
        if(root == nullptr){
            return;
        }
        cout << root->val << endl;
        traverse(root->left);
        traverse(root->right);
    }
};

int main(){
    vector<int> nums={3,2,1,6,0,5};
    Solution s;
    TreeNode *root = s.constructMaximumBinaryTree1(nums);
    s.traverse(root);
    return 0;
}