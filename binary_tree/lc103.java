package binary_tree;
import java.util.*;

/**
 * 层序遍历，
 * 记住当前队列中元素的个数，与下一轮入队列中元素的个数，每层中个每个元素的子节点都要加入队列
 * java 队列为LinkedList,入队列，queue.offer(obj), 取队列队首元素并删除，obj = queue.poll()
 * */

class Solusion103{
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res =  new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        if(root==null){
            return res;
        }
        list.add(Integer.valueOf(root.val));
        res.add(list);
        int oldCount=1,newCount = 0;            //记住上一轮队列中元素的个数和下一轮队列中元素的个数
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);              //添加一个元素
        int reversed = 2;
        while(!queue.isEmpty()){
            List<Integer> templist = new ArrayList<>();
            while(oldCount>0){
                TreeNode node = queue.poll(); //返回第一个元素，并在队列中删除
                if(node.left!=null){
                    templist.add(node.left.val);
                    queue.add(node.left);
                    newCount++;
                }
                if(node.right!=null){
                    templist.add(node.right.val);
                    queue.add(node.right);
                    newCount++;
                }
                oldCount--;
            }

            if(templist.size()>0){
                if(reversed%2==0){
                    Collections.reverse(templist);  //对列表进行反转，java传的是引用
                }
                res.add(templist);
            }
            oldCount = newCount;
            newCount = 0;
            reversed+=1;
        }
        return res;
    }
}

public class lc103 {
    public static void main(String[] args) {

    }
}
