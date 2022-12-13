#include<bits/stdc++.h>
using namespace std;

/*
二叉树的所有路径
                        1
                       / \
                      2   3
                       \
                        5
输出:["1->2->5","1->3"]      
思路: 回溯法
    递归终止条件
    如何回溯，即返回上一个节点
*/
struct TreeNode{
    TreeNode *left, *right;
    int val;
    TreeNode(int val):val(val),left(NULL),right(NULL){}
    TreeNode(){}
    ~TreeNode(){
    }

    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        helper(root,path);
        return ans;
    }

    void helper(TreeNode *root,vector<int> &path){
        path.emplace_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            string result = "";
            size_t size = path.size();
            for(int i=0;i<size-1;i++){
                string num = to_string(path[i]);
                result =  result + num + "->";
            }
            result = result + to_string(path[size-1]);
            ans.emplace_back(result);
            return;
        }
        if(root->left){
            helper(root->left,path);
            path.pop_back();
        }
        if(root->right){
            helper(root->right,path);
            path.pop_back();
        }
    }

    bool isSymmetric(TreeNode *root){
        if(root==nullptr){
            return true;
        }
        return helper(root->left,root->right);
    }
    bool helper(TreeNode *lef,TreeNode *rgt){
        if(((lef!=nullptr)&&(rgt==nullptr))||((lef==nullptr)&&(rgt!=nullptr))){
            return false;
        }else if(lef==nullptr && rgt == nullptr){
            return true;
        }
        else if(lef->val != rgt->val){
            return false;
        }
        bool left = helper(lef->left,rgt->right);
        bool right = helper(lef->right,rgt->left);
        return left && right;
    }

};

int main(){
    int arr[] = {1,2,2};
    vector<int> result;
    TreeNode *root = new TreeNode(arr[0]);
    root->left = new TreeNode(arr[1]);
    root->right = new TreeNode(arr[2]);

    cout << root->isSymmetric(root) << endl;

    vector<string> ans = root->binaryTreePaths(root);
    for(auto str : ans){
        cout << str << endl;
    }


    delete root->left;
    root->left = NULL;
    delete root->right;
    root->right = NULL;
    delete root;  
    root = NULL;
    return 0;
}