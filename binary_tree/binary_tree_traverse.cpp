#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    TreeNode *left, *right;
    int val;
    TreeNode(int val):val(val),left(NULL),right(NULL){}
    TreeNode(){}
    ~TreeNode(){
    }
    //先序遍历，递归
    void preOrderTraverse(vector<int>& vec){
        if(this == NULL){
            return;
        }
        vec.emplace_back(this->val);
        this->left->preOrderTraverse(vec);
        this->right->preOrderTraverse(vec);
    }

    //先序遍历，非递归
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traverse(root,result);
        return result;
    }
    void traverse(TreeNode *root,vector<int> &vec){
        stack<TreeNode*> stk;
        stk.emplace(root);
        TreeNode *top;
        while(!stk.empty()){
            while((top = stk.top()) && (top != NULL)){
                vec.emplace_back(top->val);
                stk.emplace(top->left);
            }
            stk.pop();
            if(!stk.empty()){
                top = stk.top();
                stk.pop();
                stk.emplace(top->right);
            }
        }
        return;
    }

    //层序遍历
    void levelTraverse(TreeNode *root,vector<int> &vec) const{
        cout << "level traverse" << endl;
        queue<TreeNode*> q;
        if(root!=NULL){
            q.emplace(root);
        }
        while(!q.empty()){
            size_t size = q.size();
            for(int i=0; i<size; i++){
                TreeNode *tmp = q.front();
                vec.emplace_back(tmp->val);
                q.pop();
                if(tmp->left != NULL){
                    q.emplace(tmp->left);
                }
                if(tmp->right != NULL){
                    q.emplace(tmp->right);
                }
            }
        }
        return;
    }

    //后序遍历，非递归
    void postTraverse(TreeNode *root,vector<int> &vec){
        stack<TreeNode*> stk;
        TreeNode *prev;
        while(root != NULL || !stk.empty()){
            while(root != NULL){
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();

            if(root->right==NULL || root->right == prev){
                vec.emplace_back(root->val);
                prev = root;
                root = NULL;
            }
            else
            {
                stk.emplace(root);
                root = root->right;
            }
        }
    }

    //中序遍历，非递归
    void InOrderTraverse(TreeNode *root,vector<int> &vec){
        stack<TreeNode*> stk;
        while(root != NULL || !stk.empty()){
            if(root != NULL){
                stk.emplace(root);
                root = root->left;
            }else{
                root = stk.top();
                stk.pop();
                vec.emplace_back(root->val);
                root = root->right;
            }
        }
    }
};

/*
    1
  2   3
4  5 6
*/

int main(){
    int arr[] = {1,2,3};
    TreeNode t1,t2;
    TreeNode arr1[] = {t1,t2};
    vector<int> result;
    TreeNode *root = new TreeNode(arr[0]);
    root->left = new TreeNode(arr[1]);
    root->right = new TreeNode(arr[2]);
    root->InOrderTraverse(root,result);

    for(vector<int>::iterator it = result.begin(); it!=result.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    delete root->left;
    root->left = NULL;
    delete root->right;
    root->right = NULL;
    delete root;  
    root = NULL;
    return 0;
}