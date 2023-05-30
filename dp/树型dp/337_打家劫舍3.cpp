
/*
分类讨论： 
对于每个节点 ， 有两种操作，选或者不选
	1.选节点root, 则 root->left, root->right不能选
		rob = root->val + l_not_rob + r_not_rob; 
	2.不选节点root, 则root->left可选可不选，root->right可选可	
		not_rob = max(l_rob,l_not_rob) + max(r_rob, r_not_rob) 
		
	向上返回两个值，节点偷或者不偷 
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

对于每个房子，偷还是不偷
不偷
    dfs(i+1)
偷
    not_havae = dfs(i+1)
    have = dfs(i)


    f[i+2] = max(f[i+1],f[i]+v[i])
*/
