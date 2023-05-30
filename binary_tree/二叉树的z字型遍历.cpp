#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int val) : val(val), left(NULL), right(NULL) {
	} 
}; 


// 层序遍历 
TreeNode *zTraverse(TreeNode *root) {
	if (root == NULL) {
		return root;
	}
	
	queue<TreeNode*> q;
	q.push(root);
	int level = 0;
	while (!q.empty()) {
		int size = q.size();
		
		for (int i = 0; i < size; i++) {
			root = q.front();
//			vec.emplace_back(root);
			q.pop();
			cout << level << endl;
			if (level%2 == 0) {
				int val = root->left->val;			//访问空指针 
				root->left->val = root->right->val;
				root->right->val = val; 
			}
			
			if (root->left) {
				q.push(root->left); 
			} 
			if (root->right) {
				q.push(root->right);
			}
		} 	
//		if (level & 1) {
//			for (int i = 0, n = vec.size(); i < n/2; i++) {
//				TreeNode *p = vec[i];
//				vec[i] = vec[n-i-1];						// 1 2  4 5
//				vec[n-i-1] = p;
//				cout << vec[i]->val << " " << vec[n-i-1]->val << endl;
//			}
//		}
		level++;
	} 
	return root;
}

class Solution{ 
// 深度优先搜索
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        dfs(root, 0);
        return result;
    }
    void dfs(TreeNode *root, int depth) {
        if (root==NULL) {
            return;
        }
        // 如果深度为结果的大小（depth从0开始），需要重新开辟一个数组存放新层的元素， 
        if (depth == result.size()) {
            result.push_back(vector<int>());
        }
        //偶数层不需要反转 
        if (depth % 2 == 0) {
            result[depth].push_back(root->val);
        } else {
            result[depth].insert(result[depth].begin(), root->val);
        }
        dfs(root->left, depth+1);
        dfs(root->right, depth+1);
    }
};

void traverse(TreeNode *root) {
	if (root) {
		cout << root->val << " ";
		traverse(root->left);
		traverse(root->right);
	}
}

void dfs(TreeNode *left, TreeNode *right, int level) {
	if (left == NULL) {
		return;
	}
	if (level & 1) {
		int val = left->val;
		left->val = right->val;
		right->val = val;
	}
	dfs(left->left, right->right, level+1);
	dfs(left->right, right->left, level+1);
	return;
}

TreeNode* reverseOddLevels(TreeNode* root) {
	if (root == NULL) {
		return root;
	} 
	dfs(root->left, root->right, 1);
	return root;
} 

int main() {
	int n = 7;
	vector<int> nums = {1,2,3,4,5,6,7}; 
	vector<TreeNode*> tree(n,NULL);
	tree[0] = new TreeNode(nums[0]);
	
	for (int i = 1; i < n; i++) {
		if (nums[i] == -1) {
			continue;
		}
		TreeNode *node = new TreeNode(nums[i]);
		tree[i] = node;
		if (i & 1) {
			tree[i/2]->left = node;
		} else {
			tree[i/2-1]->right = node;
		}
	}
	
	traverse(tree[0]);
	cout << endl; 
//	TreeNode *root = zTraverse(tree[0]);
	TreeNode *root = reverseOddLevels(tree[0]);
	traverse(tree[0]);
	cout << endl;
	
	return 0;
}

/*
				1
			   / \
			  2  3
			/ \ / \
		   4  5 6 7
如果当前是偶数层: 记录同一层的所有节点，进行奇数层节点交换 
				1
			   / \
			  3  2
			/ \ / \
		   4  5 6 7



*/
