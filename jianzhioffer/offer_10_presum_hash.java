package jianzhioffer;
import java.util.HashMap;

class Solution10 {
    //map[0]=1

    //nums = [1,1,1] k=2
    //presum = [1,2,3]
    //presum-k = -1,0,1
    //map[presum-k] = null,1,1

    //nums = [-1,-1,1],k=1
    //presum = [-1,-1,1]
    //presum-k = -2,-2,0
    //map[presum-k] = null,null,1

    public int subarraySum1(int[] nums, int k){
        //前缀和+哈希表
        HashMap<Integer,Integer> map = new HashMap<>();

        //即presum -k = 0时，默认出现过一次
        map.put(0,1);

        int presum=0,cnt=0;
        for(int num:nums){
            presum += num;
            if(map.containsKey(presum-k)){
                cnt += map.get(presum-k);
            }
            //因为数组nums中可能有负数，所以同一个presum可能出现多次
            if(map.containsKey(presum)){
                map.put(presum,map.get(presum)+1);
            }else{
                map.put(presum,1);
            }

        }
        return cnt;
    }

    //滑动窗口，右指针不断往前直到右边界，
    public int subarraySum(int[] nums, int k) {
        int left=0,right=0;
        int n = nums.length;
        long sum = 0;
        int cnt = 0;
        while(right<n){
            sum += nums[right++];

            while(left<right && sum>k){
                sum -= nums[left++];
            }
            if(sum == k){
                cnt += 1;
            }
        }
        return cnt;
    }
    //↑↑↑ 原数组中有负数，[-1,-1,1]，sum>k不成立，left=0, 例子不能通过
}

public class offer_10_presum_hash {
    public static void main(String[] args) {
        int[] nums = {1,2,3};
        int k = 3;
        Solution10 solu = new Solution10();
        int res = solu.subarraySum1(nums,k);
        System.out.println(res);
    }
}
