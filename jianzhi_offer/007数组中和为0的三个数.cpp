#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
007�����к�Ϊ 0 ��������
���룺nums = [-1,0,1,2,-1,-4]
�����[[-1,-1,2],[-1,0,1]]

˼·1��������������forѭ������
˼·2������+˫ָ�� 
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		int n = nums.size();
		sort(nums.begin(),nums.end());
		
		for (int i = 0; i < n; i++) {
			int j = i + 1, k = n-1;
			if (i > 0 && nums[i] == nums[i-1]) {
				continue;
			}
			if(nums[i] > 0) {
				break;
			}
			while (j < k) {
				while (j > i+1 && j < n && nums[j] == nums[j-1]){
					j++;
				}
				if(j>=k){
					break;
				}
				int sum = nums[i] + nums[j] + nums[k];
				if (sum > 0) {
					k--;
				}
				else if (sum < 0) {
					j++;
				} else {
					ans.push_back({i,j,k});
					j++;
				}
			}
		}
		return ans; 
    }
};

int main() {
	vector<int> nums = {-1,0,1,2,-1,-4};
	Solution s;
	s.threeSum(nums);
	return 0;
} 
