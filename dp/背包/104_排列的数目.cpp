#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std; 

/*
从输入的 nums 数组中挑选数字（可重复）使得这些数字的和是 target ，求有多少种组合方法
求每个组合：回溯法
求组合数个数：动态规划

输入：nums = [1,2,3], target = 4
输出：7
解释：
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
请注意，顺序不同的序列被视作不同的组合

dp[i][j]表示前i个数组合成j的组合总数
dp[0][0] = 1;
dp[i][0] 表示用前
dp[0][j] 表示用空集组合成j, dp[0][j] = 0 


关于求组合数和求排列数

https://leetcode.cn/problems/D0F0SV/solution/tong-guan-jian-2-shuang-bai-bei-bao-dp-b-f33v/

1.求组合数 

dp[j] 表示组成数字j有多少种组合方案， 组成j的方案数，dp[j] =  组成j-nums[i]的方案数dp[j-nums[i]] + nums[i] 

------j-nums[i]----nums[i]------
----------------j--------------

按行填充 ， 使用可用的物品去填充所有容量的背包，使用的物品逐渐增多 
for (int i = 0; i < nums.size(); i++) { // 外层遍历遍历物品
    for (int j = nums[i]; j <= amount; j++) { // 内层遍历背包容量
        dp[j] += dp[j - nums[i]];				//只有物品1时，dp[6] += dp[6-1] ， 按行填充时，dp[5]还未计算
												//遍历到物品5时， dp[6] += dp[6-5] , 此时dp[1]已经计算，  6 = {1,5} 
    }
}


按列填充，用所有物品去填充当前背包的容量 

2.求排列数
dp[j] 表示组成数字j有多少种排列方式
 
for (int j = 0; j <= amount; j++) { // 外层遍历背包容量
    for (int i = 0; i < nums.size(); i++) { // 内层遍历物品
        if (j - nums[i] >= 0) dp[j] += dp[j - nums[i]];
    }
}

*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
        	cout << "nums["<<i-1<<"]="<<nums[i-1]<< endl; 
            for (int j = 0; j <= target; j++) {
                if (j < nums[i-1]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]] + 1;
                }
                cout << j << " " << nums[i-1] << " "<< "dp["<<i<<"]["<<j<<"]="<< dp[i][j] <<endl; 
            }
        }
        return dp[n][target];
    }
    
    //递归解法 
    int combinationSum41(vector<int>& nums, int target) {
    	if (target == 0) {
    		return 1;
		} 
		if (target < 0) {
			return 0;
		}
		//从当前层遍历一棵多叉树 
		int res = 0;
		for (int i = 0; i < nums.size(); i++) {
			res += combinationSum41(nums,target-nums[i]);
		}
		//往上一层返回该层的结果 
		return res;
    } 
    
    //带记忆的递归解法 
    unordered_map<int,int> memo; 
    int combinationSum42(vector<int>& nums, int target) {
    	if (memo.find(target) != memo.end()) {
    		return memo[target];
		}
    	if (target == 0) {
    		memo[target] = 1;
    		return 1;
		} 
		if (target < 0) {
			memo[target] = 0;
			return 0;
		}
		//从当前层遍历一棵多叉树 
		int res = 0;
		for (int i = 0; i < nums.size(); i++) {
			res += combinationSum42(nums,target-nums[i]);
		}
		memo[target] = res;
		//往上一层返回该层的结果 
		return res;
    } 
    /*
									4
							  -1/ -2| -3\
							   3   2	1
					     -1/ -2| -3\
						  2    1   0
					  -1/ -2\ -1|
					   1    0   0	  
	*/ 
    
    int combinationSum43(vector<int>& nums, int target) {
    	int n = nums.size();
    	vector<int> dp(target+1,0);
    	dp[0] = 1;
    	//遍历需要组成的数字 
    	for (int i = 1; i <= target; i++) {
    		//遍历多叉树 
    		for (int j = 0; j < n; j++) {
    			if (i >= nums[j] && dp[i] <= INT_MAX - dp[i-nums[j]]) {		//防止大数越界 
    				dp[i] += dp[i-nums[j]]; 
				}
			}
		}
		return dp[target];
    }
    
    /*
									4
							  -1/ -2| -3\
							   3   2	1
					     -1/ -2| -3\
						  2    1   0
					  -1/ -2\ -1|
					   1    0   0	  
	*/ 
    
    
};

int main() {
	vector<int> nums = {1,2,3};
	int target = 4;
	Solution solu;
	cout << solu.combinationSum4(nums,target) << endl; 
	return 0;
}

//https://leetcode.cn/problems/combination-sum-iv/solution/fu-xue-ming-zhu-cong-ji-yi-hua-di-gui-tu-rqwy/
