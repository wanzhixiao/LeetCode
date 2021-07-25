package leetcode.dp;
/*
376
* 摆动序列
* 输入：[1,7,4,9,2,5]
* 输出: 6
 * */

/*
* 思路：维护两条路径，一条开始是下降，另一条开始是上升
* 下降的长度由上一次上升的转换而来，上升的长度由上一次下降转换而来
* 如果本次是下降，即nums[i]-nums[i-1]<0,则
* dp[i][down] = dp[i-1][up]+1;
* dp[i][up] = dp[i-1][up];上升长度维持不变
*
* 如果本次是上升，即nums[i]-nums[i-1]>0,则
* dp[i][up] = dp[i-1][down]+1;
* dp[i][down] = dp[i-1][down];下升长度维持不变
*
* 注意：如果遇到两个相邻的数字相等，那么上升的路径长度和下降的路径长度不发生变化，顺移到该位置
*
* 最后，取这两条路径中较长的一条返回
* return max(dp[n-1][up],dp[i-1][down])
* */

class Solution376{
    public int wiggleMaxLength(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n][2];     //0为上升，1为下降
        dp[0][0]=1;
        dp[0][1]=1;

        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1];
            }
            else if((nums[i]-nums[i-1])>0){
                dp[i][1] = dp[i-1][0]+1;
                dp[i][0] = dp[i-1][0];
            }else{
                dp[i][0] = dp[i-1][1]+1;
                dp[i][1] = dp[i-1][1];
            }
        }

        return Math.max(dp[n-1][0],dp[n-1][1]);
    }

    public int wiggleMaxLength2(int[] nums) {//空间优化版本
        int n = nums.length;
        // int[][] dp = new int[n][2];     //0为上升，1为下降
        int up=1;
        int down=1;

        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            if((nums[i]-nums[i-1])>0){
                up = down+1;
                // down = down;
            }else{
                down = up+1;
                // up = up;
            }
        }

        return Math.max(up,down);
    }

    //官方题解，维护一个波峰和波谷，如果相邻的两个不是同一种类型的，则加1
    //https://leetcode-cn.com/problems/wiggle-subsequence/solution/bai-dong-xu-lie-by-leetcode-solution-yh2m/
    class Solution {
        public int wiggleMaxLength(int[] nums) {
            int n = nums.length;
            if (n < 2) {        //长度为1，则返回1
                return n;
            }
            int prevdiff = nums[1] - nums[0];
            int ret = prevdiff != 0 ? 2 : 1;
            for (int i = 2; i < n; i++) {
                int diff = nums[i] - nums[i - 1];
                if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)) {//prevdiff<=0，prevdiff>=0表示，前面的数相等的情况,如3,3,3,1,4
                    ret++;
                    prevdiff = diff;
                }
            }
            return ret;
        }
    }
}

public class lc376 {
    public static void main(String[] args) {
        int[] nums = {1,7,4,9,2,5};
//        int[] nums = {1,17,5,10,13,15,10,5,16,8};
        Solution376 s = new Solution376();
        System.out.println(s.wiggleMaxLength(nums));
    }
}
