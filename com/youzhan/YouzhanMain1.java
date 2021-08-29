package com.youzhan;
import java.util.*;


class Solution1 {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param input_array long长整型一维数组
     * @return long长整型
     */
    public long search (long[] input_array) {
        // write code here
        long res = 0;
        int left=0,right=0;
        int n = input_array.length;
        long tmp = 0;
        while(right<n){
            tmp += input_array[right];
            while(left<=right && tmp<0){
                tmp -= input_array[left++];
            }
            res = res>tmp?res:tmp;
            right++;
        }
        return res;
    }
}
public class YouzhanMain1 {
    public static void main(String[] args) {

    }
}
