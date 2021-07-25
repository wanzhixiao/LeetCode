package leetcode.dp;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


/*
*测试用例
* 3,4,16,8 -> 4,16,8
* 1,2,3,4 ->1,2,4
* 4,8,10,240 -> 4,8,240
* */

class Solution368 {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int n = nums.length;

        Arrays.sort(nums);
        int res = 1;
        int[] dp = new int[n+1];
        Arrays.fill(dp,1);
        int maxnum = 0;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    dp[i] = Math.max(dp[i],dp[j]+1);
                }
            }
            if(res<dp[i]){
                maxnum = nums[i];
                res = dp[i];
            }
        }

        List<Integer> lst = new ArrayList<Integer>();
        if (res == 1) {
            lst.add(nums[0]);
            return lst;
        }

        for (int i = n - 1; i >= 0 && res > 0; i--) {
            if (dp[i] == res && maxnum % nums[i] == 0) {        //如果当前的最大长度==dp[i]（第i个数的最大子集）&& 上一个最大数%当前数==0
                lst.add(nums[i]);
                maxnum = nums[i];
                res--;
            }
        }
        return lst;
    }
}

//class Solution368 {//  暴力法通过率：34/48
//    public List<Integer> largestDivisibleSubset(int[] nums) {
//        List<Integer> lst = new ArrayList<>();
//        int n = nums.length;
//        Arrays.sort(nums);
//
//        for(int i=0;i<n;i++){
//            int j=0;
//            for(;j<lst.size();j++){
//                if(nums[i]%lst.get(j)!=0){
//                    break;
//                }
//            }
//            if(j==lst.size()){
//                lst.add(nums[i]);
//            }
//        }
//        return lst;
//
//    }
//}
