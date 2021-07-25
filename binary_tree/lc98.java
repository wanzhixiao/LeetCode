<<<<<<< HEAD
package binary_tree;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

//[5,4,6,null,null,3,7]
/*
*             5
*           /  \
*         4     6
*             /  \
*            3    7
* */
//[2,2,2]
class Solution98 {
    public boolean isValidBST(TreeNode root) {
        if(root == null){
            return true;
        }

        if(root.left != null && root.left.val>=root.val){
            return false;
        }
        if(root.right != null && root.right.val <= root.val){
            return false;
        }

        boolean  left = isValidBST(root.left);
        boolean right = isValidBST(root.right);
        return left && right;
    }


    /*通过设置边界，lower和upper来保证 左<根<右*/
    public boolean isValidBST1(TreeNode root) {
        return helper(root,Long.MIN_VALUE,Long.MAX_VALUE);
    }
    public boolean helper(TreeNode root,long lower,long upper){
        if(root == null){
            return true;
        }
        if(root.val>=upper || root.val<=lower){
            return false;
        }

        boolean left = helper(root.left,lower,root.val);        //验证3时，lower=5,upper=6
        boolean right = helper(root.right,root.val,upper);
        return left && right;
    }
}

public class lc98 {
    public static void main(String[] args) {
        System.out.println();
    }
}
=======
package binary_tree;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

//[5,4,6,null,null,3,7]
/*
*             5
*           /  \
*         4     6
*             /  \
*            3    7
* */
//[2,2,2]
class Solution98 {
    public boolean isValidBST(TreeNode root) {
        if(root == null){
            return true;
        }

        if(root.left != null && root.left.val>=root.val){
            return false;
        }
        if(root.right != null && root.right.val <= root.val){
            return false;
        }

        boolean  left = isValidBST(root.left);
        boolean right = isValidBST(root.right);
        return left && right;
    }


    /*通过设置边界，lower和upper来保证 左<根<右*/
    public boolean isValidBST1(TreeNode root) {
        return helper(root,Long.MIN_VALUE,Long.MAX_VALUE);
    }
    public boolean helper(TreeNode root,long lower,long upper){
        if(root == null){
            return true;
        }
        if(root.val>=upper || root.val<=lower){
            return false;
        }

        boolean left = helper(root.left,lower,root.val);        //验证3时，lower=5,upper=6
        boolean right = helper(root.right,root.val,upper);
        return left && right;
    }
}

public class lc98 {
    public static void main(String[] args) {
        System.out.println();
    }
}
>>>>>>> e94a879fa9b4dadf491dc10c450c622a214ecece
