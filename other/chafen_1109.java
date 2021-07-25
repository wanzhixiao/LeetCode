package leetcode.other;

/*
* 差分法
* 解题思路，维持一个公交车模型
* 当前站的人数 = 上一站的人数+本站变化的人数（上车人数-下车人数）
* station[i] = station[i-1]+diffstation[i]
*
* 其中，diffstation[i] = geton_i - getoff_i
* 在本题中，通过预定的航班的终点可知，终点后的下一站人数减少为该条旅行记录的预定人数
*
* */

class Solution1109 {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int[] dp = new int[n];
        int len = bookings.length;
        for(int i=0;i<len;i++){
            dp[bookings[i][0]-1] +=  bookings[i][2];
            if(bookings[i][1]<n){                            //不包括右边界
                dp[bookings[i][1]] -= bookings[i][2];
            }
        }

        //station[i] = station[i-1]+diffstation[i]
        for(int i=1;i<n;i++){
            dp[i] += dp[i-1];
        }
        return dp;
    }
}

public class chafen_1109 {
    public static void main(String[] args) {
        int [][] bookings = new int [3][];
        bookings[0] = new int[]{1, 2, 10};
        bookings[1] = new int[]{2, 3, 20};
        bookings[2] = new int[]{2, 5, 25};

        int n = 5;
        Solution1109 s = new Solution1109();
        int[] res = s.corpFlightBookings(bookings,n);

        for(int a : res){
            System.out.print(a+" ");
        }
        System.out.println();
    }
}
