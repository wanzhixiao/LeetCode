#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
		return dfs(nums,0,0,target);	
    }
    
    int dfs(vector<int> &nums, int level, int sum, int target) {
    	if (level >= nums.size()) {
    		if (target == sum) {
    			return 1;
			}
			return 0;
		}
		int left = dfs(nums, level + 1, sum + nums[level], target);
		int right = dfs(nums, level + 1, sum - nums[level], target);
		
		return left + right;
	}
	
	int findTargetSumWays2(vector<int>& nums, int target) {
		int n = nums.size();
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += abs(nums[i]);
		}	
		if (sum < abs(target)) {
			return 0;
		}
		vector<vector<int>> dp(n+1,vector<int>(2*sum+1,0));
		dp[0][sum] = 1;
		for (int i = 1; i <= n; i++) {						//物品 ,即nums[i] 
			for (int j = -sum; j <= sum; j++) {				// 数字 , 即背包容量 
				if (j - nums[i-1] + sum >= 0) {
					dp[i][j+sum] += dp[i-1][j-nums[i-1]+sum];
				}
				if (j + nums[i-1] + sum <= 2*sum) {
					dp[i][j+sum] += dp[i-1][j+nums[i-1]+sum];
				}
			}
		}
		return dp[n][sum+target]; 
	}
};

int main() {
	vector<int> nums = {1,1,1,1,1};
	int target = 3;
	Solution s;
	cout << s.findTargetSumWays2(nums,target) << endl;
	
	return 0;
}
