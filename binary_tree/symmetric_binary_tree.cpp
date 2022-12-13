#include<bits/stdc++.h>
using namespace std;
/*
对称的二叉树
思路1：后序遍历比较
后序遍历，左子树：左右根，右子树：右根左
分别比较外侧节点  left->left , right->right
和内侧节点 compare(left->right, right->left) && (left->val == right->val)
[1,2,2,3,null,-1,3]

                                1                           1
                               / \                         / \
                              2   2                       2   3
                             /   / \                     / \ / \
                            3   -1 3                    4  5 2  2
思路2：层序遍历比较
将同一层节点的值记录到数组，判断这个数组中的值是否对称
*/

struct TreeNode{
    TreeNode *left, *right;
    int val;
    TreeNode(int val):val(val),left(NULL),right(NULL){}
    TreeNode(){}
    ~TreeNode(){
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        return helper(root->left,root->right);
    }

    bool helper(TreeNode* left,TreeNode *right){

        if(((left==nullptr)&&(right!=nullptr)) || ((left!=nullptr)&&(right==nullptr))){
            return false;
        }
        else if((left==nullptr)&&(right==nullptr)){
            return true;
        }
        else if(left->val != right->val){
            return false;
        }

        bool outer = helper(left->left,right->right);
        bool inner = helper(left->right,right->left);

        return (left->val==right->val) && outer && inner;
    }

    bool helper1(TreeNode *root){
        queue<TreeNode*> q;
        if(root != nullptr){
            q.emplace(root);
        }
        while(!q.empty()){
            size_t size = q.size();
            vector<int> vec;
            for(int i=0; i<size;i++){
                root = q.front();
                q.pop();
                if(root != nullptr){
                    vec.emplace_back(root->val);
                }
                else{
                    vec.emplace_back(-101);
                }
                q.emplace(root->left);
                q.emplace(root->right);
            }
            size = vec.size();
            for(int i=0;i<size/2;i++){
                if(vec[i] != vec[size-i-1]){
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    int arr[] = {1,2,3};
    vector<int> result;
    TreeNode *root = new TreeNode(arr[0]);
    root->left = new TreeNode(arr[1]);
    root->right = new TreeNode(arr[2]);


    cout << root->helper1(root) << endl;

    delete root->left;
    root->left = NULL;
    delete root->right;
    root->right = NULL;
    delete root;  
    root = NULL;
    return 0;
}