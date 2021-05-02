package leetcode;


/*
输入：nums = [1,2,3], target = 4
输出：7
解释：
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
请注意，顺序不同的序列被视作不同的组合。

下面↓用例超出时间限制
[2,1,3]
35


思路：
第一反应是回溯，一个一个值去参试，当达到目标值返回

* */

import java.util.Arrays;

class Solution377{
    int count = 0;  //组合数
    //回溯法
    public int combinationSum4(int[] nums, int target) {
        backtracking(nums,0,target);
        return count;
    }

    public void backtracking(int []nums,int cur,int target){
        if(cur==target){
            count++;
            return;
        }
        if(cur>target){//不满足
            return;
        }

        for(int i=0;i<nums.length;i++){
            //满足条件
            cur+=nums[i];
            //做决定
            backtracking(nums,cur,target);
            //撤销决定
            cur-=nums[i];
        }
        return;
    }


    //解法二，带记忆功能的深度搜索，深搜时如果计算过，则直接返回该数的组合数，类似剪枝
    //画出递归树
    private int[] memo;
    public int combinationSum42(int[] nums, int target) {
        memo = new int[target+1];
        Arrays.fill(memo,-1);
        memo[0] = 1;

        return backtracking1(nums,target);
    }

    public int backtracking1(int []nums,int target){
        if (memo[target] != -1) {
            return memo[target];
        }
        int res = 0;
        for (int num : nums) {
            if (target >= num) {
                res += backtracking1(nums, target - num);        //res代表组合数个数
            }
        }
        memo[target] = res;
        return res;
    }

    //解法三，转化为背包
    //dp[i]表示容量为i时组合数的个数，nums[i]表示第i个物品

    public int combinationSum43(int []nums,int target){
        int[] dp = new int[target+1];
        dp[0] = 1;
        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.length;j++){
                if(i>=nums[j]){
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
}

public class lc377 {
    public static void main(String[] args) {
        int []nums = {2,1,3};
        int target = 35;
        Solution377 s = new Solution377();
        int res = s.combinationSum43(nums,target);
        System.out.println(res);
    }
}
