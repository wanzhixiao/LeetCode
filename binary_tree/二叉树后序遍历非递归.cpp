#include<iostream>
#include<vector>
#include<stack>
using namespace std;


struct TreeNode {
	TreeNode *left;
	TreeNode *right;
	int val;
	TreeNode(int x) : left(NULL),right(NULL),val(x) {}
};

void postOrderTraverse(TreeNode *root, vector<int> &ans) {
	if (root == NULL ){
		return;
	}
	stack<TreeNode*> stk;
	stk.push(root);
	while (!stk.empty()) {
		root = stk.top();
		stk.pop();
		if (root != NULL) {
			stk.push(root);
			stk.push(NULL);
			if (root->right) {
				stk.push(root->right);
			}
			if (root->left) {
				stk.push(root->left);
			}
		} 
		else {
			root = stk.top();
			stk.pop();
			ans.push_back(root->val);
		}
	}
}


/*
	1
   / \
   2  3
*/


int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	
	vector<int> ans;
	postOrderTraverse(root,ans);
	
	for (auto &x:ans) {
		cout << x << endl;
	}
	
	return 0;
}

