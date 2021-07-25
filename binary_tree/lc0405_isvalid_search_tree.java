package binary_tree;

//合法的二叉搜索树
 //Definition for a binary tree node.
//class TreeNode {
//    int val;
//    TreeNode left;
//    TreeNode right;
//    TreeNode(int x) { val = x; }
//}

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

class Solution0405 {
     public boolean isValidBST(TreeNode root) {
         return  helper(root,Long.MIN_VALUE,Long.MAX_VALUE);
     }

     boolean helper(TreeNode root,long lower,long upper){
         if(root==null){
             return true;
         }
         boolean left = helper(root.left,lower,root.val);
         boolean right = helper(root.right,root.val,upper);
         return (lower< root.val) && (root.val < upper) && left&&right;
     }

    private TreeNode pre=null;
    public boolean isValidBST2(TreeNode root){
        if(root == null){
            return true;
        }
        if(!(isValidBST2(root.left))){
            return false;
        }

        if(pre != null && (root.val <= pre.val)){
            return false;
        }
        pre = root;

        if(!(isValidBST2(root.right))){
            return false;
        }
        return true;
    }


    //二叉树的非递归遍历
    public boolean isValidBST3(TreeNode root){
        Stack<TreeNode> stk = new Stack<>();

        stk.push(root);
        List<Integer> res=new ArrayList<>();

        while(!stk.empty()){

            while((root = stk.peek())!=null){
                stk.push(root.left);
            }

            stk.pop();      //空出栈

            if(!stk.empty()){
                TreeNode p = stk.peek();
                stk.pop();

                //visit p
//                res.add(p.val);
                if (pre != null && (p.val <= pre.val)){
                    return false;
                }
                pre = p;

                //不需要判断右子树是否为空
                stk.push(p.right);
            }

        }
        return true;
    }

}


public class lc0405_isvalid_search_tree {
}
