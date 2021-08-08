package jianzhioffer;

import java.util.Arrays;

/*
* 区间合并
* */
class Solution74 {
    public int[][] merge(int[][] intervals) {
        int n = intervals.length;
        int[][] ans = new int[n][n];

        Arrays.sort(intervals,(r,l)->r[0]-l[1]);
        ans[0] = intervals[0];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=ans[i-1][1]){
                ans[i-1][1] = Math.max(ans[i-1][1],intervals[i][1]);
            }else{
                ans[i] = intervals[i];
            }
        }
        return ans;
    }
}

public class lc74 {
    public static void main(String[] args) {

    }
}
