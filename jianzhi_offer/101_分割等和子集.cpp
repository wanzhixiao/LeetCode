#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int,bool> mp;
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        return dfs(nums, 0, 0 ,sum);
    }

    bool dfs(vector<int>& nums, int cur, int cursum, int sum) {
        int key = 2 * cursum;

        if (mp.find(key) != mp.end()) {
            return mp[key];
        }

        if (2 * cursum == sum) {
            mp[key] = true;
            return true;
        }

        if (cur == nums.size()) {
            mp[key] = false;
            return false;
        }
		
		//遍历一棵多叉树 
        for (int i = cur; i < nums.size(); i++) {
            if (2*(cursum + nums[i]) > sum) {
                continue;
            }
            bool ans = dfs(nums, i+1, cursum + nums[i], sum);
            if (ans) {
                return true;
            }
        }
        mp[key] = false;
        return false;
    }
    
    
    //动态规划 
    bool canPartition2(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        
        if (sum % 2) {
        	return false;
		}
        int n = nums.size();
        vector<vector<bool>> dp(n,vector<bool>(sum/2+1,false));

        for (int i = 0; i < n; i++) {
        	dp[i][0] = true;
        	
        	for (int j = 1; j <= sum/2; j++) {
        		if (i == 0) {
        			dp[i][j] = false; 	 
				}
				else if ( i > 0 && j > 0) {
					if (j >= nums[i]) {
						dp[i][j] = dp[i-1][j-nums[i]] | dp[i-1][j];
					} else {
						dp[i][j] = dp[i-1][j];
					}
				}
			}
		}
   		return dp[n-1][sum/2];
    }
};

int main() {
	vector<int> nums = {1,2,3,6};
	Solution solu;
	cout << solu.canPartition(nums) << endl;
	return 0;
}
