#include<iostream>
#include<vector>
#include<unordered_map> 
#include<algorithm> 
using namespace std; 

/*

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

思路1：滑动窗口	
	窗口中的状态是什么？
	数组和
	
	怎么表示该状态？
	sum
	
	什么时候窗口扩展？
	sum > 0 时
	
	什么时候窗口收缩？
	sum <= 0 时, 舍弃窗口左侧的值 
	
思路2：动态规划 
	dp[i]表示以i结尾的子数组，最大的和为dp[i] 
	dp[i] = dp[i-1] + nums[i] ; if dp[i-1] >=0
	dp[i] = nums[i] ;			if dp[i-1]<=0
	
	dp[i] = max(dp[i-1]+nums[i], nums[i]) 
*/
int maxSubArray1(vector<int>& nums) {
    int n = nums.size();
    if (n==1) {
        return nums[0];
    }
    int ans = *max_element(nums.begin(),nums.end());
    if(ans <= 0) {
        return ans;
    }
    int left = 0, right = 0;
    int sum = 0;
    while (right < n) {
        sum += nums[right];
        right++;                //放在此，右指针往右边遍历
        while ((sum <= 0) && (left < right)) {   //当sum<=0时，左指针进行收缩
            sum -= nums[left++];
        }
        ans = max(ans , sum);
    }
    ans = max(ans , sum);
    return ans;
}

int maxSubArray2(vector<int>& nums) {
	int n = nums.size();
	
	if (n==1) {
		return nums[0];
	}
	vector<int> dp(n,0);
	dp[0] = nums[0];
	int ans = nums[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i-1] + nums[i], nums[i]);
	} 
	
	for (int i = 0; i < n; i++) {
		ans = ans > dp[i] ? ans : dp[i];
	}
	
	return ans;
}

int main() {
	
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	cout << maxSubArray1(nums) << endl; 
	return 0;
}
