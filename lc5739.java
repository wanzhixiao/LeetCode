package leetcode;

import java.util.Arrays;
import java.util.Map;

class Solution5739 {

    //我的解答
    public static int maxFrequency(int[] nums, int k) {
        int count = 1;
        int n = nums.length;
        if(n<=1){
            return n;
        }
        int rawk=k;
        Arrays.sort(nums);
        for(int i=1;i<n;i++){
            if(k>(nums[i]-nums[i-1]) && (nums[i]>nums[i-1])){
                k -= i*(nums[i]-nums[i-1]);
                count++;
            }else if(k<=0){
                break;
            }
        }
        return k!=rawk?count:1;
    }

    //滑动窗口+双指针
    public static int maxFrequency2(int[] nums, int k) {
        //代码来自https://leetcode-cn.com/problems/frequency-of-the-most-frequent-element/solution/jian-dan-yi-dong-zui-zi-ran-de-chu-li-lu-9i9a/
        Arrays.sort(nums);
        int n = nums.length;

        int j = 0;
        long sum = 0;
        int res = 1;                                 //至少有一个数组成
        for(int i=1;i<n;i++){
            sum += (nums[i]-nums[i-1])*(i-j);       //往右边加，并填满左边
            while(sum>k){                           //k不足以填满左边所有的差值sum_i=1 to i-1 (nums[i]-nums[i-1])*(i-j)
                sum -= (nums[i]-nums[j]);           //减去最左边填充的
                j++;                                //左侧指针右移
            }
            res = Math.max(res,i-j+1);
        }
        return res;
    }

    //前缀和
    public static int maxFrequency3(int[] nums, int k) {
        //代码来自https://leetcode-cn.com/problems/frequency-of-the-most-frequent-element/solution/javasan-chong-jie-fa-by-hpq30fv0iv-wuie/
        Arrays.sort(nums);
        int n = nums.length;
        long[] s = new long[n+1];
        s[0] = 0;
        for(int i=1;i<=n;i++){
            s[i] += s[i-1]+nums[i-1];
        }
        int res = 0;
        for(int l=1,r=1;r<=n;r++){
            while((r-l+1)*nums[r-1] - s[r]+s[l-1]>k)          //s[r] - s[l] = nums[l]+nums[l+1]+...+nums[r]
            {
                l++;
            }
            res = Math.max(res,r-l+1);
        }
        return res;
    }
}


public class lc5739 {
    public static void main(String[] args) {
//        int[] nums = {1,4,8,13};
//        int k = 5;
        //out:84 real:72

        int[] nums = {9930,9923,9983,9997,9934,9952,9945,9914,9985,9982,9970,9932,9985,9902,9975,9990,9922,9990,9994,9937,9996,9964,9943,9963,9911,9925,9935,9945,9933,9916,9930,9938,10000,9916,9911,9959,9957,9907,9913,9916,9993,9930,9975,9924,9988,9923,9910,9925,9977,9981,9927,9930,9927,9925,9923,9904,9928,9928,9986,9903,9985,9954,9938,9911,9952,9974,9926,9920,9972,9983,9973,9917,9995,9973,9977,9947,9936,9975,9954,9932,9964,9972,9935,9946,9966};
        int k = 3056;

        int res = Solution5739.maxFrequency3(nums,k);
        System.out.println(res);

    }
}
