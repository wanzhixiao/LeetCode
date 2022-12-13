#include<bits/stdc++.h>
using namespace std;


/*
二叉树的最大深度
思路：
    深度是从根节点到树中任意节点的层数,下面这棵树的最大深度是3，最小深度是2.（高度根节点是3）
                    1                   1
                                       / \
                    2                 2   3
                                     / \
                    3               4   5
    思路1：
        后序遍历，从下往上返回树的深度，返回到根节点，函数调用结束即树的最大深度，
        if(root == NULL)
        {
            return 0;
        }
        return max(depth(root->left),depth(root->right))+1;
    思路2：
        先序遍历，使用回溯，每往下一层，深度加1，用全局变量保存树的深度，比较全局变量和当前深度的最大值

二叉树的最小深度
*/

struct TreeNode{
    TreeNode *left, *right;
    int val;
    TreeNode(int val):val(val),left(NULL),right(NULL){}
    TreeNode(){}
    ~TreeNode(){
    }

    //求二叉树的最大深度
    int maxdepth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left_depth = maxdepth(root->left);
        int right_depth = maxdepth(root->right);
        return (left_depth>right_depth)?(left_depth+1):(right_depth+1);
    }

    int result = 0;
    void getdepth(TreeNode *root,int &depth){
        result = depth > result ? depth : result;
        if(root->left == nullptr && root->right == nullptr){
            return;
        }
        if(root->left){
            depth++;
            getdepth(root->left,depth);
            depth--;
        }
        if(root->right){
            depth++;
            getdepth(root->right,depth);
            depth--;
        }
        return;
    }

    //二叉树的最小深度
    int result1 = 9999;
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int depth = 1;
        helper(root,depth);
        return result;
    }
    void helper(TreeNode *root,int depth){
        if((root->left==NULL) && (root->right==NULL)){
            result1 = depth <  result1? depth : result1;
            return;
        }
        if(root->left){
            depth++;
            helper(root->left,depth);
            depth--;
        }
        if(root->right){
            depth++;
            helper(root->right,depth);
            depth--;
        }
    }
/*
    给定一棵多叉树，求最大最小深度
                                1
                           /    |    \
                          3     2     4
                        /  \
                       5   6
*/
    //N叉树的最大深度
    int result2 = 0;
    int maxDepth2(Node* root) {
        if(root==NULL){
            return result;
        }
        int depth = 1;
        helper2(root,depth);
        return result;
    }
    void helper2(Node *root,int depth){
        //记录当前最大深度
        result = result>depth?result:depth;
        //叶子节点则表明出于最后一层，返回
        if(root->children.size() == 0){
            return;
        }
        //遍历每个孩子节点
        size_t size = root->children.size();
        for(int i=0;i<size;i++){
            if(root->children[i] != NULL){
                helper2(root->children[i],depth+1);
            }
        }
        return;
    }

/*先序遍历与后序遍历的区别在于  
    先序求最大深度：记录当前位置层数最深的结果
    traverse(root,depth):
        result = result > depth ? result:depth
        if(root-> child is None){
            return;
        }
        if (root->child[i] is not None)
            traverse(root->child[i],depth)
    后序求最大深度 : :返回当前子树层数最深的层数+1
    traverse(root,depth):
        if(root){
            return 0 ;
        }
        int level_depth = 0;
        if (root->child[i] is not None)
            int tmp = traverse(root->child[i],depth);
            level_depth = max(level_depth,tmp)
        return level_depth + 1
*/
};

int main()
{
    int arr[] = {1,2,3};
    vector<int> result;
    TreeNode *root = new TreeNode(arr[0]);
    root->left = new TreeNode(arr[1]);
    root->right = new TreeNode(arr[2]);
    int depth = 1;
    root->getdepth(root,depth);
    cout << root->result << endl;
    return 0;
}