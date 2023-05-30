#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
 
class Solution {
    int memo[30010];
public:
	//超时 
    bool canJump(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return dfs(nums, nums.size()-1);
    }

    bool dfs(vector<int> &nums, int j) {
        if (j <= 0) {
            if (j == 0) {
                return true;
            }
            return false;
        }
        if (memo[j] != -1) {
            return memo[j];
        }
        bool res = false;
        for (int i = j-1; i >= 0; i--) {
           if (i + nums[i] < j) {
               continue;
           }
            res |= dfs(nums, i);
        }
        memo[j] = res;
        return res;
    }
    
    
    ////dfs正确版本 
    bool canJump2(vector<int>& nums) {
        return dfs(nums, nums.size()-1);
    }
    bool dfs2(vector<int> &nums, int j) {
        if (j <= 0) {
            if (j == 0) {
                return true;
            }
            return false;
        }
        for (int i = j-1; i >= 0; i--) {
           if (nums[i] >= j - i) {
           	   //沿着满足条件的路径继续往下搜，只要找到一条路径，就返回true 
               return dfs(nums, i);
           }
        }
        return false;
    }
    
    // 动态规划 
	bool canJump3(vector<int>& nums) {
		int n = nums.size();
		vector<bool> dp(n, false);			//dp[i]表示能否到达第i个位置 
		//初始化 
		dp[0] = true;
		for (int i = 1; i < n; i++) {
//			for (int j = 0; j < i; j++) {		// 正序枚举会超时 
			for (int j = i-1; j >= 0; j--)
				if (dp[j] && j + nums[j] >= i) {
					dp[i] = true;
				}
			}
		return dp[n-1];
    }
};

/*
[2,0,2]
[2,0,0]
输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。

													4
											-1/   -2| -3\ -4\
										    1      1(x) 3   2(x)
									   -1/-2|-3\        
									   1   3   2
思路： dfs + memo 
*/

int main() {
	vector<int> nums{2,0,2};
	Solution solu;
	cout << solu.canJump3(nums) << endl;
	return 0;
} 

