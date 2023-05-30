#include<iostream>
#include<vector>
#include<unordered_map> 
#include<algorithm> 
using namespace std; 

/*

���룺nums = [-2,1,-3,4,-1,2,1,-5,4]
�����6
���ͣ����������� [4,-1,2,1] �ĺ����Ϊ 6 ��

˼·1����������	
	�����е�״̬��ʲô��
	�����
	
	��ô��ʾ��״̬��
	sum
	
	ʲôʱ�򴰿���չ��
	sum > 0 ʱ
	
	ʲôʱ�򴰿�������
	sum <= 0 ʱ, ������������ֵ 
	
˼·2����̬�滮 
	dp[i]��ʾ��i��β�������飬���ĺ�Ϊdp[i] 
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
        right++;                //���ڴˣ���ָ�����ұ߱���
        while ((sum <= 0) && (left < right)) {   //��sum<=0ʱ����ָ���������
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
