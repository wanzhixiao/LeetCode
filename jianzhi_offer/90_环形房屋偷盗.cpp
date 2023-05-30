#include<iostream>
#include<vector>
using namespace std;

/*
���η��ݷ��� 
��һ�������һ������ͬʱ͵��0��n-2�� 1��n-1
dp[i]��ʾ����i�䷿�ܻ�õ��������
dp[i] = max(dp[i-1],nums[i]+dp[i-2]) 
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1) {
            return nums[0];
        }
        else if (n==2){
            return max(nums[0],nums[1]);
        }
        return max(robRange(nums,0,n-2), robRange(nums,1,n-1));
    }
    int robRange(vector<int> &nums, int start, int end) {
        int first = nums[start], second = max(first, nums[start+1]), temp = 0;
        for (int i=start+2; i <= end; i++){
            temp = second;
            second = max(second, nums[i] + first);
            first = temp; 
        }
        return second;
    }
};

int main(){
	vector<int> nums = {2,1,1,2};
	Solution s;
	cout << s.rob(nums) << endl; 
	return 0;
}
