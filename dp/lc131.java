package leetcode.dp;

/*
* 力扣131
* 分割回文串
* 示例 1：

输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]
示例 2：

输入：s = "a"
输出：[["a"]]

思路，与647题相同，使用中心扩散思想
* 维护一个二维dp数组，dp[i][j]表示以i开头，以j结尾的字符串是不是回文字符串
i往左走，j往右走
dp[i][j] = dp[i+1][j-1]     ,如果s[i]==s[j]&&(j-i)>=2,否则
dp[i][j] = dp[i+1][j] || dp[i][j-1]
边界情况：
dp[i][i] = ture
else dp[i][j] = false, if i!= j
*
*
* */

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Solution131 {
    public List<List<String>> partition(String s) {
        int n = s.length();


//        for(int i=0;i<n;i++)
//            Arrays.fill(dp[i],false);

        List<List<String>> list = new ArrayList<List<String>>();            //二维数组



        for(int i=1;i<n;i++){//枚举每个分割点
            List<String> lhs = gethuiwen(s.substring(0,i));
            List<String> rhs = gethuiwen(s.substring(i,n));

            lhs.addAll(rhs);
            list.add(lhs);
        }


        return list;
    }

    public List<String> gethuiwen(String s){
        int n = s.length();
        boolean[][] dp = new boolean[n][n];
        List<String> tmp = new ArrayList<String>();
        for(int i=n-1;i>=0;i--){

            for(int j=i;j<n;j++){
                if(s.charAt(i) == s.charAt(j)&&(((j-i)<=2)||dp[i+1][j-1])){
                    dp[i][j] = true;
                    tmp.add(s.substring(i,j+1));
                }
            }
        }
        return tmp;
    }

}

public class lc131 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Solution131 sobj = new Solution131();
        while(sc.hasNext()){
            String str = sc.next();
            List<List<String>> list = sobj.partition(str);

            for(List<String> ll : list){
                for(String s : ll){
                    System.out.print(s + " ");
                }
                System.out.println(" end");
            }

        }
    }
}
