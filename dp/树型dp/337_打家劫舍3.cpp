
/*
�������ۣ� 
����ÿ���ڵ� �� �����ֲ�����ѡ���߲�ѡ
	1.ѡ�ڵ�root, �� root->left, root->right����ѡ
		rob = root->val + l_not_rob + r_not_rob; 
	2.��ѡ�ڵ�root, ��root->left��ѡ�ɲ�ѡ��root->right��ѡ��	
		not_rob = max(l_rob,l_not_rob) + max(r_rob, r_not_rob) 
		
	���Ϸ�������ֵ���ڵ�͵���߲�͵ 
*/ 

class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> ans = dfs(root);
        return max(ans[0], ans[1]);
    }

    vector<int> dfs(TreeNode *root) {
        if (root == nullptr) {
            return {0,0};
        }

        vector<int> l = dfs(root->left);
        vector<int> r = dfs(root->right);
        int rob = root->val + l[1] + r[1];
        int not_rob = max(l[0],l[1]) + max(r[0],r[1]);
        vector<int> m{rob, not_rob};
        return m;
    }
    int max(int a,int b) {
        return a>b ? a:b;
    }
};

/*
        1
       /\
      1  1
     /\
   100 100

����ÿ�����ӣ�͵���ǲ�͵
��͵
    dfs(i+1)
͵
    not_havae = dfs(i+1)
    have = dfs(i)


    f[i+2] = max(f[i+1],f[i]+v[i])
*/
