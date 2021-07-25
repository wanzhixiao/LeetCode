package binary_tree;

import sun.reflect.generics.tree.Tree;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;


class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

/*
* 找每层的最右边一个结点是解决该题的关键
* BFS,在添加结点入队列时，结点是逐层加入的
* 下一层入队列时上一层会先出队列，所以只需要保留 队列末尾的那个元素
* 在遍历过程中,将左右非空子节点加入队列中
*
* DFS
* 以根，右，左的形式遍历
* 记录遍历的深度，用list保留每次第一个遍历的结点，lise.size()==depth时
* 如，0==list.size()保留根 1, depth++
* depth = 1, depth == list.size() == 1，保留3，继续遍历2，depth++, depth=2
* 遍历 4, depth == 2 == list.size() ,保留4，继续遍历5，depth++, depth = 3
*                       1
*                     /  \
*                   2     3
*                   \      \
*                    5      4
*
* */

class Solution199 {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if(root == null) {
            return res;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while(!queue.isEmpty()){
           int size = queue.size();
           for(int i=0; i<size; i++){
               TreeNode p = queue.poll();
               if(i == size-1){
                   res.add(p.val);
               }
               if(null != p.left){
                   queue.offer(p.left);
               }
               if(null != p.right){
                   queue.offer(p.right);
               }
           }
        }
        return res;
    }
}

public class lc199 {
}
