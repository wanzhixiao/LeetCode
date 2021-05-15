package leetcode.other;

class Solution1094 {
    public boolean carPooling(int[][] trips, int capacity) {
        int[] dp = new int[1001];
        int len = trips.length;
        for(int i=0;i<len;i++){
            dp[trips[i][1]] += trips[i][0];
            dp[trips[i][2]] -= trips[i][0];
        }

        for(int i=1;i<1001;i++){
            dp[i] += dp[i-1];
            if(dp[i]>capacity){
                return false;
            }
        }
        return true;
    }
}

public class chafen_1094 {
    public static void main(String[] args) {
        int[][] trips = new int[3][];
        trips[0] = new int[]{3,2,7};
        trips[1] = new int[]{3,7,9};
        trips[2] = new int[]{8,3,9};
        int capcity = 11;

        Solution1094 s = new Solution1094();
        boolean res = s.carPooling(trips,capcity);

        System.out.println(res);

    }
}
