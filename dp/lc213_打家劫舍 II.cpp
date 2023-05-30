#include<iostream>
#include<vector>
using namespace std;
 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1) {
            return nums[0];
        }
        vector<int> dp1(n+1,0), dp2(n+1,0);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0],nums[1]);

        for (int i = 2; i < n-1; i++) {
            dp1[i] = max(dp1[i-1],dp1[i-2]+nums[i]);
        }

        dp2[0] = 0;
        dp2[1] = nums[1];
        for (int i = 2; i < n; i++) {
            dp2[i] = max(dp2[i-1],dp2[i-2]+nums[i]);
        }

        return max(dp1[n-2],dp2[n-1]);
    }
};

int main() {
	vector<int> nums = {1,2,3,1};
	Solution solu;
	cout << solu.rob(nums) << endl;
	return 0;
}
