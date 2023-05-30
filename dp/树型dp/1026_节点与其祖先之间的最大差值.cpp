/*
���룺root = [8,3,10,1,6,null,14,null,null,4,7,13]
�����7
���ͣ� 
�����д����Ľڵ��������ȵĲ�ֵ������һЩ���£�
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
�����п��ܵĲ�ֵ�У����ֵ 7 �� |8 - 1| = 7 �ó���
						8
					  /  \
					 3   10
				   / \    \
				  1  6    14
					/ \   /
				   4  7  13
				   
����ֵ���ܵ���Դ��
	1. �ڵ�cur�������ӽڵ��е���Сֵminval,   cur.val-minval, ���߽ڵ�cur�������ӽڵ��е����ֵmaxval maxval - cur.val
			max(cur.val-minval, maxval - cur.val)
			minval = min(lmin, rmin)
			maxval = max(lmax, rmax)
			
			���Ϸ��ص�ǰ�ڵ�������С������ֵ, 
			�ڵ�����ֵ curmax = max(cur.val, max(lmax, rmax)) ���ڵ����Сֵ curmin = min(cur.val, min(lmin, rmin))
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
    
    // ������������ϴ����ӽڵ����Сֵ�����ֵ 
    vector<int> dfs1(TreeNode *root) {
        if (root == NULL) {
            return {inf,-inf};
        }
        vector<int> l = dfs1(root->left);
        vector<int> r = dfs1(root->right);
        //[0], �ϴ�ֵ�� 1��Сֵ
        int val = root->val;
        int minval = min(min(l[0], r[0]), val);
        int maxval = max(max(l[1],r[1]), val);

        int m = min(l[0],r[0]);
        int n = max(l[1],r[1]);

        ans = max(ans, max(n-val, val-m));
    
        return {minval,maxval};
    }

	
	//������� 
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
