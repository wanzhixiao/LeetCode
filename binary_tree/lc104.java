package binary_tree;

/*
* 二叉树的直径
* 解题思路: 后序遍历+dp
* */


class Solution104 {
    int res = Integer.MIN_VALUE;
    public int diameterOfBinaryTree(TreeNode root) {
        dfs(root);
        return res;
    }

    public int dfs(TreeNode root){
        if(root == null){
            return 0;
        }
        int left = dfs(root.left);
        int right = dfs(root.right);
        res = Math.max(left+right,res);
        return Math.max(right,left)+1;
    }
}

public class lc104 {
    public static void main(String[] args) {

    }
}
