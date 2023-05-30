

/*
˼·1�� ̰������ 
����+�������ң� ����case��ͨ�� 
[9,1,2,4,10]
[1,2,4,9,10]
˼·2�� 01���� 
    // 01������ÿ����Ʒѡ���߲�ѡ
	// dp[i][j]��ʾʹ��ǰi��s�����ܷ����j,  ʹ�õ�i�����֣�dp[i-1][j-nums[i],��ʹ�õ�i�����֣�dp[i-1][j],
	// dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i]]�� ��ʾ����������һ�߼��� 
*/
class Solution {
public:
	//˼·1 
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
    
	//˼·2 
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

// ���仯����  ö��ѡ�ĸ� 
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
���Ƶ���Ŀ��
698�� ����k����ȵ��Ӽ� 


����+˫ָ������̰�ĽⷨӦ���ǽⲻ�����ģ�����+dp��Ӧ���Ƕ���ö��k, �ٵȺͷָ��Ӽ�(698�⣩,ѡ����С��K��
2��3��4��5��6����ȷ�����ǣ�2��3��5���ͣ�4��6��

[9,1,2,4,10]
[1,2,4,9,10]


*/
