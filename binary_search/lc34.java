package leetcode.binary_search;

//找出有重复数字的非降序排列数组中第一个与target相等，最后一个与target相等的数组下标
//题目连接，https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/


class Solution34{
    public int[] searchRange(int[] nums, int target) {
        int left=0,right=nums.length-1;
        int[] res = new int[2];
        //找第一个与target相等的数
        while(left<=right){
            //退出循环时 right+1=left
            // left=mid,nums[left]=第一个target,nums[right]<target
            //target = 7,   5,7,7,8,8,9   退出循环时，left=1,right=0;nums[left]=第一个7
            int mid = left+(right-left)/2;
            if(nums[mid]>=target){
                right=mid-1;
            }else{
                left = mid+1;
            }
        }
        if(left<nums.length && nums[left]==target){ //left>right 判断left是否超过边右边界
            res[0] = left;
        }else{
            res[0] = -1;
        }

        left=0;right=nums.length-1;
        //找到最后一个与target相等的数
        while(left<=right) {
            //退出循环时 right+1=left
            // right=mid,nums[right]=最后一个target,nums[left]>target
            //target = 7,   5,7,7,8,8,9   退出循环时，left=3,right=2; nums[right]=第二个7
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if(right>=0 && nums[right]==target){ //right<left 判断right是否超过边左边界
            res[1] = right;
        }else{
            res[1] = -1;
        }
        return res;
    }
}

public class lc34 {
    public static void main(String[] args) {
        int[] nums = {5,7,7,8,8,10};
        int target = 8;
        Solution34 s = new Solution34();
        int[] res = s.searchRange(nums,target);
        System.out.println(res[0]+" "+res[1]);
    }
}
