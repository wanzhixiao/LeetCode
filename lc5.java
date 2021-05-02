package leetcode;

import java.util.Scanner;

/*最长回文子串
* 输入：s = "babad"
* 输出："bab"
* s = "cbbd",输出："bb"
* s = "a",输出："a"
* */
class Solution5 {
    public String longestPalindrome(String s) {
        int n = s.length();

        String result = "";
        boolean[][] dp = new boolean[n][n];

        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(i==j){
                    dp[i][j] = true;
                    continue;
                }
                if(s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = dp[i+1][j-1];
                    result = s.substring(i,j);
                }else {
                    dp[i][j] = false;
                }
            }
        }

        return result;
    }
}

public class lc5 {

    public static void main(String[] args) {

        Solution5 solution = new Solution5();

        Scanner scanner = new Scanner(System.in);
        while(scanner.hasNext()){
            String s = scanner.next();

            System.out.println(solution.longestPalindrome(s));;
        }
    }
}
