#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0 || inorder.size() == 0) {
			return NULL;
		}	
		TreeNode *root = new TreeNode(preorder[0]);
		int i = 0;
		for ( ; i < inorder.size(); i++) {
			if (preorder[0] == inorder[i]) {
				break;
			}
		}
		vector<int> leftPre(preorder.begin()+1,preorder.begin()+i+1);
		vector<int> rightPre(preorder.begin()+i+1,preorder.end());
		vector<int> leftIn(inorder.begin(),inorder.begin()+i);
		vector<int> rightIn(inorder.begin()+i+1,inorder.end());
		root->left = buildTree(leftPre,leftIn);
		root->right = buildTree(rightPre,rightIn);
		return root;
    }
};

void preOrderTraverse(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	stack<TreeNode*> stk;
	stk.push(root);
	vector<int> ans;
	
	while (!stk.empty()) {
		root = stk.top();
		stk.pop();
		if (root) {
			if (root->right) {
				stk.push(root->right);
			}
			if (root->left) {
				stk.push(root->left);
			}
			stk.push(root);
			stk.push(NULL);
		} else {
			root = stk.top();
			ans.push_back(root->val);
			if (!stk.empty()) {
				stk.pop();
			}
		}
	}
	for (int &x : ans) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {
	vector<int> nums = {3,9,20,-1,-1,15,7};
	int n = nums.size();
	
	// 1.构建二叉树 
	vector<TreeNode*> tree(n,NULL);
	tree[0] = new TreeNode(nums[0]);
	
	for (int i = 1; i < n; i++) {
		if (nums[i] == -1) {
			continue;
		}
		int parent = (i%2) ? i/2 : i/2-1; 
		tree[i] = new TreeNode(nums[i]);
		if (i % 2) {
			tree[parent]->left = tree[i];
		} else {
			tree[parent]->right = tree[i];
		}
	}
	// 2.二叉树的先序遍历 
	preOrderTraverse(tree[0]);
	
	cout << "====rebuild====" << endl;
	// 3.重建二叉树 
	vector<int> preorder = {3,9,20,15,7};
	vector<int> inorder = {9,3,15,20,7};
	
	Solution s;
	TreeNode *root = s.buildTree(preorder, inorder);
	preOrderTraverse(root);
	return 0;
}
