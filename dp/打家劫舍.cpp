#include<iostream>
#include<vector>
#include<string.h> 
using namespace std; 

class Solution {
private:
    int memo[110];
public:
	//1.记忆化搜索
    int rob1(vector<int>& nums) {
        int n = nums.size();
        memset(memo,-1,sizeof(memo));
        int res = dfs(nums,n-1);
        return res;
    }
    int dfs(vector<int> &nums, int n) {
        if (n < 0 ) {
            return 0;
        }
        if (memo[n] != -1) {
            return memo[n];
        }
        int res = max(dfs(nums,n-1), dfs(nums,n-2)+nums[n]);
        memo[n] = res;
        return res;
    }
    
    //2.动态规划 
    int rob2(vector<int>& nums) {
        int n = nums.size();
        memset(memo,0,sizeof(memo));
        for(int i = 0; i < n; i++) {
            memo[i+2] = max(memo[i+1],memo[i]+nums[i]);
        }
        return memo[n+1];
    }
    
    //3.动态规划 + 空间优化 
    int rob3(vector<int>& nums) {
        int n = nums.size();
        int f0 = 0, f1 = 0;
        for(int i = 0; i < n; i++) {
            int newF = max(f1,f0+nums[i]);
            f0 = f1;
            f1 = newF;
        }
        return f1;
    }
};

int main() {
	vector<int> nums = {2,7,9,3,1};
	Solution solu;
	cout << solu.rob3(nums) << endl;
	return 0;
} 
								 

