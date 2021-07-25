package dp;


//定义子问题 dp[i][j] = dp[i-1][j-1]+1 A[i] == B[j]
//dp[i][j] = 0 A[i] != B[j]

//i==0 || j==0 dp[i][j] =

class SolutionLCS1 {
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
        int[][] dp = new int[n1+1][n2+1];  //第0行，第0列不用，防止数组越界
        //记录最长公共子串的长度
        int length = 0;
        //记录最长公共子串最后一个元素在字符串str1中的位置
        int lastindex = 0;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(str1.charAt(i) == str2.charAt(j)){
                    dp[i+1][j+1] = dp[i][j]+1;
                    if(dp[i+1][j+1]>length){
                        length = dp[i+1][j+1];
                        lastindex = i;
                    }
                }else{
                    dp[i+1][j+1] = 0;
                }
            }
        }
        return str2.substring(lastindex-length+1,lastindex+1);
    }
}
public class LCS1 {
    public static void main(String[] args) {
        SolutionLCS1 solu = new SolutionLCS1();
        String s1 = "1AB2345CD";
        String s2 = "12345EF";

        String result = solu.LCS(s1,s2);
        System.out.println(result);
    }
}
