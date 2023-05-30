#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool canPartition(vector<int>& nums) {
    	int n = nums.size();
    	//dp[i][j] ��ʾǰi�����ܷ����j 
    	//dp[i][j] = dp[i-1][j-nums[i]] | dp[i-1][j] 		j >= nums[i]
    	//dp[i][j] = dp[i-1][j]
    	//dp[0][0] = 1 
    	int sum = 0;
    	for (int i = 0; i < n; i++) {
    		sum += nums[i];
		}
		if (sum %2) {
			return false;
		}
		int target = sum/2 + 1;			//��sum/2 ����sum/2+1?? , sum��ż����sum/2��������Ҫȡ��sum/2, ���Լ�1 
		vector<vector<bool>> dp(n+1,vector<bool>(target,false));
		//0��ɺ�Ϊ0 
		dp[0][0] = true;	 
		//dp[0][nums[i]] = true 
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= target; j++) {
				if (j >= nums[i-1]) {
					dp[i][j] = dp[i-1][j-nums[i-1]] | dp[i-1][j];
				} else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}
      	return dp[n][target-1];
    }
};

int main() {
	vector<int> nums = {1,2,3,5};
	Solution solu;
	cout << solu.canPartition(nums) << endl;
	return 0;
}
