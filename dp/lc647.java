package leetcode.dp;

import java.util.Scanner;

/*回文串数量*/

class Solution647 {
    public int countSubstrings(String s) {//暴力法
        int count = s.length();
        for(int i=0;i<s.length();i++)
        {
            for(int j=i+1;j<s.length();j++)//枚举所有回文子串
            {

                int start=i,end=j;

                while(start<=end){

                    if(s.charAt(start)==s.charAt(end))
                    {
                        start++;
                        end--;
                    }else{
                        break;
                    }
                }
                if(start>end)
                {
                    count++;
                }
            }
        }
        return count;
    }

    public int countSubstrings3(String s){
        int n = s.length();

        int cnt = 0;
        boolean[][] dp = new boolean[n][n];
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if((s.charAt(i) == s.charAt(j))&&(((j-i)<=2)||dp[i+1][j-1])){
                    dp[i][j] = true;
                    cnt++;
                }
            }
        }
        return cnt;
    }


}


public class lc647 {

    public static void main(String[] args) {

        Solution647 solution = new Solution647();

        Scanner scanner = new Scanner(System.in);
        while(scanner.hasNext()){
            String s = scanner.next();

            System.out.println(solution.countSubstrings3(s));;
        }
    }
}
