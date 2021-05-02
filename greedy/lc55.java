package leetcode.greedy;

/*贪心算法之跳跃至尾部*/


class Solution55{
    public boolean canJump(int[] nums) {
         int len = nums.length-1;

        for(int i=0;i<nums.length;){
            int maxidx = i;
            for(int j=maxidx+1;j<=maxidx+nums[maxidx] && j<nums.length;j++){
                if((len-j-nums[j])<(len-maxidx-nums[maxidx])){
                    maxidx = j;
                }
            }

            i = maxidx + nums[maxidx];

            if(i>=len){
                break;
            }
            if(nums[i] == 0){
                return false;
            }
        }
        return true;
    }

    public boolean canJump2(int[] nums) {
        int n = nums.length;
        int k = 0;
        for(int i=0;i<n;i++){
            if(i>k){
                return false;
            }
            k =  Math.max(i+nums[i],k);
        }
        return true;
    }
}

public class lc55 {
    public static void main(String[] args) {
        int[] arr = {2,0,2};
        Solution55 s = new Solution55();
        System.out.println(s.canJump(arr));
    }
}
