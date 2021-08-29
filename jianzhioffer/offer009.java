package jianzhioffer;


import java.math.BigInteger;

class Solution009{

    //超时 72 / 94
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int n = nums.length;
        int left = 0,right = 0;
        int cnt = 0;
        while(left<n){
            int res = multiply(nums,left,right);
//            System.out.println(res);
            if(res<k){
                cnt++;
                if(right<n)
                    right++;
                if(right==n && res <k) {
                    left++;
                    right = left;
                }
            }else{
                left++;
                right = left;
            }

        }
        return cnt;
    }
    public int multiply(int[] nums,int start,int end){
        int res = 1;
        for(int i=start;i<=end;i++){
            res = ((res % Integer.MAX_VALUE)*nums[i])%Integer.MAX_VALUE;
        }
        return res;
    }

    //正解 94/94
    public int numSubarrayProductLessThanK2(int[] nums, int k) {
        int n = nums.length;
        int left = 0,right = 0;
        int cnt = 0;
        long window_product = 1;

        while(right<n){
            window_product *= nums[right++];
            while(left<right&&window_product>=k){
                window_product /= nums[left++];
            }
            cnt+= right-left;
        }
        return cnt;
    }
    //通过率66 / 94
    public int numSubarrayProductLessThanK3(int[] nums, int k) {
        int n = nums.length;
        int left = 0,right = 0;
        int cnt = 0;

        BigInteger[] pre_product = new BigInteger[n];
        pre_product[0] = BigInteger.valueOf(nums[0]);
        for(int i=1;i<n;i++){
            pre_product[i] = pre_product[i-1].multiply(BigInteger.valueOf(nums[i]));
        }

        BigInteger k1 = BigInteger.valueOf(k);

        while(left<n){
            BigInteger res =  (left==0) ? pre_product[right]:(pre_product[right].divide(pre_product[left-1]));
            if(res.compareTo(k1)<0){
                System.out.println(left+" "+right+" "+res);
                cnt++;
                if(right<n)
                    right++;
                if(right==n && res.compareTo(k1)<0) {
                    left++;
                    right = left;
                }
            }else{
                left++;
                right = left;
            }

        }
        return cnt;
    }

    public int numSubarrayProductLessThanK4(int[] nums, int k) {
        int n = nums.length;
        long[][] dp = new long[n][n];
        int cnt = 0;

        for(int i=0;i<n;i++){
            dp[i][i] = nums[i];
            for(int j=i;j<n;j++){
                if(dp[i][j]==0){
                    if(j>0){
                        dp[i][j] = ((dp[i][j-1]%Long.MAX_VALUE)*nums[j])%Long.MAX_VALUE;
                    }
                }
                if(dp[i][j]<k){
                    cnt++;
                }else{
                    break;
                }
            }
        }
        return cnt;
    }


    //通过率88 / 94
    public int numSubarrayProductLessThanK5(int[] nums, int k) {
        int n = nums.length;
        int cnt = 0;
        long window = 1;
        for(int i=0;i<n;i++){
            window = 1;
            for(int j=i;j<n;j++){  //1--n,  2--n 被重复计算，越小的区间被重复计算的次数越多
                window = ((window % Long.MAX_VALUE)*nums[j])%Long.MAX_VALUE;
                if(window<k){
                    cnt++;
                }else{
                    break;
                }
            }
        }
        return cnt;
    }

}

public class offer009 {
    public static void main(String[] args) {
        int[] arr = {10,9,10,4,3,8,3,3,6,2,10,10,9,3};
        int k =  19;
        Solution009 solu = new Solution009();
        int res = solu.numSubarrayProductLessThanK4(arr,k);
        System.out.println(res);
    }
}
