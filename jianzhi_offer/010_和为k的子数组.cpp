#include<iostream>
#include<vector>
#include<unordered_map> 
using namespace std; 

/*
和为k的子数组
nums = [-1,-1,1,-1,1], k = 0 

思路1：滑动窗口
	此题存在负数和重复数，滑动窗口不能用，原因是窗口内的数既有负数右有正数，窗口内的和 sum < k 时， 是右移动left还是right不能确定
	
	-1,-2,-1,-2,-1 
	
	同向滑动窗口：右指针右移和左指针右移的效果相反 
	
	
思路2：
	前缀和 + 哈希表
	判断当前 前缀和 presum[i] - k 在哈希表中出现了多少次； 出现一次说明 presum[i]与 presum[j]等价。
	presum[j]-presum[i] = 0 , nums[i...j]之和为0 
*/ 

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        int ans = 0;
        int left = 0, right = 0;
        int sum = 0;
        while(right < n) {
            sum += nums[right];

            while((left <= right) && (sum >= k)) {
                if(sum == k) {
                    ans++;
                }
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return ans;
    }
    
    int subarraySum2(vector<int>& nums, int k) {
    	int n = nums.size();
    	vector<int> presum(n+1,0);
		for(int i = 1; i <= n; i++) {
			presum[i] = presum[i-1] + nums[i-1];
		} 
		unordered_map<int,int> m{{0,1}};		//第1个数的前缀和 为0,个数为1 
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int tar = presum[i] - k;
			if (m.count(tar)) {
				ans = ans + m[tar];
			}
			++m[presum[i]];
		} 
		return ans;
    } 
    
};

int main() {
	vector<int> nums = {-1,-1,1,-1,1};
	int k = 0;
	Solution s;
	cout << s.subarraySum2(nums,k) << endl;
	return 0;
}
