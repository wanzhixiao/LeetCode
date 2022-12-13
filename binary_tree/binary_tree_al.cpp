 #include<bits/stdc++.h>
using namespace std;
/*
    翻转二叉树
    思路1：前序遍历，后序遍历
    1              1 
   / \            / \
  2  3           3   2
   思路2：层序遍历
   遍历每一层节点，将每个节点的左右子树进行交换
*/
struct TreeNode{
    TreeNode *left, *right;
    int val;
    TreeNode(int val):val(val),left(NULL),right(NULL){}
    TreeNode(){}
    ~TreeNode(){
    }
   
   void preOrderTraverse(TreeNode *root,vector<int> &ans){
        if(root == nullptr){
            return;
        }
        // ans.emplace_back(root->val);
        cout << root->val << endl;
        preOrderTraverse(root->left,ans);
        preOrderTraverse(root->right,ans);
   }

   void preOrderTraverse1(TreeNode *root,vector<int> &ans){
        stack<TreeNode*> stk;
        if(root != nullptr){
            stk.emplace(root);
        }
        while(!stk.empty()){
            while((root = stk.top()) && (root != nullptr)){
                ans.emplace_back(root->val);
                stk.emplace(root->left);
            }
            stk.pop();
            if(!stk.empty()){
                root = stk.top();
                stk.pop();
                stk.emplace(root->right);
            }
        }
   }

   void invertTree(TreeNode *root){
        if(root == nullptr){
            return;
        }
        TreeNode *p = root->left;
        root->left = root->right;
        root->right = p;
        invertTree(root->left);
        invertTree(root->right);
   }

   void invertTreeNoneRecursion(TreeNode *root){
        queue<TreeNode*> q;
        if(root != nullptr){
            q.emplace(root);
        }
        while(!q.empty()){
            size_t size = q.size();
            for(int i=0;i<size;i++){
                TreeNode *p = q.front();
                q.pop();
                TreeNode *tmp = p->left;
                p->left = p->right;
                p->right = tmp;
                if(p->left != nullptr){
                    q.emplace(p->left);
                }
                if(p->right != nullptr){
                    q.emplace(p->right);
                }
            }
        }
   }

   void unifyTraverse(TreeNode *root,vector<int>& vec){
        stack<TreeNode*> stk;
        if(root != nullptr){
            stk.emplace(root);
        }
        while(!stk.empty()){
            root = stk.top();
            if(root != nullptr){
                stk.pop();
                
                //放这就是后序遍历
                if(root->right != nullptr){
                    stk.emplace(root->right);
                }
                //放这就是中序遍历
                if(root->left != nullptr){
                    stk.emplace(root->left);
                }
                //放这就是前序遍历
                stk.emplace(root);
                stk.push(NULL);
            }
            else
            {   
                stk.pop();
                root = stk.top();
                stk.pop();

                swap(root);
                // vec.emplace_back(root->val);
            }
        }
   }

    void swap(TreeNode* root){
        TreeNode *p = root->left;
        root->left = root->right;
        root->right = p;
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
    root->unifyTraverse(root,result);
    root->preOrderTraverse(root,result);

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