#include<bits/stdc++.h>
using namespace std;

/*
106. 从中序与后序遍历序列构造二叉树
                                        3
                                       / \
                                      9  20
                                         / \
                                        15  7

inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
output: [3,9,20,null,null,15,7]
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
 TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        size_t size1 = inorder.size(), size2 = postorder.size();
        if(size2==0){
            return nullptr;
        }
        int rootVal = postorder[size2-1];
        TreeNode *root = new TreeNode(rootVal);
        if(size2==1){
            return root;
        }
        int idx = 0;
        for(int i=0;i<size1;i++){
            if(inorder[i]==rootVal){
                idx = i;
                break;
            }
        }
        vector<int> inLeft(inorder.begin(),inorder.begin()+idx);
        vector<int> inRight(inorder.begin()+idx+1,inorder.end());
        
        vector<int> postLeft(postorder.begin(),postorder.begin()+inLeft.size());
        vector<int> postRight(postorder.begin()+inLeft.size(),postorder.end()-1);
        root->left = buildTree(inLeft,postLeft);
        root->right = buildTree(inRight,postRight);
        return root;
    }
};

int main(){

    return 0;
}