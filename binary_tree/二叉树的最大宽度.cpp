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
    // ÿ���ڵ�ı�ż�ȥ��һ���ڵ��� 
    void dfs(TreeNode *root,int depth, unsigned long long index, vector<unsigned long long> &vec) {
        if (root == NULL) {
            return;
        }   
        if (depth == vec.size()) {
            vec.push_back(index);
        }
        
        // ǰ������ 
        ans = max(ans, index - vec[depth]+1);
        // ������������ 
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
                offset -= first_offset; //ͳһ��ȥ����Ԫ��ƫ�ƣ���������*2����long long
                if (node->left) q.emplace(node->left, offset * 2);
                if (node->right) q.emplace(node->right, offset * 2 + 1);
            }
        }
        return res;
    }	
};

/*
������Ŀ���������Ĵ�������� ���ýڵ���У�row), �У�col����ţ���Ӧ�����depth, index 
*/ 

int main() {
	
	
	return 0;
}
