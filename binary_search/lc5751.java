package leetcode.binary_search;


/*
[55,30,5,4,2]
[100,20,10,10,5]
2
解释：有效下标对是 (0,0), (2,2), (2,3), (2,4), (3,3), (3,4) 和 (4,4) 。
最大距离是 2 ，对应下标对 (2,4) 。


[2,2,2]
[10,10,1]
1
[30,29,19,5]
[25,25,25,25,25]
2

[5,4]
[3,2]
0


* */

class Solution5751 {
    public int maxDistance(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        int maxdist = 0;
        for(int i=0;i<m;i++){

            if(nums1[i]>nums2[0]){ //如果第一个数组的元素比第二个数组所有的元素都大，不满足i<=j && nums[i]<=nums[j]
                continue;
            }
            int left=0,right=n;
            //返回第一个大于nums1[i]的值
            while(left+1<right){
                int mid = left+(right-left)/2;
                if(nums2[mid]>=nums1[i]){
                    left = mid;
                }else{
                    right = mid;
                }
            }
            if(nums2[left]>=nums1[i] && left>=i)
                maxdist = maxdist>(left-i)?maxdist:(left-i);
        }
        return maxdist;
    }

    //双指针解法，i指向第二个数组，从左往右遍历，j从0开始遍历nums1，直到nums1[j]<=nums2[i]
    //注意j不需要停顿，一直往右边遍历
    public int maxDistance2(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        int res = 0;
        for(int i=0;i<n;i++){
            int j=0;
            while(j<m && nums1[j]>nums2[i]){    //从nums1[j]中找第一个小于nums2[i]的数
                j++;
            }
            if(j<m && j<=i){
                res = Math.max(res,i-j);
            }
        }
        return res;
    }

    //暴力解法，超时，通过率 20/30
    public int maxDistance3(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        int maxdist = 0;
        for(int i=0;i<m;i++){
            for(int j=i;j<n;j++){
                if(nums2[j]>=nums1[i]){
                    maxdist = maxdist>(j-i)?maxdist:(j-i);
                }
            }
        }
        return maxdist;
    }
}


public class lc5751 {
    public static void main(String[] args) {
        int[] nums1 = {55,30,5,4,2};
        int[] nums2 = {100,20,10,10,5};
        Solution5751 s = new Solution5751();

        int res = s.maxDistance2(nums1,nums2);

        System.out.println(res);
    }
}
