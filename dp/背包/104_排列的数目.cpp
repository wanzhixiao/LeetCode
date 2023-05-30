#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std; 

/*
������� nums ��������ѡ���֣����ظ���ʹ����Щ���ֵĺ��� target �����ж�������Ϸ���
��ÿ����ϣ����ݷ�
���������������̬�滮

���룺nums = [1,2,3], target = 4
�����7
���ͣ�
���п��ܵ����Ϊ��
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
��ע�⣬˳��ͬ�����б�������ͬ�����

dp[i][j]��ʾǰi������ϳ�j���������
dp[0][0] = 1;
dp[i][0] ��ʾ��ǰ
dp[0][j] ��ʾ�ÿռ���ϳ�j, dp[0][j] = 0 


���������������������

https://leetcode.cn/problems/D0F0SV/solution/tong-guan-jian-2-shuang-bai-bei-bao-dp-b-f33v/

1.������� 

dp[j] ��ʾ�������j�ж�������Ϸ����� ���j�ķ�������dp[j] =  ���j-nums[i]�ķ�����dp[j-nums[i]] + nums[i] 

------j-nums[i]----nums[i]------
----------------j--------------

������� �� ʹ�ÿ��õ���Ʒȥ������������ı�����ʹ�õ���Ʒ������ 
for (int i = 0; i < nums.size(); i++) { // ������������Ʒ
    for (int j = nums[i]; j <= amount; j++) { // �ڲ������������
        dp[j] += dp[j - nums[i]];				//ֻ����Ʒ1ʱ��dp[6] += dp[6-1] �� �������ʱ��dp[5]��δ����
												//��������Ʒ5ʱ�� dp[6] += dp[6-5] , ��ʱdp[1]�Ѿ����㣬  6 = {1,5} 
    }
}


������䣬��������Ʒȥ��䵱ǰ���������� 

2.��������
dp[j] ��ʾ�������j�ж��������з�ʽ
 
for (int j = 0; j <= amount; j++) { // ��������������
    for (int i = 0; i < nums.size(); i++) { // �ڲ������Ʒ
        if (j - nums[i] >= 0) dp[j] += dp[j - nums[i]];
    }
}

*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
        	cout << "nums["<<i-1<<"]="<<nums[i-1]<< endl; 
            for (int j = 0; j <= target; j++) {
                if (j < nums[i-1]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]] + 1;
                }
                cout << j << " " << nums[i-1] << " "<< "dp["<<i<<"]["<<j<<"]="<< dp[i][j] <<endl; 
            }
        }
        return dp[n][target];
    }
    
    //�ݹ�ⷨ 
    int combinationSum41(vector<int>& nums, int target) {
    	if (target == 0) {
    		return 1;
		} 
		if (target < 0) {
			return 0;
		}
		//�ӵ�ǰ�����һ�ö���� 
		int res = 0;
		for (int i = 0; i < nums.size(); i++) {
			res += combinationSum41(nums,target-nums[i]);
		}
		//����һ�㷵�ظò�Ľ�� 
		return res;
    } 
    
    //������ĵݹ�ⷨ 
    unordered_map<int,int> memo; 
    int combinationSum42(vector<int>& nums, int target) {
    	if (memo.find(target) != memo.end()) {
    		return memo[target];
		}
    	if (target == 0) {
    		memo[target] = 1;
    		return 1;
		} 
		if (target < 0) {
			memo[target] = 0;
			return 0;
		}
		//�ӵ�ǰ�����һ�ö���� 
		int res = 0;
		for (int i = 0; i < nums.size(); i++) {
			res += combinationSum42(nums,target-nums[i]);
		}
		memo[target] = res;
		//����һ�㷵�ظò�Ľ�� 
		return res;
    } 
    /*
									4
							  -1/ -2| -3\
							   3   2	1
					     -1/ -2| -3\
						  2    1   0
					  -1/ -2\ -1|
					   1    0   0	  
	*/ 
    
    int combinationSum43(vector<int>& nums, int target) {
    	int n = nums.size();
    	vector<int> dp(target+1,0);
    	dp[0] = 1;
    	//������Ҫ��ɵ����� 
    	for (int i = 1; i <= target; i++) {
    		//��������� 
    		for (int j = 0; j < n; j++) {
    			if (i >= nums[j] && dp[i] <= INT_MAX - dp[i-nums[j]]) {		//��ֹ����Խ�� 
    				dp[i] += dp[i-nums[j]]; 
				}
			}
		}
		return dp[target];
    }
    
    /*
									4
							  -1/ -2| -3\
							   3   2	1
					     -1/ -2| -3\
						  2    1   0
					  -1/ -2\ -1|
					   1    0   0	  
	*/ 
    
    
};

int main() {
	vector<int> nums = {1,2,3};
	int target = 4;
	Solution solu;
	cout << solu.combinationSum4(nums,target) << endl; 
	return 0;
}

//https://leetcode.cn/problems/combination-sum-iv/solution/fu-xue-ming-zhu-cong-ji-yi-hua-di-gui-tu-rqwy/
