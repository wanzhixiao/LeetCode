package dp;

/*
* 力扣72 编辑距离
* */
public class lc72 {
    public static int editDistance(String s,String t){
        int m = s.length(),n=t.length();
        if(m==0 || n==0){
            return m+n;
        }

        int[][] dp = new int[m+1][n+1];
        //初始化
        for(int i=0;i<=m;i++){
            dp[i][0] = i;
        }
        for(int j=0;j<=n;j++){
            dp[0][j] = j;
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                int d;
                if(s.charAt(i-1) == t.charAt(j-1)){//替换
                    d=0;
                }else{
                    d=1;
                }
                dp[i][j] = Math.min(1+Math.min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]+d);
            }
        }
        return dp[m][n];
    }
    public static void main(String[] args) {
        String s1 = "horse";
        String s2 = "ros";
        int res = editDistance(s1,s2);
        System.out.println(res);
    }
}
