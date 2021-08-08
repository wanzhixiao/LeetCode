package dp;


/*
 预测赢家
 dp[i][j]代表区间[i,j]上的赢家所能获得的分数
* */

import java.lang.reflect.Array;
import java.util.Arrays;

class Solution486 {
    //递归搜索
    public boolean PredictTheWinner(int[] nums) {
        int res = helper(nums,0,nums.length-1);
        return res>=0;
    }

    int helper(int[] nums,int i,int j){
        if(i==j){
            return nums[i];
        }
        return (int)Math.max(nums[i]-helper(nums,i+1,j),nums[j]-helper(nums,i,j-1));
    }

    //带记忆的递归搜索
    int[][] dp;
    public boolean PredictTheWinner1(int[] nums){
        int n = nums.length;
        dp = new int[n][n];

        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        int res = helper1(nums,0,n-1);

        return res>=0;
    }

    int helper1(int[] nums,int i,int j){
        if(i==j){
            return nums[i];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int res = (int)Math.max(nums[i]-helper1(nums,i+1,j),nums[j]-helper1(nums,i,j-1));
//        dp[i][j] = res;
        dp[i][j] = Math.max(dp[i][j],res);
        return res;
    }

    //动态规划
    public boolean PredictTheWinner3(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n][n];
        for(int i=0;i<n;i++){
            dp[i][i] = nums[i];
        }
        for(int i=n-2; i>=0; --i){
            for(int j=i+1;j<n;j++){                //不包括对角线，取右上半部分,   左边和下面的先计算
                dp[i][j] = Math.max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][n-1]>=0;
    }
}

public class lc486 {
    public static void main(String[] args) {
        int[] nums = {1,5,2};
        Solution486 solu = new Solution486();
        boolean res = solu.PredictTheWinner3(nums);
        System.out.println(res);
    }
}
