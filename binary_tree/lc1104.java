package binary_tree;

//二叉树寻路
//之字形+满二叉树
//对于满二叉树，有i层的数二叉树，最大的结点数2^i - 1, 第i层最大的结点编号为2^(i-1)
//对完全二叉树，若结点从1开始编号，左孩子结点编号，2i,右孩子结点编号2i+1
//对于有n个结点的二叉树，n = n0+n1+n2, n = n1+2n2+1 => n0 = n2+1

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution1104 {
    public List<Integer> pathInZigZagTree(int label) {
        List<Integer> list = new ArrayList<>();
        int row = 1,rowstart = 1;       //行号与每行的起点

        while(rowstart*2<=label){
            row += 1;
            rowstart *= 2;              //之字形开头为2的次方偶数，
        }
        if(row % 2==0){
            label = reverseLabel(label,row);
        }
        //从第row行开始往上求解路径，对偶数行的结点进行reverse
        while(row>0){
            if(row%2==0){
                list.add(reverseLabel(label,row));
            }else{
                list.add(label);
            }
            //计算label的父结点
            label = label/2;
            //树的层数减1
            row--;
        }
        Collections.reverse(list);
        return list;
    }
    public int reverseLabel(int label,int row){ //偶数行求对称的值
        return (1 << row - 1) + (1 << row) - 1 - label;   //2^i + 2^i-1 - label
    }
}

public class lc1104 {
    public static void main(String[] args) {
        int label = 14;
        Solution1104 solu = new Solution1104();
        List<Integer> list = solu.pathInZigZagTree(label);
        for(int id : list){
            System.out.print(id+" ");
        }
        int a = 2<<2;
        System.out.println(a);
    }
}
