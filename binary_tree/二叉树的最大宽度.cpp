#include<iostream>
#include<vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int ans = 1;
    typedef unsigned long long ULL;
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<ULL> vec;
        dfs(root, 0, 0, vec);
        return ans;
    }
    // 每个节点的编号减去第一个节点编号 
    void dfs(TreeNode *root,int depth, unsigned long long index, vector<unsigned long long> &vec) {
        if (root == NULL) {
            return;
        }   
        if (depth == vec.size()) {
            vec.push_back(index);
        }
        
        // 前序，求解答案 
        ans = max(ans, index - vec[depth]+1);
        // 遍历左右子树 
        dfs(root->left, depth+1, 2*index+1, vec);
        dfs(root->right, depth+1, 2*index+2, vec);
    }

    int widthOfBinaryTree1(TreeNode* root) {
        int res = 0;
        queue<pair<TreeNode *, long long>> q;
        if (root) q.emplace(root, 0);
        while (!q.empty()) {
            long long first_offset = q.front().second;
            res = max(res, (int)(q.back().second - first_offset + 1));
            for (int size = q.size(), i = 0; i < size; i++) {
                auto [node, offset] = q.front(); q.pop();
                offset -= first_offset; //统一减去行首元素偏移，避免下面*2超出long long
                if (node->left) q.emplace(node->left, offset * 2);
                if (node->right) q.emplace(node->right, offset * 2 + 1);
            }
        }
        return res;
    }	
};

/*
相似题目：二叉树的垂序遍历， 利用节点的行（row), 列（col）编号，对应本题的depth, index 
*/ 

int main() {
	
	
	return 0;
}
