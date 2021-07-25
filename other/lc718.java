package leetcode.other;


/*
* 给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
* 填二维dp数组，当a[i]==b[j]时，dp[i][j] = dp[i-1][j-1]+1,状态转移只能由左上角转过来
* */

import java.util.ArrayList;
import java.util.Hashtable;

class Solution718 {
    public int findLength(int[] nums1, int[] nums2) {
        int m = nums1.length,n = nums2.length;

        int[][] dp = new int[m+1][n+1];     //java默认初始化为0
        int res = 0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    res = Math.max(res,dp[i][j]);
                }
            }
        }
        return res;
    }
}


public class lc718 {
    public static void main(String[] args) {
        int[] A = {1,0,0,1};
        int[] B = {1,1,2,2};

        Solution718 s = new Solution718();
        int res = s.findLength(A,B);
        System.out.println(res);


        ArrayList<Character> arr = new ArrayList<>();
        arr.clear();
        arr.add('a');

        int idx = arr.indexOf('a');
        System.out.println(idx);

        String s1 = "aaba";

        StringBuffer str = new StringBuffer();
        s1.indexOf('a');

        s1 += 'b';
        System.out.println(s1.substring(0,2));
        System.out.println(s1);

        Hashtable<Character,Integer> hash = new Hashtable<>();
        hash.put('a',10);
        hash.put('b',5);
        int ss = hash.get('a');
        System.out.println(ss);
    }
}
