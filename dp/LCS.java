package dp;


//定义子问题 dp[i][j] = dp[i-1][j-1]+1 A[i] == B[j]
//dp[i][j] = 0 A[i] != B[j]

//i==0 || j==0 dp[i][j] =

import java.util.*;


class SolutionLCS{
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    public String LCS (String str1, String str2) {
        // write code here
        String result = "";
        int n1 = str1.length();
        int n2 = str2.length();
        int[][] dp = new int[n1][n2];

        int length = 0;
        int lastindex = 0;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(i==0||j==0){
                    dp[i][j] =  (str1.charAt(i)==str2.charAt(j))?1:0;
                }else if(str1.charAt(i) == str2.charAt(j)){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = 0;
                }
                if(dp[i][j]>length){
                    length = dp[i][j];
                    lastindex = i;
                }
            }
        }
        return str1.substring(lastindex-length+1,lastindex+1);
    }
}

public class LCS {
    public static void main(String[] args) {
        SolutionLCS solu = new SolutionLCS();
        String s1 = "1AB2345CD";
        String s2 = "12345EF";

        String result = solu.LCS(s1,s2);
        System.out.println(result);
    }
}
