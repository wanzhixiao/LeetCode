/*
输入：root = [8,3,10,1,6,null,14,null,null,4,7,13]
输出：7
解释： 
我们有大量的节点与其祖先的差值，其中一些如下：
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
在所有可能的差值中，最大值 7 由 |8 - 1| = 7 得出。
						8
					  /  \
					 3   10
				   / \    \
				  1  6    14
					/ \   /
				   4  7  13
				   
最大差值可能的来源：
	1. 节点cur的所有子节点中的最小值minval,   cur.val-minval, 或者节点cur的所有子节点中的最大值maxval maxval - cur.val
			max(cur.val-minval, maxval - cur.val)
			minval = min(lmin, rmin)
			maxval = max(lmax, rmax)
			
			向上返回当前节点最大和最小的两个值, 
			节点的最大值 curmax = max(cur.val, max(lmax, rmax)) ，节点的最小值 curmin = min(cur.val, min(lmin, rmin))
			return  {curmin, curmax}

*/ 

class Solution {
    int ans = 0;
    int inf = 0x3f3f3f3f;
public:
    int maxAncestorDiff(TreeNode* root) {
        dfs1(root);
        return ans;
    }
    
    // 后序遍历，向上传递子节点的最小值和最大值 
    vector<int> dfs1(TreeNode *root) {
        if (root == NULL) {
            return {inf,-inf};
        }
        vector<int> l = dfs1(root->left);
        vector<int> r = dfs1(root->right);
        //[0], 较大值， 1较小值
        int val = root->val;
        int minval = min(min(l[0], r[0]), val);
        int maxval = max(max(l[1],r[1]), val);

        int m = min(l[0],r[0]);
        int n = max(l[1],r[1]);

        ans = max(ans, max(n-val, val-m));
    
        return {minval,maxval};
    }

	
	//先序遍历 
    void dfs(TreeNode *root, int minx, int maxx) {
        if (root==NULL) {
            ans = max(ans, maxx-minx);
            return;
        }
        int mn = min(root->val, minx);
        int mx = max(root->val, maxx);

        dfs(root->left, mn, mx);
        dfs(root->right, mn, mx);
    }
};
