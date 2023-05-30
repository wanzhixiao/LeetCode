#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
 
class Solution {
    int memo[30010];
public:
	//��ʱ 
    bool canJump(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return dfs(nums, nums.size()-1);
    }

    bool dfs(vector<int> &nums, int j) {
        if (j <= 0) {
            if (j == 0) {
                return true;
            }
            return false;
        }
        if (memo[j] != -1) {
            return memo[j];
        }
        bool res = false;
        for (int i = j-1; i >= 0; i--) {
           if (i + nums[i] < j) {
               continue;
           }
            res |= dfs(nums, i);
        }
        memo[j] = res;
        return res;
    }
    
    
    ////dfs��ȷ�汾 
    bool canJump2(vector<int>& nums) {
        return dfs(nums, nums.size()-1);
    }
    bool dfs2(vector<int> &nums, int j) {
        if (j <= 0) {
            if (j == 0) {
                return true;
            }
            return false;
        }
        for (int i = j-1; i >= 0; i--) {
           if (nums[i] >= j - i) {
           	   //��������������·�����������ѣ�ֻҪ�ҵ�һ��·�����ͷ���true 
               return dfs(nums, i);
           }
        }
        return false;
    }
    
    // ��̬�滮 
	bool canJump3(vector<int>& nums) {
		int n = nums.size();
		vector<bool> dp(n, false);			//dp[i]��ʾ�ܷ񵽴��i��λ�� 
		//��ʼ�� 
		dp[0] = true;
		for (int i = 1; i < n; i++) {
//			for (int j = 0; j < i; j++) {		// ����ö�ٻᳬʱ 
			for (int j = i-1; j >= 0; j--)
				if (dp[j] && j + nums[j] >= i) {
					dp[i] = true;
				}
			}
		return dp[n-1];
    }
};

/*
[2,0,2]
[2,0,0]
���룺nums = [2,3,1,1,4]
�����true
���ͣ��������� 1 �������±� 0 �����±� 1, Ȼ���ٴ��±� 1 �� 3 ���������һ���±ꡣ

													4
											-1/   -2| -3\ -4\
										    1      1(x) 3   2(x)
									   -1/-2|-3\        
									   1   3   2
˼·�� dfs + memo 
*/

int main() {
	vector<int> nums{2,0,2};
	Solution solu;
	cout << solu.canJump3(nums) << endl;
	return 0;
} 

