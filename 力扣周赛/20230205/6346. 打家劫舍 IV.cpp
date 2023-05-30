#include<iostream>
#include<queue>
#include<cmath>
using namespace std;


class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
    	int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1,0));
        
        for (int i = 1; i <= n; i++) {
        	dp[i][1] = nums[i-1];
		}
		
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				dp[i][j] = max(dp[i-2][j-1],nums[i-1]);
				cout <<"i=" << i << " j=" << j << " " << dp[i][j] << " ";
			} 
			cout << endl;
		}



		int ans = 0x3f3f3f3f; 
//		for (int i = 1; i <= n; i++) {
////			cout << dp[i][k] << " "; 
//			ans = min(ans, dp[i][k]);
//		}
		return ans;
    }
    
    vector<int> vec;
    int minCapability2(vector<int>& nums, int k) { 
    	int ans = 0x3f3f3f3f;
    	for (int i = 0; i < nums.size(); i++) {
    		ans = min(ans,dfs(nums,i));
		}
		return ans;
	}
	
    int dfs(vector<int>& nums, int j) {
    	if (j >= nums.size()) {
    		return 0;	
		}
		int ans = nums[j];
		ans = max(ans,dfs(nums,j+2));
		cout << j << " " << ans << endl;
		return ans;
	}
    
};

int main() {
	vector<int> nums = {2,3,5,9};
	int k = 2;
	
	Solution solu;
	cout << solu.minCapability2(nums,k) << endl;
	
}
