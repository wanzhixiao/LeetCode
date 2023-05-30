

/*
思路1： 贪心做法 
排序+从左往右， 以下case不通过 
[9,1,2,4,10]
[1,2,4,9,10]
思路2： 01背包 
    // 01背包，每个物品选或者不选
	// dp[i][j]表示使用前i个s数字能否组成j,  使用第i个数字，dp[i-1][j-nums[i],不使用第i个数字，dp[i-1][j],
	// dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i]]， 表示两者中满足一者即可 
*/
class Solution {
public:
	//思路1 
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int total = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            total += nums[i];
        }
        if (total & 1) {
            return false;
        }
        int i = 0, j = nums.size()-1;
        int sum = 0;
        while (i < j) {
            sum += nums[i];
            if (sum*2 == total) {
                return true;
            }
            if (total > sum*2) {
                i++;
            } else {
                break;
            }
        }
        return false;
    }
    
	//思路2 
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0; 
        for (int i = 0; i < n; i++) {
            s += nums[i];
        }
        if(s % 2 == 1) {
            return false;
        }
        int target = s/2;
        vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
        dp[0][0] = true;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                if (j-nums[i]>=0) {
                    dp[i+1][j] = dp[i][j] | dp[i][j-nums[i]];
                } else {
                    dp[i+1][j] = dp[i][j];
                }
            }
        }
        return dp[n][target];
    }

// 记忆化搜索  枚举选哪个 
private:
    unordered_map<int,bool> mp;
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0; 
        for (int i = 0; i < n; i++) {
            s += nums[i];
        }
        if(s % 2 == 1) {
            return false;
        }
        int target = s/2;
        return dfs(nums, 0,0,s);
    }

    bool dfs(vector<int>& nums, int cur, int cursum, int sum) {
        int key = 2 * cursum;

        if (mp.find(key) != mp.end()) {
            return mp[key];
        }

        if (2 * cursum == sum) {
            mp[key] = true;
            return true;
        }

        if (cur == nums.size()) {
            mp[key] = false;
            return false;
        }

        for (int i = cur; i < nums.size(); i++) {
            if (2*(cursum + nums[i]) > sum) {
                continue;
            }
            bool ans = dfs(nums, i+1, cursum + nums[i], sum);
            if (ans) {
                return true;
            }
        }
        mp[key] = false;
        return false;
    }
};

/*
类似的题目：
698： 划分k个相等的子集 


排序+双指针这种贪心解法应该是解不出来的，二分+dp，应该是二分枚举k, 再等和分割子集(698题）,选出最小的K；
2，3，4，5，6，正确分组是（2，3，5）和（4，6）

[9,1,2,4,10]
[1,2,4,9,10]


*/
