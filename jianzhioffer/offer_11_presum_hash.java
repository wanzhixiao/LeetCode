package jianzhioffer;


/*
*  剑指11: 0 和 1 个数相同的子数组
* */

import java.util.HashMap;

class Solution11 {
    public int findMaxLength(int[] nums) {
        int n = nums.length,cnt = 0;
        int presum = 0;

        HashMap<Integer,Integer> map = new HashMap<>();
        //todo 8.15 不清楚为什么 map[0]=-1
        map.put(0,-1);

        for(int i=0;i<n;i++){
            nums[i] = (nums[i]==1)?nums[i]:-1;
            presum = presum+nums[i];

            if(!map.containsKey(presum)){
                map.put(presum,i);
            }else{
                cnt = Math.max(cnt, i-map.get(presum));
            }
        }
        return cnt;
    }
}

public class offer_11_presum_hash {
    public static void main(String[] args) {
        int[] nums = {0,1,0};
        Solution11 solu = new Solution11();
        int res = solu.findMaxLength(nums);
        System.out.println(res);
    }
}
