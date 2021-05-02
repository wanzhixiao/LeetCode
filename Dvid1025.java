package leetcode;

/**
 * https://leetcode-cn.com/problems/is-subsequence/
 * 力扣392：判断子序列
 */

class Solution1{
    public boolean isSubsequence(String s, String t) {
        int slen = s.length(),tlen = t.length();

        //f[i][j]表示从字符串位置i开始，字符j第一次出现的位置

//        Arra<vector<int> > f(tlen+1,vector<int>(26,0));
        int[][] f = new int[tlen+1][26];
        //初始化边界条件，f[i][j] = tlen表示t中不存在字符j,从位置i开始后不存在字符j
        for(int i=0;i<tlen;i++){
            f[tlen][i] = tlen;
        }

        for(int i=tlen-1;i>=0;i--){
            for(int j=0;j<26;j++){
                if(t.charAt(i)-'a' == j){
                    f[i][j] = i;
                }else{
                    f[i][j] = f[i+1][j];
                }
            }
        }
        int add = 0;
        for(int i=0;i<slen;i++){
            //t中没有s[i] 返回false

            if(f[add][s.charAt(i)-'a'] == tlen){
                return false;
            }
            //否则直接跳到t中s[i]第一次出现的位置之后一位
           add  = f[add][s.charAt(i)-'a']+1;

        }
        return true;
    }
}

public class Dvid1025 {
    public static void main(String[] args) {
        String s = "abc";
        String t = "ahbgdc";

        Solution1 solution = new Solution1();
        System.out.printf(""+solution.isSubsequence(s,t));
    }

}
