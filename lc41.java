package leetcode;


class Solution41 {
    public int arraySign(int[] nums) {
        long mul = 1;
        for(int i=0;i<nums.length;i++){
            mul = ((mul%Integer.MAX_VALUE)*(nums[i]%Integer.MAX_VALUE))%Integer.MAX_VALUE;
        }
        if(mul>0){
            return 1;
        }else if(mul<0){
            return -1;
        }
        return 0;
    }
}

public class lc41 {
    public static void main(String[] args) {

    }
}
