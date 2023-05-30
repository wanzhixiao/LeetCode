#include<iostream>
#include<vector> 
#include <numeric>
#include<string.h>
using namespace std;


/*
P : 数字前添加+的数字和，N数字前添加-的数字和
S : 数组中所有的数字和 
1: P+N =  S
2: P-N = target
 1式-2式得：
 2N = S - target;   N = (S-target)/2
 
 因为N > 0， 所以 S-target > 0;
 并且， N % 2 == 0,  如N %2 == 1, 则有 P+N != S;  因为 P=N , 2P=2N=S  
 
 自顶向下， 第i个数加正号或者加符号
 递归终止条件	i
 	递归终止时，判断N是否==0， 如等于0， 则添加Path至结果集合， ans++; 
 
*/ 

class Solution {
private:
	int ans = 0;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
    	int n = nums.size()-1;
    	int sum = accumulate(nums.begin(), nums.end(), 0);		// func是自定义的函数，可以对nums中的每个数进行操作 
		int diff = sum + target;
		
		if (diff < 0 || diff%2) {
			return 0;
		}

		int N = diff/2;
		ans = dfs(nums, n, N);
		return ans; 
    }
    
    int dfs(vector<int> &nums, int n, int target) {
    	if (n < 0) {
    		if (target == 0) {
    			ans++; 
    			return 1;
			}
			return 0;
		}
		if (target < nums[n]) {
			return dfs(nums, n-1, target);
		}
		int res = 0;
		res += dfs(nums, n-1, target-nums[n]);
		res += dfs(nums, n-1, target+nums[n]);
		return res;
	}
};

int main() {
	Solution solu;
	vector<int> nums = {1,1,1,1,1};
	int target = 3;
	
	cout << solu.findTargetSumWays(nums, target) << endl;
	
	return 0;
}

