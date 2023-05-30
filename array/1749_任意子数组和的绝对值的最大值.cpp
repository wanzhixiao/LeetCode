#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

/*
子数组绝对值最大，等价于子数组最大，或者子数组最小；看前面的累加和对当前的贡献 
维护子数组最大：如果当前pos_sum和为正，则继续加。如果pos_sum + nums[i] < 0, pos_sum = 0
				如果当前neg_sum为负， 则不继续加，如果neg_sum + nums[i] > 0, neg_sum = 0
				ans = max(ans, max(abs(pos), abs(neg)))
例子： 
	nums	2	-5	1	-4	3	-2
	pos		2	0	1	0	3	1
	neg		0	-5	-4	-8	-5	-7
	ans		2	5	4	8	5	7
*/

class Solution {
public:
	//动态规划 
    int maxAbsoluteSum(vector<int>& nums) {
		int mi = 0, ma = 0;
		int n = nums.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ma += nums[i];
			if (ma < 0) {
				ma = 0;
			}
			mi += nums[i];
			if (mi > 0) {
				mi = 0;
			}
			ans = max(ans,max(ma,-mi));
		}
		return ans;
    }
    
    //动态规划 
    int maxAbsoluteSum(vector<int>& nums) {
        int maxs = 0, mins = 0;
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (maxs + nums[i] >= 0) {
                maxs += nums[i];
            } else {
                maxs = 0;
            }

            if (mins + nums[i] <= 0) {
                mins += nums[i];
            } else {
                mins = 0;
            }
            // cout << maxs << " " << mins << endl;
            ans = max(ans, max(abs(maxs), abs(mins)));
        }
        return ans;
    }
    
    //前缀和 
    int maxAbsoluteSum2(vector<int>& nums) {
        int n = nums.size();
        vector<int> presum(n+1,0);
        for (int i = 1; i <= n; i++) {
            presum[i] = presum[i-1] + nums[i-1];
        }
        sort(presum.begin(), presum.end());
        return presum[n] - presum[0];
    }
};

int main() {
	vector<int> nums = {1,-3,2,3,-4};
	Solution solu;
	cout << solu.maxAbsoluteSum(nums) << endl;
	return 0;
}
