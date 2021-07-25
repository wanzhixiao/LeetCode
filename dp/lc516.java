package dp;

//最长回文子序列
//注意：是子序列，可以不连续, 如bbbab 的最长回文子序列为bbbb
// 子串则要求连续
class Solution516 {
    public int longestPalindromeSubseq(String s) {
        int n=s.length();
        int[][] dp = new int[n][n];
        for(int i=n-1;i>=0;i--){
            dp[i][i] = 1;
            for(int j=i;j<n;j++){
                if(s.charAt(i) == s.charAt(j) && (j-i)>=1){
                    dp[i][j] = dp[i+1][j-1]+2;
                }else{
                    if((j-i)>=1){
                        dp[i][j] = Math.max(dp[i][j],Math.max(dp[i][j-1],dp[i+1][j]));
                    }
                }
            }
        }
        return dp[0][n-1];
    }
}

public class lc516 {
}
