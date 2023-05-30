#include<iostream>
#include<vector>
using namespace std; 

struct TreeNode{
	TreeNode *left;
	TreeNode *right;
	int val;
	TreeNode(int val) : val(val), left(NULL), right(NULL){
	} 
}; 

void insert(TreeNode* root, int val) {
	if (root == NULL) {
		root = new TreeNode(val);
		return;
	}
	TreeNode *p = root;
	TreeNode *pre = NULL;
	int direction = 0;
	while (p != NULL) {
		if (p->val == val) {
			return;
		}
		else if (p->val > val) {
			pre = p;
			p = p->left;
			direction = 0;
		} else if (p->val < val) {
			pre = p;
			p = p->right;
			direction = 1;
		}
	}
	if (direction & 0) {
		pre->left = new TreeNode(val);
	} else {
		pre->right = new TreeNode(val);
	}
	return;
}

void dfs(TreeNode *root) {
	if (root) {
		cout << root->val << " ";
		dfs(root->left);
		dfs(root->right); 
	}
}

int main() {
	vector<int> nums = {4,2,7,1,3};
	vector<TreeNode*> tree(nums.size(),NULL);
	tree[0] = new TreeNode(nums[0]);
	for (int i = 1; i < nums.size(); i++) {
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
	dfs(tree[0]);
	 
	insert(tree[0],5);
	cout << endl;
	dfs(tree[0]);
	return 0;
}




/*
		   2
		 /  \
	   1     7
  			/ \
  		   5   8
  		   	 
val = 6

*/ 

