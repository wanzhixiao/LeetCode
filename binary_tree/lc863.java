package binary_tree;

import java.util.*;

class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
 }

class Solution863 {
    HashMap<TreeNode,TreeNode> map;
    List<Integer> ans;
    Set<TreeNode> visited;

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        map = new HashMap<>();
        ans = new ArrayList<>();
        visited = new HashSet<>();
        findparent(root,null,target);

        //从目标节点开始dfs
        dfs(target,k);
        return ans;
    }

    void findparent(TreeNode root,TreeNode parent,TreeNode target){
        //找到目标节点前记录遍历过程中结点的父结点
        if(root == null){
            return;
        }

        map.put(root,parent);
        if(root.val == target.val){
            return;
        }

        findparent(root.left,root,target);
        findparent(root.right,root,target);
    }

    void dfs(TreeNode root, int k){
        if(root!=null && !visited.contains(root)){
            visited.add(root);
            if(k==0){
                ans.add(root.val);
                return;
            }
            dfs(root.left,k-1);
            dfs(root.right,k-1);
            dfs(map.get(root),k-1);
        }

    }
}

public class lc863 {
    public static void main(String[] args) {

    }
}
