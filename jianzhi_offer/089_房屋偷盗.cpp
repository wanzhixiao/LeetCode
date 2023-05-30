#include<iostream>
#include<vector>
using namespace std;

/*
��Ŀ��͵�������ܻ�õ�������棬Լ���ǲ���͵�����ڵ��������� 
���룺nums = [1,2,3,1]
�����4
���ͣ� ȡ 1,3
˼·����̬�滮��dp[i]��ʾ�����i�����ܻ�õ��������
	dp[i] = max(dp[i-1],nums[i]+dp[i-2])
	��ʼ�� dp[1] = max(nums[0],nums[1])
	���� max(dp[n-1],dp[n-2])  
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) {
            return nums[0];
        }
        nums[1] = max(nums[0],nums[1]);
        for(int i=2;i<n;i++) {
            nums[i] = max(nums[i-1],nums[i]+nums[i-2]);
        }
        return max(nums[n-1],nums[n-2]);
    }
};

int main(){
	vector<int> nums = {2,1,1,2};
	Solution s;
	cout << s.rob(nums) << endl; 
	return 0;
}
