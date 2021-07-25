package leetcode.binary_search;

//https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/

import java.util.Arrays;
import java.util.stream.IntStream;

class Solution1011 {
    public int shipWithinDays(int[] weights, int D) {

        int left = Arrays.stream(weights).max().getAsInt();     //最低运力
        int right = IntStream.of(weights).sum();                //最高运力

        //二分法搜索最小的capcity
        while(left<right){
            int mid = left+(right-left)/2;
            if(posible(weights,D,mid)){//船的运载能力为mid且可以在D天运送完时，将right不断缩小，right=mid;压缩有边界，直到取到最小的右边界
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }

    public boolean posible(int[] weight,int D,int capcity){
        int tmp = 0;
        int day = 0;
        for(int i=0;i<weight.length;i++){
            tmp+=weight[i];
            if(tmp>capcity){
                day++;
                tmp=weight[i];
            }
            if(day>D){
                break;
            }
        }
        //最后一次运送
        day += 1;
        return day<=D;        //在D天内可以送达所有物品
    }
}

public class lc1011 {
    public static void main(String[] args) {
        Solution1011 s = new Solution1011();
        int[] weight = {1,2,3,1,1};
        int D = 4;

        int res = s.shipWithinDays(weight,D);
        System.out.println(res);
    }
}
