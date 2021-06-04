package other;

import java.util.HashMap;
import java.util.Map;

class Solution523{

    //暴力法，通过率93/94
    public boolean checkSubarraySum1(int[] nums, int k) {
        int n = nums.length;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int sum = 0;
                for(int p=i;p<=j;p++){
                    sum += nums[p];
                }
                if(sum%k==0){
                    return true;
                }
            }
        }
        return false;
    }

    //前缀和解法，超时
    public boolean checkSubarraySum2(int[] nums, int k) {
        int n = nums.length;
        int[] presum = new int[n];
        presum[0] = nums[0];
        for(int i=1;i<n;i++){
            presum[i] = presum[i-1]+nums[i];
        }
        //前缀差
        //枚举前缀和数组
        for(int i=0;i<n-1;i++){
            if(i>0 && (presum[i]%k)==0){
                return true;
            }
            for(int j=i+1;j<n;j++){
                if((j-i>1)&&((presum[j]-presum[i])%k==0)){
                    return true;
                }
            }
        }
        return false;
    }

    //前缀和+双指针,错误
    public boolean checkSubarraySum3(int[] nums, int k) {
        int n = nums.length;
        int[] presum = new int[n];
        presum[0] = nums[0];
        for(int i=1;i<n;i++){
            presum[i] = presum[i-1]+nums[i];
        }
        int left=0,right=1;
        while(right<n){
            if(((presum[right]>=k)&&(presum[right]%k==0)) || (((presum[right]-presum[left])>=k)&&(presum[right]-presum[left])%k==0)){
                return true;
            }
            System.out.println(presum[right]+" "+(presum[right]-presum[left]));
            if(((right-left)>=1 && presum[right]==0) || ((right-left)>=2&&(presum[right]-presum[left])==0)){
                return true;
            }
            if((presum[right]-presum[left])>k){
                left++;
            }
            right++;
        }

        return false;
    }

    //前缀和+哈希表+同余定理
    /*
    * 来个通俗一点的解释，同余定理 (a-b)%m = n，称为a同余于b模m，记做a≡b(mod m)，
    * 例如，前缀和分别为37和25时，由于37%6=1，25%6  = 1在哈希表中出现过，前缀和为37的下标-前缀和为25的下标>2,
    * 并有(37-25)=12%6 = 0，应当返回true;
    * */
    public boolean checkSubarraySum4(int[] nums, int k) {
        int n = nums.length;
        int[] presum = new int[n];
        presum[0] = nums[0];
        Map<Integer,Integer> map = new HashMap<>();     //存放当前余数和下标
        map.put(presum[0]%k,0);
        for(int i=1;i<n;i++){
            presum[i] = presum[i-1]+nums[i];
            int tmp = presum[i]%k;
            if(tmp==0){
                return true;
            }else if(map.containsKey(tmp)){
                if(i-map.get(tmp)>=2){      //presum[i - 2] % k与presum[i]同余
                    return true;
                }
            }else{
                map.put(tmp,i);
            }
        }
        return false;
    }

}

/**
 * [23,0,0,0]
 * 6
 *
 * [1,0]
 * 2
 *
 * */

public class lc523 {
    public static void main(String[] args) {
        int[] nums = {1,0};
        int k = 2;
        Solution523 s = new Solution523();
        System.out.println(s.checkSubarraySum4(nums,k));
    }
}
