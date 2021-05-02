package leetcode;

/*
* 开三个dp数组
* dp[i]表示位置i停留在第i道所需的最少变道次数
* dp[i]要么从dp[i-1]过来，要么从相邻的两道过来
*
* 解题的时候,状态定义对了，边界条件也定义正确
* 初始想的时候状态转移想法没想好
* dp[i][0] = dp[i-1][0]
* di[i][0] = min(dp[i][0],min(dp[i][1],dp[i][2])
*
* */

class Solution5872 {
    public int minSideJumps(int[] obstacles) {
        int n = obstacles.length;
        int [][] dp = new int[3][n+1];

        for(int i=1;i<=n;i++){
            dp[0][i] = dp[1][i] = dp[2][i] = 0x03f3f3f;
        }

        //初始化变道
        dp[0][0] = dp[2][0] = 1;
        dp[1][0] = 0;

        //[0,1,2,3,0]
        for(int i=1;i<=n;i++){

            //从当前道上的前一步跳过来
            if(obstacles[i-1]!=1){
                dp[0][i] = dp[0][i-1];
            }
            if(obstacles[i-1]!=2){
                dp[1][i] = dp[1][i-1];
            }
            if(obstacles[i-1] != 3){
                dp[2][i] = dp[2][i-1];
            }

            //从两边跳过来
            if(obstacles[i-1] != 1){
                dp[0][i] = Math.min(dp[0][i-1],Math.min(dp[1][i],dp[2][i])+1);
            }
            if(obstacles[i-1] != 2){
                dp[1][i] = Math.min(dp[1][i-1],Math.min(dp[0][i],dp[2][i])+1);
            }
            if(obstacles[i-1] != 3){
                dp[2][i] = Math.min(dp[2][i-1],Math.min(dp[0][i],dp[1][i])+1);
            }
        }

        return Math.min(dp[0][n],Math.min(dp[1][n],dp[2][n]));
    }
}

public class lc5782 {
    public static void main(String[] args) {
        int[] obstacles = {0,1,2,3,0};
        Solution5872 s = new Solution5872();
        System.out.println(s.minSideJumps(obstacles));
    }
}
