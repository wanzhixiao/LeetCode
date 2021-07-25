package leetcode.jianzhioffer;

import java.util.Arrays;

class Solution57_1 {
    public int[][] findContinuousSequence(int target) {
        int [][]res = new int[target+1][];
        int[] presum = new int[target+1];
        presum[0] = 0;

        //求解前缀和
        for(int i=1;i<target;i++){
            presum[i] = i + presum[i-1];
        }

        int l=0,r=1,t=0;
        //双指针
        while(l<r && l<target/2){
            int num = presum[r] - presum[l];
            if(num==target){
                int[] temp = new int[r-l];
                for(int i=l+1;i<=r;i++){
                   temp[i-l-1] = i;
                }
                res[t++] = temp;
                l++;
                r++;
            }else if(num<target){
                r++;
            }else{          //nums>target
                l++;
            }
        }
        res = Arrays.copyOf(res,t);
        return res;
    }
}

public class offer57_1 {
    public static void main(String[] args) {

        Solution57_1 s = new Solution57_1();

        int target = 15;
        int[][] res = s.findContinuousSequence(target);

    }
}
