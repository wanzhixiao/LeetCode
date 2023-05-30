#include<iostream>
#include<vector>
using namespace std;


/*
思路：
		
		step1 : 问题转化 
		
		记数组元组和为sum, 添加负号的元素和为neg, 其余添加正号的元素和为sum-neg,  得到的表达式结果为
		(sum - neg) - neg = pos - neg = sum - 2neg =  target;
		neg = (sum-target)/2;
		
		neg必须是非负整数， sum-target是非负整数
		若上式成立，问题转化成在数组nums中选若干元素，使得这些元素之和等于neg, 计算选取元素的方案数 	
		
		step2 : 动态规划问题定义 
		定义dp[i][j] 为	 使用前i个数组成数字j的种数
		
		dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]];  // j >= nums[i]
		dp[i][j] = dp[i-1][j];						 // j < nums[i]
		
		初始化：
		dp[0][0] = 1;
		
		枚举：
		是01背包还是完全背包？一个数只能使用一次 
		for(int i = 0; i < n; i++) {
			for (int j = 0; j<=target; j++) {
			
		}
		
		最终答案
		返回 dp[n][neg] 
		
		
	

	P : 数字前添加+的数字和，N数字前添加-的数字和
	S : 数组中所有的数字和 
	1: P+N =  S
	2: P-N = target
	 1式-2式得：
	 2N = S - target;   N = (S-target)/2
	 
	 因为N > 0， 所以 S-target > 0;
	 并且， N % 2 == 0,  如N %2 == 1, 则有 P+N != S;  因为 P=N , 2P=2N=S  
	 
	 从数组中选一些数，使得这些数的和等于N 
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int diff = sum-target;
        //neg 为添加负号的元素的和， neg >= 0 
        //(sum-neg)-neg = target = sum-2neg;  neg = (sum-target)/2;
        // neg >= 0 ,所以sum-target >=0;  并且 (sum-target)%2 == 0;  //一般为正，一般为负  0 = pos - neg;  pos+neg = sum; 2*neg = sum - target
        if (diff < 0 || diff % 2 != 0) {        
            return 0;
        }
        int neg = diff/2;
        vector<vector<int>> dp(n+1,vector<int>(neg+1,0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= neg; j++) {
                if (j >= nums[i-1]) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][neg];
    }
    
    int findTargetSumWays2(vector<int>& nums, int target) {
	    int n = nums.size();
	    int sum = 0;
	    for (int i = 0; i < n; i++) {
	        sum += nums[i];
	    }
	    int diff = sum-target;
	    //(sum-neg)-neg = target = sum-2neg;  neg = (sum-target)/2;
	    // neg >= 0 ,所以sum-target >=0;  并且 (sum-target)%2 == 0;  //一般为正，一般为负  0 = pos - neg;  pos+neg = sum; 2*neg = sum - target
	    if (diff < 0 || diff % 2 != 0) {        
	        return 0;
	    }
	    int neg = diff/2;
	    vector<int> dp(neg+1,0);
	    dp[0] = 1;
	    for (int i = 1; i <= n; i++) {						
	        for (int j = neg; j >= nums[i-1]; j--) {
	        	//   1 1 1 1
	        	//   0 0 1 1      dp[2] = dp[2] + dp[2-1];  dp[1]还没有被覆盖 
	            dp[j] = dp[j] + dp[j-nums[i-1]];
	        }
	    }
	    return dp[neg];
	}
};

int main() {
	Solution solu;
	vector<int> nums = {1,1,1,1,1};
	int target = 3;
	
	cout << solu.findTargetSumWays2(nums, target) << endl;
	return 0;
} 
