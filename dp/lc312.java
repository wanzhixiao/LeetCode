package dp;


import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;

class Solution312 {
    private int ans = 0;

    //回溯法，超时
    public int maxCoins(int[] nums) {
        int n = nums.length;
        ArrayList<Integer> arr = new ArrayList<Integer>();
        for(int i=0;i<n;i++){
            arr.add(nums[i]);
        }

        helper(arr,0);
        return ans;
    }

    public void helper(ArrayList<Integer> nums,int coins){
        // boundry
        //边界条件为所有的气球均被刺破
        if(nums.size()==0){
            ans = Math.max(coins,ans);
            return;
        }
        //search
        for(int i=0;i<nums.size();i++){
            //暂存第i个气球的值
            int tmp = nums.get(i);
            //计算刺破第i个气球获得的硬币数
            int delta = nums.get(i)*(i>0?nums.get(i-1):1)*(i>=nums.size()-1?1:nums.get(i+1));
            //刺破第i个气球
            nums.remove(i);
            //继续回溯
            helper(nums,coins+delta);
            //撤销
            nums.add(i,tmp);
        }
    }

    //带记忆的递归搜索
    int[][] dp;
    public int maxCoins2(int[] nums){
        int n = nums.length;
        ArrayList<Integer> arr = new ArrayList<Integer>();
        for(int i=0;i<n;i++){
            arr.add(nums[i]);
        }

        //dp[i..j]表示num[i..j]能够获得的最大硬币数
        //选择最后一个被戳破的气球k
        //dp[i][j] = dp[i][k]+dp[k+1][j]+nums[i]*nums[k]*nums[j]

        dp = new int[n][n];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        helper2(arr,0,n-1);

        return dp[0][n-1];
    }

    public int helper2(ArrayList<Integer> nums,int i,int j){
        //boundry
        if(i>j){
            return 0;
        }
        if(dp[i][j]>0){
            return dp[i][j];
        }

        for(int k=i;k<=j;k++){
            int left = helper2(nums,i,k-1);
            int right = helper2(nums,k+1,j);
            //nums[i..,k..,j]
            int delta = nums.get(k);
            delta = delta*(i>0?nums.get(i-1):1)*(j>=nums.size()-1?1:nums.get(j+1));
            dp[i][j] = Math.max(dp[i][j],left+right+delta);
        }
        return dp[i][j];
    }
    //动态规划
    public int maxCoins3(int[] nums){
        int n = nums.length;
        ArrayList<Integer> arr = new ArrayList<Integer>();
        for(int i=0;i<n;i++){
            arr.add(nums[i]);
        }
        arr.add(0,1);
        arr.add(1);

        dp = new int[n+2][n+2];

        for(int len=1;len<=n;len++){    //枚举区间长度,长度需大于0
            for(int i=1;i<=n-len+1;i++){     //枚举左端点 （1，n),数组中有n+2个元素，分别在左右端点填充1
                int j = i+len-1;            //(1,n),分别在i=1和i=n-len+1取得

                for(int k=i;k<=j;k++){
                    int delta = arr.get(k)*arr.get(i-1)*arr.get(j+1);
                    dp[i][j] = Math.max(dp[i][j],dp[i][k-1]+dp[k+1][j]+delta);
                }
            }
        }
        return dp[1][n];
    }
    // https://www.bilibili.com/video/av45180542
    //参考题解：https://qoogle.top/leetcode-312-burst-balloons/
}

public class lc312 {
    public static void main(String[] args) {
        Solution312 solu = new Solution312();
        int[] nums = {3,1,5,8};
        int ans = solu.maxCoins3(nums);
        System.out.println(ans);
    }
}
