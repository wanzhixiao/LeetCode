package leetcode.jianzhioffer;

import java.math.BigInteger;
import java.util.Arrays;

class Solution14{
    public int cuttingRope(int n) {

        if(n<=1){       //不能剪
            return n;
        }
        int maxres = 1;
        for(int j=1;j<n;j++){
            int p = cuttingRope(n-j);
            int q = cuttingRope(j);

            maxres = Math.max(maxres,p*q);
        }
        maxres = Math.max(maxres,cuttingRope(n));
        return maxres;
    }

    public int cuttingRope1(int n) {

        if(n<=1){       //不能剪
            return n;
        }
        int[] dp = new int[n+1];
        for(int i=0;i<=n;i++){
            dp[i] = i;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i] = Math.max(dp[i],dp[i-j]*dp[j]);
            }
        }
        return dp[n];
    }

    public int cuttingRope2(int n) {
        //使用java自带的大数运算
        if(n<=2){       //不能剪
            return n-1;
        }

        if(n==1000000008){
            return 1;
        }

        BigInteger[] dp = new BigInteger[n+1];

        Arrays.fill(dp, BigInteger.valueOf(1));

        int mod = 1000000007;
        for(int i=3;i<=n;i++){
            for(int j=1;j<i;j++){
                // int nocut = ((i-j)%mod)*(j%mod)%mod;          //i-j不拆

                // int cut = (dp[i-j])*(j%mod)%mod;          //i-j继续拆

                // dp[i] = Math.max(dp[i],Math.max(nocut,cut));
                // dp[i] = dp[i];

                dp[i] = dp[i].max(BigInteger.valueOf((i-j)*j)).max(dp[i-j].multiply(BigInteger.valueOf(j)));


            }
        }
        return dp[n].mod(BigInteger.valueOf(1000000007)).intValue();
    }

}

public class offer14 {
    public static void main(String[] args) {
        Solution14 solution = new Solution14();

        int res = solution.cuttingRope1(2);

        System.out.println(res);
    }
}
