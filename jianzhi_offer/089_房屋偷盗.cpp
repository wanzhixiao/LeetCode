#include<iostream>
#include<vector>
using namespace std;

/*
题目：偷盗房屋能获得的最大收益，约束是不能偷盗相邻的两个房屋 
输入：nums = [1,2,3,1]
输出：4
解释： 取 1,3
思路：动态规划，dp[i]表示到达第i个数能获得的最大收益
	dp[i] = max(dp[i-1],nums[i]+dp[i-2])
	初始化 dp[1] = max(nums[0],nums[1])
	返回 max(dp[n-1],dp[n-2])  
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) {
            return nums[0];
        }
        nums[1] = max(nums[0],nums[1]);
        for(int i=2;i<n;i++) {
            nums[i] = max(nums[i-1],nums[i]+nums[i-2]);
        }
        return max(nums[n-1],nums[n-2]);
    }
};

int main(){
	vector<int> nums = {2,1,1,2};
	Solution s;
	cout << s.rob(nums) << endl; 
	return 0;
}
