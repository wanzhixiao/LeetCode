#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxPos = 0, end = 0;
        int ans = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            maxPos = max(maxPos, nums[i] + i);
            if (i == end) {
                end = maxPos;
                ans++;
            }
            // 剪枝，在当前可以到达的情况下，提前终止 
            if(end == n-1) {
            	return ans;
			}
        }
        return ans;
    }
    
    int jump2(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,10010);
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (dp[j] != 10010 && j + nums[j] >= i) {
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
        return dp[n-1];
    }
};

/*
2,3,1,1,4
    当前位置 == 上一次能到达的最远位置
        更新end = maxPos
        ans+=1
       
i 			0	1	2	3	4
nums[i]		2	3	1	1	4
maxPos	0	2	4	4	4	4
end		0	2	2	4	4	4
ans 	0	1	1	2	2	2
*/

int main() {
	vector<int> nums{2,3,1,1,4};
	Solution solu;
	cout << solu.jump(nums) << endl;
	return 0;
} 
