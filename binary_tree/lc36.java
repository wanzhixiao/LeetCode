package binary_tree;
class Node {
    public int val;
    public Node left;
    public Node right;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val,Node _left,Node _right) {
        val = _val;
        left = _left;
        right = _right;
    }
}

class Solution {
    private Node head=null;
    private Node pre=null;
    public Node treeToDoublyList(Node root) {
        if(root == null){
            return root;
        }
        dfs(root);
        head.left = pre;
        pre.right = head;
        return head;
    }

    public void dfs(Node root){
        if(root == null){
            return ;
        }
        dfs(root.left);
        if(pre != null){
            root.left = pre;
            pre.right = root;
        }else{
            head = root;  //最左边的叶子结点
        }
        pre = root;
        dfs(root.right);

    }
}

public class lc36 {
}
