package leetcode.monotonous_stack;


import java.util.ArrayList;
import java.util.Collections;
import java.util.Stack;


//找到左右两边的较小值，再把这个区间（不包括左右的更小值）的数求和与当前数相乘
class Solution1856 {
    public int maxSumMinProduct(int[] nums) {
        long mod = 1000000000+7;
        int n = nums.length;
        ArrayList<Integer> left = new ArrayList<>(Collections.nCopies(n,-1));
        ArrayList<Integer> right = new ArrayList<>(Collections.nCopies(n,n));
//        Collections.fill(presmaller,-1);
//        Collections.fill(nextsmaller,n);

        Stack<Integer> stk = new Stack<>();
        //利用单调栈每个元素的前一个更小元素
        for(int i=0;i<n;i++){
            while(!stk.empty() && nums[stk.peek()]>=nums[i]){
                right.set(stk.peek(),i);         //栈顶的下一个更小的元素nums[i]
                stk.pop();
            }
            //此时应该是stk.empty()或 nums[stk.peek()]<nums[i]
            if(!stk.empty()){                   //如果栈顶不为空，说明栈顶的元素小于nums[i]
                left.set(i,stk.peek());
            }
            stk.push(i);
        }

        //计算前缀和
        int[] presum = new int[n+1];
        presum[0] = nums[0];
        for(int i=1;i<n;i++){
            presum[i] = presum[i-1]+nums[i];
        }
        long res = 0;
        //计算两个更小元素之间的最小乘积
        for(int i=0;i<n;i++){
            res = Math.max(res,(presum[right.get(i)-1]-(left.get(i)==-1?0:presum[left.get(i)]))*nums[i]);
        }
        return (int)(res%mod);
    }
}

public class lc1856 {
    public static void main(String[] args) {
        int[] nums = {1,2,3,2};
        Solution1856 s = new Solution1856();
        int res = s.maxSumMinProduct(nums);

        System.out.println(res);
    }
}
