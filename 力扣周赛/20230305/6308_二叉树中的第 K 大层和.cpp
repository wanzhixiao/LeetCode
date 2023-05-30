#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
	typedef long long LL;
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        //从小到达排序  [1,2,3]
        priority_queue<LL, vector<LL>, greater<LL>> pq(k,0);
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        
        while (!q.empty()) {
            int size = q.size();
            LL levelsum = 0;
            for (int i = 0; i < size; i++) {
                root = q.front();
                q.pop();
                levelsum += root->val;
                if (root->left) {
                    q.push(root->left);
                }
                if(root->right) {
                    q.push(root->right);
                }
            }
            if (pq.size() < k) {
                pq.push(levelsum);
            } else {
                if (levelsum > pq.top()) {  // levelsum = 4 pq = [1,2,3]
                    pq.pop();               //弹出队头元素    
                    pq.push(levelsum);
                }
            }
            level++;
        }
        
        // cout << "size = " << pq.size() << endl;
        
        return level < k ? -1 : pq.top();
        
    }
};

/*
								5
							   / \
							  8  9
							/ \ / \
						   2  1 3  7
						  /\
						 4 6 
*/

int main() {
	vector<int> root{5,8,9,2,1,3,7,4,6};
	int k = 2;
	
	vector<TreeNode*> tree(root.size(), NULL);
	tree[0] = new TreeNode(root[0]);
	
	for (int i = 1; i < root.size(); i++) {
		if (root[i] == -1) {
			continue;
		}
		TreeNode *node = new TreeNode(root[i]);
		tree[i] = node;										//tree数组的第i个节点等于node 
		if (i & 1) {
			tree[i/2]->left = node;							//左子树 
		} else {	
			tree[i/2-1]->right = node;						//右子树 
		}
	} 
	Solution solu;
	long long ans = solu.kthLargestLevelSum(tree[0], k);
	cout << ans << endl;
	
	return 0;
}
