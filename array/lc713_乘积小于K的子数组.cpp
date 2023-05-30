#include<iostream>
#include<vector>
using namespace std;


/*
	nums = [1,1,1]
	k = 1
	
	窗口代表什么？
		窗口内数字的乘积
	如何表示？ 
		product
	什么时候扩展窗口？ 
		product < k
	什么时候收缩窗口
		product >= k
	当窗口内的乘积满足 product < k, 并且左端点为left, 右端口为right时，的子数组个数为多少？
	nums[left...right]
	nums[right-1,right],nums[right-2,right],...,nums[right-k,right], nums[left,left+1,...,right-1,rgiht]
	从left到right一共有right-left+1个连续的子数组
	
https://leetcode.cn/problems/subarray-product-less-than-k/solution/cheng-ji-xiao-yu-k-de-zi-shu-zu-by-leetc-92wl/ 
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) {
            return 0;
        }
        long long product = 1;
        int left = 0, right = 0;
        int ans = 0;
        while (right < n) {
            product *= nums[right];
            while(product >= k && left <= right) {		//left <= right ; product/nums[left] >= k
                product /= nums[left];
                left++;
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
};

int main() {
	vector<int> nums = {10,5,2,6};
	int k = 100;
	
	Solution s; 
	cout << s.numSubarrayProductLessThanK(nums, k) << endl;
	return 0;
}

/*
 nums = [10,5,2,6], k = 100
*/
