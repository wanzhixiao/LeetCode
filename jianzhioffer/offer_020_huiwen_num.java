package jianzhioffer;


class Solution20 {

    //暴力dp
    public int countSubstrings(String s) {
        int cnt = 0;
        int n = s.length();
        boolean[][] dp = new boolean[n][n];

        for(int i=n-1;i>=0;i--){
            dp[i][i] = true;
            for(int j=i;j<n;j++){
                if(s.charAt(i)==s.charAt(j)){
                    if(j-i>=2){
                        dp[i][j] = dp[i+1][j-1];
                    }else{
                        dp[i][j] = true;
                    }
                }
                cnt += dp[i][j]?1:0;
            }
        }
        return cnt;
    }
}

public class offer_020_huiwen_num {
    public static void main(String[] args) {
        String s = "aaa";
        Solution20 solu = new Solution20();
        int res = solu.countSubstrings(s);
        System.out.println(res);
    }
}
